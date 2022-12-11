#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nbMots, taille, id;
    cin >> nbMots >> taille >> id;
    id--;

    string lettres;
    cin >> lettres;

    sort(lettres.begin(), lettres.end());
    int iLettre = 0, curMot = 0;

    vector<string> mots(nbMots, "");
    for(int i = 0;i < taille;i++) {
        for(int j = curMot;j <= id;j++) {
            mots[j].push_back(lettres[iLettre]);
            iLettre++;
        }

        for(int j = curMot;j <= id;j++) {
            if(mots[j][i] == mots[id][i]) {
                curMot = j;
                break;
            }
        }
    }

    for(int iMot = 0;iMot < nbMots;iMot++) {
        while((int)mots[iMot].size() < taille) {
            mots[iMot].push_back(lettres[iLettre]);
            iLettre++;
        }
    }

    sort(mots.begin(), mots.end());

    for(string mot : mots) {
        cout << mot << endl;
    }
    return 0;
}