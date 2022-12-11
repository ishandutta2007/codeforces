#include <iostream>
using namespace std;

char grille[60][60];
bool interdits[121][121];

int main()
{
    int taille;
    cin >> taille;

    for(int iLigne = 0;iLigne < taille;iLigne++)
        for(int iColonne = 0;iColonne < taille;iColonne++)
            cin >> grille[iLigne][iColonne];

    for(int iLigne = 0;iLigne < taille;iLigne++)
        for(int iColonne = 0;iColonne < taille;iColonne++)
            if(grille[iLigne][iColonne] == 'o')
            {
                for(int iLigneD = 0;iLigneD < taille;iLigneD++)
                    for(int iColonneD = 0;iColonneD < taille;iColonneD++)
                        if(grille[iLigneD][iColonneD] == '.')
                            interdits[taille + iLigneD - iLigne - 1][taille + iColonneD - iColonne - 1] = true;
            }

    for(int iLigne = 0;iLigne < taille;iLigne++)
        for(int iColonne = 0;iColonne < taille;iColonne++)
            if(grille[iLigne][iColonne] == 'o')
            {
                for(int iLigneD = 0;iLigneD < taille;iLigneD++)
                    for(int iColonneD = 0;iColonneD < taille;iColonneD++)
                        if(!interdits[taille + iLigneD - iLigne - 1][taille + iColonneD - iColonne - 1] && grille[iLigneD][iColonneD] != 'o')
                            grille[iLigneD][iColonneD] = '.';
            }

    bool reponse = true;
    for(int iLigne = 0;iLigne < taille;iLigne++)
        for(int iColonne = 0;iColonne < taille;iColonne++)
            if(grille[iLigne][iColonne] == 'x')
                reponse = false;

    if(reponse)
    {
        cout << "YES" << endl;
        for(int iLigne = 0;iLigne < 2 * taille - 1;iLigne++)
        {
            for(int iColonne = 0;iColonne < 2 * taille - 1;iColonne++)
            {
                if(iLigne == taille - 1 && iColonne == taille - 1)
                    cout << 'o';
                else if(interdits[iLigne][iColonne])
                    cout << '.';
                else
                    cout << 'x';
            }
            cout << endl;
        }
    }
    else
        cout << "NO" << endl;
}