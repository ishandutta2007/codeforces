#include <iostream>
#include <algorithm>
using namespace std;

int nbSujets, nbTaches, tempsTotal;
int temps[100];

int main() {
	cin >> nbSujets >> nbTaches >> tempsTotal;
	
	int somme = 0;
	for(int iTache = 0;iTache < nbTaches;iTache++) {
		cin >> temps[iTache];
		somme += temps[iTache];
	}
	
	sort(temps, temps + nbTaches);
	
	int maxPoints = 0;
	for(int iComplet = 0;iComplet <= nbSujets;iComplet++) {
		int reste = tempsTotal;
		int nbPoints = 0;
		
		reste -= iComplet * somme;
		nbPoints += iComplet * (nbTaches + 1);
		
		if(reste < 0)
			break;
		
		for(int iTache = 0;iTache < nbTaches;iTache++) {
			for(int iSujet = 0;iSujet < nbSujets - iComplet;iSujet++) {
				if(reste >= temps[iTache]) {
					reste -= temps[iTache];
					nbPoints++;
				}
			}
		}
		
		maxPoints = max(maxPoints, nbPoints);
	}
	
	cout << maxPoints << endl;
	return 0;
}