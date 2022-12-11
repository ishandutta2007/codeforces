#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int grille[1000][1000];

int calcule_xor(int x, int y, int taille, int i = 0) {
	if(taille == 1) {
		if(i % 4 <= 1) {
			return grille[x][y];
		}
		else return 0;
	}
	
	int resultat = calcule_xor(x + 1, y + 1, taille - 2, i + 1);
	
	if(i % 4 <= 1) {
		for(int iLig = x;iLig < x + taille;iLig++) {
			if((iLig - x) % 2 == 0) {
				resultat ^= grille[iLig][y];
				resultat ^= grille[iLig][y + taille - 1];
			}
		}
		for(int iCol = y + 1;iCol < y + taille - 1;iCol++) {
			if((iCol - y) % 2 == 0) {
				resultat ^= grille[x][iCol];
				resultat ^= grille[x + taille - 1][iCol];
			}
		}
	}
	
	return resultat;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int nbTests;
	cin >> nbTests;
	
	for(int iTest = 0;iTest < nbTests;iTest++) {
		int taille;
		cin >> taille;
		
		for(int i = 0;i < taille;i++) {
			for(int j = 0;j < taille;j++) {
				cin >> grille[i][j];
			}
		}
		
		cout << (calcule_xor(0, 0, taille - 1) ^ calcule_xor(0, 1, taille - 1)) << endl;
	}
	
	return 0;
}