#include <iostream>
using namespace std;

int pgcd(int a, int b) {
	if(a == 0)
		return b;
	return pgcd(b % a, a);
}

int ppcm(int a, int b) {
	return a * b / pgcd(a, b);
}

int suivants[100 * 1000];
bool estPasse[100 * 1000];

int main() {
	int nbPersonnes;
	cin >> nbPersonnes;
	
	for(int iPersonne = 1;iPersonne <= nbPersonnes;iPersonne++) {
		cin >> suivants[iPersonne];
	}
	
	int total = 1;
	for(int iPersonne = 1;iPersonne <= nbPersonnes;iPersonne++) {
		if(!estPasse[iPersonne]) {
			int tailleCycle = 0;
			int curE = iPersonne;
			while(!estPasse[curE]) {
				estPasse[curE] = true;
				curE = suivants[curE];
				tailleCycle++;
			}
			
			if(curE != iPersonne) {
				cout << -1 << endl;
				return 0;
			}
			
			if(tailleCycle % 2 == 1) 
				total = ppcm(total, tailleCycle);
			else
				total = ppcm(total, tailleCycle / 2);
		}
	}
	
	cout << total << endl;
	return 0;
}