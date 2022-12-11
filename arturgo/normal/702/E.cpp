#include <iostream>
using namespace std;

const long long INFINI = (long long)1000 * 1000 * 1000 * 1000 * 1000;

int nbNoeuds;
long long taille;

int images[40][100 * 1000];
long long sommePoids[40][100 * 1000];
long long minPoids[40][100 * 1000];

long long puis2[62];

int main() {	
	cin >> nbNoeuds >> taille;
	
	puis2[0] = 1;
	for(int i = 1;i < 62;i++) {
		puis2[i] = 2*puis2[i-1];
	}
	
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		cin >> images[0][iNoeud];
	}
	
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		cin >> sommePoids[0][iNoeud];
		minPoids[0][iNoeud] = sommePoids[0][iNoeud];
	}
	
	for(int iExp = 1;iExp < 40;iExp++) {
		for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
			images[iExp][iNoeud] = images[iExp-1][images[iExp-1][iNoeud]];
			sommePoids[iExp][iNoeud] = 
				sommePoids[iExp-1][iNoeud] + sommePoids[iExp-1][images[iExp-1][iNoeud]];
			minPoids[iExp][iNoeud] = 
				min(minPoids[iExp-1][iNoeud], minPoids[iExp-1][images[iExp-1][iNoeud]]);
		}
	}
	
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		int image = iNoeud;
		long long mini = INFINI;
		long long somme = 0;
		
		long long reste = taille;
		
		for(int iExp = 39;iExp >= 0;iExp--) {
			if(puis2[iExp] <= reste) {
				mini = min(mini, minPoids[iExp][image]);
				somme += sommePoids[iExp][image];
				image = images[iExp][image];
				reste -= puis2[iExp];
			}
		}
		
		cout << somme << " " << mini << endl;
	}
	
	return 0;
}