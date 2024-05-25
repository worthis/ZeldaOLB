/*

    Zelda Oni Link Begins

    Copyright (C) 2006-2008  Vincent Jouillat

    Please send bugreports with examples or suggestions to www.zeldaroth.fr

*/

#ifndef __TEXTE_H__
#define __TEXTE_H__

#include <string>
#include <SDL/SDL_ttf.h>

class Jeu;

class Texte
{
public:
    Texte(Jeu *jeu);
    ~Texte();
    void draw(SDL_Surface *gpScreen);
    void setTexte(int idTxt, int vx, int vy, int vw, int vh, bool cadr, bool defil, int vit = 30);
    bool suite();
    void affiche(SDL_Surface *gpScreen, std::string s, int a, int b);
    bool isFinished();
    void changeId(int i);
    int getId();

private:
    bool hasNext();
    void drawCadre(SDL_Surface *gpScreen);
    void chercheText();
    void decoupeText();
    int tailleMot(int deb);
    void afficheLettre(SDL_Surface *gpScreen, std::string c, int vx, int vy);

    Jeu *gpJeu;
    int vitesse; // millisecondes entre 2 lettres
    int av;      // avancement du d�filement
    int x;
    int y;
    int w;
    int h;
    int id;
    int idsuiv;
    bool def;   // si le texte doit d�filer
    bool cadre; // si on doit dessiner un cadre
    std::string texte;
    std::string buffer;
    Uint32 lastAnimTime;
    SDL_Surface *imageFont;
    SDL_Surface *imageCoeur;

    std::string fontName;  // text font name
    SDL_Color textColorFG; // text main color
    SDL_Color textColorBG; // text outline color
    TTF_Font *textFontFG;  // text main font
    TTF_Font *textFontBG;  // text outline font
    int fontSize;          // text font point size
    int charWidth;
};

#endif // Texte.h
