#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> groupes[1000 * 1000];
int nombres[1000 * 1000];
int parents[1000 * 1000];

int Find(int a) {
	if(parents[a] == a)
		return a;
	return (parents[a] = Find(parents[a]));
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if(a == b) return;
	parents[a] = b;
}

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	
	int nbNombres, nbPaires;
	cin >> nbNombres >> nbPaires;
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		cin >> nombres[iNombre];
		parents[iNombre] = iNombre;
	}
	
	for(int iPaire = 0;iPaire < nbPaires;iPaire++) {
		int debut, fin;
		cin >> debut >> fin;
		Union(debut - 1, fin - 1);
	}
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		groupes[Find(iNombre)].push_back(nombres[iNombre]);
	}
	
	for(int iGroupe = 0;iGroupe < nbNombres;iGroupe++) {
		sort(groupes[iGroupe].begin(), groupes[iGroupe].end());
	}
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		cout << groupes[Find(iNombre)].back() << " ";
		groupes[Find(iNombre)].pop_back();
	}
	return 0;
}