#include <iostream>
#include <cstdio>
using namespace std;

int nombres[1000000];
int reprs[(1 << 22)];

const int MASK = (1 << 22) - 1;

int main() {
	int nbNombres;
	scanf("%d", &nbNombres);

	for(int mask = 0;mask < (1 << 22);mask++) {
		reprs[mask] = -1;
	}

	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		scanf("%d", &nombres[iNombre]);
		reprs[nombres[iNombre] ^ MASK] = nombres[iNombre];
	}

	for(int mask = (1 << 22) - 1;mask >= 0;mask--) {
		for(int bit = 0;bit < 22;bit++) {
			if((mask | (1 << bit)) == mask) {
				reprs[mask ^ (1 << bit)] = max(reprs[mask ^ (1 << bit)], reprs[mask]);
			}
		}
	}

	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		printf("%d ", reprs[nombres[iNombre]]);
	}
	printf("\n");

	return 0;
}