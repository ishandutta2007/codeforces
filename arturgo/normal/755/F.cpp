#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cstdio>
using namespace std;

int suivant[1000 * 1000 + 42];
bool estPasse[1000 * 1000 + 42];
bitset<1000 * 1000 + 42> possibles;

vector<int> tailles;
int counts[1000 * 1000 + 1];

bool can(int val) {
	possibles[0] = true;
	for (int iTaille = 1;iTaille <= 1000 * 1000;iTaille++) {
		int nombre = 1;
		while (counts[iTaille] != 0) {
		  nombre = min(nombre, counts[iTaille]);
		  possibles |= (possibles << (nombre * iTaille));
		  counts[iTaille] -= nombre;
		  nombre *= 2;
		}
	}
  
	return possibles[val];
}

int main() {
	int nbBalles, nbOublis;
	scanf("%d%d", &nbBalles, &nbOublis);
	
	for(int iBalle = 0;iBalle < nbBalles;iBalle++) {
		scanf("%d", &suivant[iBalle]);
		suivant[iBalle]--;
	}
	
	for(int iBalle = 0;iBalle < nbBalles;iBalle++) {
		if(!estPasse[iBalle]) {
			int taille = 1;
			estPasse[iBalle] = true;
			int c = suivant[iBalle];
			
			while(c != iBalle) {
				taille++;
				estPasse[c] = true;
				c = suivant[c];
			}
			
			tailles.push_back(taille);
			counts[taille]++;
		}
	}

	
	int mini = 0;
	if(can(nbOublis)) {
		mini = nbOublis;
	}
	else {
		mini = nbOublis + 1;
	}
	
	int maxi = 0;
	for(int taille : tailles) {
		int nbFois = min(nbOublis, taille / 2);
		maxi += 2 * nbFois;
		nbOublis -= nbFois;
	}
	maxi += nbOublis;
	
	printf("%d %d\n", mini, min(nbBalles, maxi));
    return 0;
}