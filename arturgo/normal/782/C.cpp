#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int nbCouleurs;
vector<int> voisins[300 * 1000];
int couleurs[300 * 1000];

void colorie(int noeud, int parent) {
	int curCouleur = 0;
	
	int cCur = couleurs[noeud];
	int cPar = couleurs[parent];
	
	for(int voisin : voisins[noeud]) {
		if(voisin != parent) {
			while(curCouleur == cCur || curCouleur == cPar)
				curCouleur++;
			couleurs[voisin] = curCouleur;
			curCouleur++;
			colorie(voisin, noeud);
		}
	}
}

int main() {
	int nbNoeuds;
	cin >> nbNoeuds;
	
	for(int iArc = 0;iArc < nbNoeuds - 1;iArc++) {
		int debut, fin;
		cin >> debut >> fin;
		voisins[debut - 1].push_back(fin - 1);
		voisins[fin - 1].push_back(debut - 1);
	}
	
	int melNoeud = 0;
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		if(voisins[iNoeud].size() > voisins[melNoeud].size()) {
			melNoeud = iNoeud;
		}
	}
	
	nbCouleurs = voisins[melNoeud].size() + 1;
	
	couleurs[ melNoeud ] = nbCouleurs - 1;
	for(int iVoisin = 0;iVoisin < (int)voisins[melNoeud].size();iVoisin++) {
		couleurs[ voisins[melNoeud][iVoisin] ] = iVoisin;
		colorie(voisins[melNoeud][iVoisin], melNoeud); 
	}
	
	cout << nbCouleurs << endl;
	
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		cout << couleurs[iNoeud] + 1 << " ";
	}
	cout << endl;
	return 0;
}