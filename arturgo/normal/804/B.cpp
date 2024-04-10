#include <iostream>
using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

int main() {
	string chaine;
	cin >> chaine;
	
	int puis2[1000 * 1000 + 1];
	puis2[0] = 1;
	for(int iP = 1;iP <= 1000 * 1000;iP++) {
		puis2[iP] = puis2[iP - 1] * 2;
		puis2[iP] %= MOD;
	}
	
	int nbBs = 0;
	int nbAs = 0;
	for(char car : chaine) {
		if(car == 'a') {
			nbAs++;
		}
		else {
			if(nbAs != 0) {
				nbBs += puis2[nbAs] - 1;
				nbBs %= MOD;
			}
		}
	}
	
	cout << nbBs << endl;
	return 0;
}