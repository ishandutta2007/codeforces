#include <iostream>
#include <vector>
using namespace std;

const int INFINI = 1000 * 1000 * 1000;

struct Ecran {
	int taille, score;
};

int minScore[4][3000];

int main() {
	int nbEcrans;
	cin >> nbEcrans;

	vector<Ecran> ecrans(nbEcrans);
	for(int iEcran = 0;iEcran < nbEcrans;iEcran++) {
		cin >> ecrans[iEcran].taille;
	}

	for(int iEcran = 0;iEcran < nbEcrans;iEcran++) {
		cin >> ecrans[iEcran].score;
		minScore[1][iEcran] = ecrans[iEcran].score;
	}

	for(int nbPris = 1;nbPris < 3;nbPris++) {
		for(int nouvPris = 0;nouvPris < nbEcrans;nouvPris++) {
			int mini = INFINI;
			for(int derPris = 0;derPris < nouvPris;derPris++) {
				if(ecrans[derPris].taille < ecrans[nouvPris].taille) {
					mini = min(mini, minScore[nbPris][derPris] + ecrans[nouvPris].score);
				}
			}
			minScore[nbPris + 1][nouvPris] = mini;
		}
	}

	int mini = INFINI;
	for(int iEcran = 0;iEcran < nbEcrans;iEcran++) {
		mini = min(mini, minScore[3][iEcran]);
	}

	if(mini == INFINI)
		cout << -1 << endl;
	else
		cout << mini << endl;
	return 0;
}