#include <iostream>
#include <vector>
using namespace std;

const int LIGS = 0;
const int COLS = 1000;

vector<int> voisins[2000];
bool estUtile[2000];

void colorie(int sommet) {
	if(!estUtile[sommet]) return;
	estUtile[sommet] = false;

	for(int voisin : voisins[sommet]) {
		colorie(voisin);
	}
}

int main() {
	int nbSlots;
	cin >> nbSlots;

	for(int iSlot = 0;iSlot < nbSlots;iSlot++) {
		int lig, col;
		cin >> lig >> col;
		lig--; col--;
		voisins[LIGS + lig].push_back(COLS + col);
		voisins[COLS + col].push_back(LIGS + lig);
		estUtile[LIGS + lig] = true;
		estUtile[COLS + col] = true;
	}

	int nbComposantes = 0;

	for(int iSommet = 0;iSommet < 2000;iSommet++) {
		if(estUtile[iSommet]) {
			colorie(iSommet);
			nbComposantes++;
		}
	}
	cout << nbComposantes - 1 << endl;
	return 0;
}