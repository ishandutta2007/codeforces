#include <iostream>
using namespace std;

bool table[200 * 1000];

int main() {
	int nbSocks;
	
	cin >> nbSocks;
	
	int nbSurTable = 0;
	int maxi = 0;
	
	for(int iSock = 0;iSock < nbSocks * 2;iSock++) {
		int valeur;
		cin >> valeur;
		
		if(table[valeur]) {
			nbSurTable--;
		}
		else {
			nbSurTable++;
		}
		
		maxi = max(maxi, nbSurTable);
		
		table[valeur] = !table[valeur];
	}
	
	cout << maxi << endl;
	return 0;
}