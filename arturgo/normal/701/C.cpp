#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

map<char, int> occurs;

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int nbCases;
	cin >> nbCases;
	
	string pokemons;
	cin >> pokemons;
	
	for(int iCase = 0;iCase < nbCases;iCase++) {
		occurs[pokemons[iCase]] = 0;
	}
	
	int minInt = 1000 * 1000 * 1000;
	int nbOpens = 0;
	int fin = 0;	
	for(int debut = 0;debut < nbCases;debut++) {
		while(fin != nbCases && nbOpens != (int)occurs.size()) {
			occurs[pokemons[fin]]++;
			if(occurs[pokemons[fin]] == 1) {
				nbOpens++;
			}
			fin++;	
		}
		
		if(nbOpens == (int)occurs.size()) {
			minInt = min(minInt, fin - debut);
		}
		
		occurs[pokemons[debut]]--;
		if(occurs[pokemons[debut]] == 0) {
			nbOpens--;
		}
	}
	
	cout << minInt << endl;
	return 0;
}