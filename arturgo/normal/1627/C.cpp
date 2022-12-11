#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> voisins[200 * 1000];
int premiers[200 * 1000];
bool estValide;

void colorie(int sommet, int couleur = 2, int parent = -1) {
	int nbVoisins = voisins[sommet].size();
	
	if(nbVoisins > 2)
		estValide = false;
	
	for(pair<int, int> paire : voisins[sommet]) {
		if(paire.first == parent) continue;
		premiers[paire.second] = couleur;
		colorie(paire.first, 5 - couleur, sommet);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int nbTests;
	cin >> nbTests;
	
	for(int iTest = 0;iTest < nbTests;iTest++) {
		int nbVertices;
		cin >> nbVertices;
		
		estValide = true;
		for(int iVertice = 0;iVertice < nbVertices - 1;iVertice++) {
			int deb, fin;
			cin >> deb >> fin;
			deb--;
			fin--;
			
			voisins[deb].push_back({fin, iVertice});
			voisins[fin].push_back({deb, iVertice});
		}
		
		for(int iVertice = 0;iVertice < nbVertices - 1;iVertice++) {
			if(voisins[iVertice].size() == 1) {
				colorie(iVertice);
				break;
			}
		}
		
		if(estValide) {
			for(int iVertice = 0;iVertice < nbVertices - 1;iVertice++) {
				cout << premiers[iVertice] << " ";
			}
			cout << endl;
		}
		else {
			cout << -1 << endl;
		}
		
		for(int iVertice = 0;iVertice < nbVertices;iVertice++) {
			voisins[iVertice].clear();
		}
	}
	return 0;
}