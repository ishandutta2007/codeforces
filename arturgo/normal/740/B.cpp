#include <iostream>
using namespace std;

const int MAX_NB_FLEURS = 100;

int valeurs[MAX_NB_FLEURS];

int main() {
	int nbFleurs, nbPacks;
	cin >> nbFleurs >> nbPacks;
	
	for(int iFleur = 0;iFleur < nbFleurs;iFleur++) {
		cin >> valeurs[iFleur];
	}
	
	int total = 0;
	for(int iPack = 0;iPack < nbPacks;iPack++) {
		int somme = 0;
		
		int debut, fin;
		cin >> debut >> fin;
		
		for(int iFleur = debut - 1;iFleur < fin;iFleur++) {
			somme += valeurs[iFleur];
		}
		
		if(somme > 0)
			total += somme;
	}
	
	cout << total;
}