#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int INFINI = 1000 * 1000 * 1000;

int nbCandidats;
vector<int> candidats[3];

void lireEntree()
{
    cin >> nbCandidats;
    int matiere = 0;
    for(int iCandidat = 1;iCandidat <= nbCandidats;iCandidat++)
    {
        cin >> matiere;
        candidats[matiere - 1].push_back(iCandidat);
    }
}

int main()
{
    lireEntree();

    int nbEquipes = INFINI;
    for(int iMatiere = 0;iMatiere < 3;iMatiere++)
        nbEquipes = min(nbEquipes, (int)candidats[iMatiere].size());

    cout << nbEquipes << endl;
    for(int iEquipe = 0;iEquipe < nbEquipes;iEquipe++)
    {
        for(int iMatiere = 0;iMatiere < 3;iMatiere++)
            cout << candidats[iMatiere][iEquipe] << " ";
        cout << endl;
    }
}