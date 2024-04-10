#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const long long MAXI = 1000 * 1000 * 1000 + 7;

long long resultats[40][100];
long long nbBits, nbBlocs, k, modulo;

void multiplie(long long a, long long b, long long c, long long expAB) { // c = a * b
	fill(resultats[c], resultats[c] + 100, 0);
	for(long long iA = 0;iA < modulo;iA++) {
		for(long long iB = 0;iB < modulo;iB++) {
			resultats[c][(iA * expAB + iB) % modulo] = (resultats[c][(iA * expAB + iB) % modulo] + resultats[a][iA] * resultats[b][iB]) % MAXI;
		}
	}
}

int main() {
	cin >> nbBits >> nbBlocs >> k >> modulo;
	
	for(long long iBit = 0;iBit < nbBits;iBit++) {
		long long bit;
		cin >> bit;
		resultats[0][bit % modulo]++;
	}
	
	long long puis = 10;
	for(long long iPuis = 1;iPuis <= 30;iPuis++) {
		multiplie(iPuis - 1, iPuis - 1, iPuis, puis % modulo);
		puis = (puis * puis) % modulo;
	}
	
	fill(resultats[35], resultats[35] + 100, 0);
	resultats[35][0] = 1;
	
	long long cur = nbBlocs;
	long long iBit = 0;
	long long dec = 1;
	puis = 10;
	while(cur != 0) {
		if(cur % 2 == 1) {
			multiplie(iBit, 35, 36, dec);
			dec = (dec * puis) % modulo;
			for(long long iA = 0;iA < modulo;iA++) {
				resultats[35][iA] = resultats[36][iA];
			}
		}
		puis = (puis * puis) % modulo;
		cur /= 2;
		iBit++;
	}
	
	cout << resultats[35][k] << endl;
	return 0;
}