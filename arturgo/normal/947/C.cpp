#include <iostream>
#include <bitset>
#include <set>
#include <vector>
using namespace std;

struct noeud {
	int n0s, n1s;
	int nbFils;
	noeud(int _n0s = -1, int _n1s = -1) {
		n0s = _n0s;
		n1s = _n1s;
		nbFils = 0;
	}
};

vector<noeud> noeuds;

void ajoute(int n, int delt = 0, int d = (1 << 29), int p = 0) {
	noeuds[p].nbFils += delt;
	if(d == 0)
		return;
	
	if(n >= d) {
		if(noeuds[p].n1s == -1) {
			noeuds[p].n1s = noeuds.size();
			noeuds.push_back(noeud());
		}
		ajoute(n - d, delt, d / 2, noeuds[p].n1s);
	}
	else {
		if(noeuds[p].n0s == -1) {
			noeuds[p].n0s = noeuds.size();
			noeuds.push_back(noeud());
		}
		ajoute(n, delt, d / 2, noeuds[p].n0s);
	}
}

int getMel(int n, int d = (1 << 29), int p = 0) {
	if(d == 0)
		return 0;
	
	if(n >= d) {
		if(noeuds[p].n1s != -1 && noeuds[noeuds[p].n1s].nbFils > 0) {
			return getMel(n - d, d / 2, noeuds[p].n1s) + d;
		}
		else {
			return getMel(n - d, d / 2, noeuds[p].n0s);
		}
	}
	else {
		if(noeuds[p].n0s != -1 && noeuds[noeuds[p].n0s].nbFils > 0) {
			return getMel(n, d / 2, noeuds[p].n0s);
		}
		else {
			return getMel(n, d / 2, noeuds[p].n1s) + d;
		}
	}
}

int message[300 * 1000], cle[300 * 1000];

int main() {
	
	int nbNombres;
	scanf("%d", &nbNombres);
	
	noeuds.push_back(noeud());
	for(int i = 0;i < nbNombres;i++) {
		scanf("%d", &message[i]);
	}
	
	for(int i = 0;i < nbNombres;i++) {
		scanf("%d", &cle[i]);
		ajoute(cle[i], 1);
	}
	
	for(int i = 0;i < nbNombres;i++) {
		int mel = getMel(message[i]);
		ajoute(mel, -1);
		printf("%d ", (mel ^ message[i]));
	}
	printf("\n");
	return 0;
}