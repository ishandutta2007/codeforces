#include <iostream>
#include <vector>
using namespace std;

vector<int> fortunes;

int barreRiche(int nbJours) {
	int deb = 0, fin = 1000 * 1000 * 1000 + 42;
	while(fin - deb > 1) {
		int mil = (deb + fin) / 2;
		long long dessus = 0;
		
		for(int fortune : fortunes) {
			dessus += max(0, fortune - mil);
		}
		
		if(dessus > nbJours) {
			deb = mil;
		}
		else {
			fin = mil;
		}
	}
	
	return deb + 1;
}

int barrePauvre(int nbJours) {
	int deb = 0, fin = 1000 * 1000 * 1000 + 42;
	while(fin - deb > 1) {
		int mil = (deb + fin) / 2;
		long long dessous = 0;
		
		for(int fortune : fortunes) {
			dessous += max(0, mil - fortune);
		}
		
		if(dessous > nbJours) {
			fin = mil;
		}
		else {
			deb = mil;
		}
	}
	return deb;
}

int main() {
	ios_base::sync_with_stdio(false);
	int nbFortunes, nbJours;
	cin >> nbFortunes >> nbJours;
	
	long long somme = 0;
	for(int iFortune = 0;iFortune < nbFortunes;iFortune++) {
		int argent;
		cin >> argent;
		somme += argent;
		fortunes.push_back(argent);
	}
	
	int riche = barreRiche(nbJours);
	int pauvre = barrePauvre(nbJours);
	
	if(riche <= pauvre + 1) {
		if(somme % nbFortunes == 0)
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}
	else {
		cout << riche - pauvre << endl;
	}
	return 0;
}