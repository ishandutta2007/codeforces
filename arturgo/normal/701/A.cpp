#include <iostream>
#include <algorithm>
using namespace std;

int valeurs[1000], ids[1000];

int main() {
	int nbCartes;
	cin >> nbCartes;
	
	for(int iCarte = 0;iCarte < nbCartes;iCarte++) {
		cin >> valeurs[iCarte];
		ids[iCarte] = iCarte;
	}
	
	sort(ids, ids + nbCartes, [](int a, int b){ return valeurs[a] < valeurs[b]; });
	
	for(int iJoueur = 0;iJoueur < nbCartes / 2;iJoueur++) {
		cout << ids[iJoueur] + 1 << " " << ids[nbCartes - iJoueur - 1] + 1 << endl;
	}
	
	return 0;
}