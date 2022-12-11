#include <iostream>
#include <vector>
using namespace std;

const int MAX_PREMIERS = 200 * 1000;
bool estDivisible[MAX_PREMIERS];
vector<int> premiers;

void calculePremiers() {
	estDivisible[0] = estDivisible[1] = true;
	for(int i = 2;i < MAX_PREMIERS;i++) {
		if(!estDivisible[i]) {
			premiers.push_back(i);
			for(int j = 2 * i;j < MAX_PREMIERS;j += i) {
				estDivisible[j] = true;
			}
		}
	}
}

int cnts[MAX_PREMIERS];

void decomp(int a) {
	for(int p : premiers) {
		if(p * p > a) {
			cnts[a]++;
			return;
		}
		
		int exp = 0;
	
		while(a % p == 0) {
			a /= p;
			exp++;
		}
		
		if(exp != 0) {
			cnts[p]++;
		}
	}
}

int main() {
	int nbPokemons;
	cin >> nbPokemons;
	
	calculePremiers();
	
	for(int iPokemon = 0;iPokemon < nbPokemons;iPokemon++) {
		int force;
		cin >> force;
		decomp(force);
	}
	
	int maxi = 1;
	for(int p : premiers) {
		maxi = max(maxi, cnts[p]);
	}
	cout << maxi << endl;
	return 0;
}