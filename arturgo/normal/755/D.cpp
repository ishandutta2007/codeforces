#include <iostream>
#include <vector>
using namespace std;

int arbre[(1 << 21)];

void modifie(int pos, int val) {
	pos += (1 << 20);
	
	while(pos != 0) {
		arbre[pos] += val;
		pos /= 2;
	}
}

int getSum(int debut, int fin) {
	int somme = 0;
	
	debut += (1 << 20);
	fin += (1 << 20);
	
	while (debut < fin) {
		if(debut % 2 == 1) {
			somme += arbre[debut];
			debut++;
		}
		if(fin % 2 == 1) {
			fin--;
			somme += arbre[fin];
		}
		debut /= 2;
		fin /= 2;
	}
	
	return somme;
}

int main() {
	int nbVert, saut;
	
	cin >> nbVert >> saut;
	
	int cur = 0;
	saut = min(saut, nbVert - saut);
	
	long long nbZones = 1;
	for(int iFois = 0;iFois < nbVert;iFois++) {
		int pro = (cur + saut) % nbVert;
		
		if(cur + saut < nbVert) {
			nbZones += 1 + getSum(cur + 1, cur + saut);
		}
		else {
			nbZones += 1 + getSum(cur + 1, nbVert) + getSum(0, cur + saut - nbVert);
		}
		
		modifie(cur, 1);
		modifie(pro, 1);
		
		cur = pro;
		
		cout << nbZones << " ";
	}
	
	cout << endl;
    return 0;
}