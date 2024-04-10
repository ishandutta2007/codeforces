#include <iostream>
#include <set>
using namespace std;

int nbObjets, nbAs, nbBs;

int arbre[2][(1 << 18)];

void modifie(int id, int pos, int val) {
	pos += (1 << 17);
	
	while(pos != 0) {
		arbre[id][pos] = max(arbre[id][pos], val);
		pos /= 2;
	}
}

int getMax(int id, int deb, int fin) {
	fin += (1 << 17);
	deb += (1 << 17);
	
	int maxi = -1000 * 1000 * 1000;
	while(deb < fin) {
		if(deb % 2 == 1) {
			maxi = max(maxi, arbre[id][deb]);
			deb++;
		}
		if(fin % 2 == 1) {
			fin--;
			maxi = max(maxi, arbre[id][fin]);
		}
		deb /= 2;
		fin /= 2;
	}
	
	return maxi;
}

int main() {
	cin >> nbObjets >> nbAs >> nbBs;
	
	for(int iNoeud = 0;iNoeud < (1 << 18);iNoeud++) {
		arbre[0][iNoeud] = arbre[1][iNoeud] = -1000 * 1000 * 1000;
	}
	
	int maxVal = 0;
	
	for(int iObjet = 0;iObjet < nbObjets;iObjet++) {
		int val, prix;
		char type;
		
		cin >> val >> prix >> type;
		
		int resteAs = nbAs;
		int resteBs = nbBs;
		
		if(type == 'C')
			resteAs -= prix;
		else
			resteBs -= prix;
		
		if(resteAs < 0 || resteBs < 0) {
			continue;
		}
		
		int mel = max(getMax(0, 0, resteAs + 1), getMax(1, 0, resteBs + 1));
		maxVal = max(maxVal, mel + val);
		
		if(type == 'C')
			modifie(0, prix, val);
		else {
			modifie(1, prix, val);
		}
	}
	
	cout << maxVal << endl;
	return 0;
}