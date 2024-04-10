#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	long long nbLignes, nbTours;
	cin >> nbLignes >> nbTours;
	
	set<long long> lignes, colonnes;
	
	for(long long iTour = 0;iTour < nbTours;iTour++) {
		long long x, y;
		cin >> x >> y;
		
		if(lignes.find(y) == lignes.end()) {
			lignes.insert(y);
		}
		
		if(colonnes.find(x) == colonnes.end()) {
			colonnes.insert(x);
		}
		
		long long curL = lignes.size();
		long long curC = colonnes.size();
		long long nbAttacked = nbLignes * (curL + curC) - curL * curC;
		cout << nbLignes * nbLignes - nbAttacked << " ";
	}
	return 0;
}