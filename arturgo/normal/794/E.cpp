#include <iostream>
using namespace std;

int nbFruits;
int valeurs[1000 * 1000];
int possibles[1000 * 1000];

int main() {
	cin >> nbFruits;
	
	int maxi = 0;
	
	for(int iFruit = 0;iFruit < nbFruits;iFruit++) {
		cin >> valeurs[2 * iFruit];
		maxi = max(maxi, valeurs[2 * iFruit]);
	}
	
	for(int iFruit = 1;iFruit <= 2 * nbFruits - 3;iFruit += 2) {
		possibles[iFruit] = max(valeurs[iFruit - 1], valeurs[iFruit + 1]);
	}
	
	for(int iFruit = 2;iFruit <= 2 * nbFruits - 4;iFruit += 2) {
		possibles[iFruit] = min(valeurs[iFruit], max(valeurs[iFruit - 2], valeurs[iFruit + 2]));
	}
	
	int curs[2] = {0, 0};
	
	int pos = nbFruits - 1;
	
	for(int iFois = 0;iFois < nbFruits - 1;iFois++) {
		curs[iFois % 2] = max(curs[iFois % 2], possibles[pos - iFois]);
		curs[iFois % 2] = max(curs[iFois % 2], possibles[pos + iFois]);
		
		cout << curs[iFois % 2] << " ";
	}
	
	cout << maxi << endl;
}