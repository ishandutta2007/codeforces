#include <iostream>
#include <vector>
using namespace std;

int nbPairs = 0;
vector<int> voisins[100 * 1000];

int nbSous(int noeud, int parent = -1) {
	int somme = 1;
	for(int voisin : voisins[noeud]) {
		if(voisin != parent) {
			int curSous = nbSous(voisin, noeud);
			if(curSous % 2 == 0) {
				nbPairs++;
			}
			somme += curSous;
		}
	}
	return somme;
}

int main() {
	int nbNoeuds;
	cin >> nbNoeuds;
	
	for(int iArc = 0;iArc < nbNoeuds - 1;iArc++) {
		int deb, fin;
		cin >> deb >> fin;
		voisins[deb - 1].push_back(fin - 1);
		voisins[fin - 1].push_back(deb - 1);
	}
	
	if(nbNoeuds % 2 == 1) {
		cout << -1 << endl;
		return 0;
	}
	
	nbSous(0);
	
	cout << nbPairs << endl;
	return 0;
}