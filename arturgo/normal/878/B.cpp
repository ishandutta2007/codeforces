#include <iostream>
#include <vector>
using namespace std;

vector<pair<long long, long long>> groupes;

int main() {
	ios_base::sync_with_stdio(false);
	long long nbGens, tailleGroupe, nbFois;
	cin >> nbGens >> tailleGroupe >> nbFois;
	
	long long taille = nbGens;
	for(long long iGens = 0;iGens < nbGens;iGens++) {
		long long ville;
		cin >> ville;
		
		if(groupes.empty() || groupes.back().first != ville) {
			groupes.push_back({ville, 1});
		}
		else {
			groupes.back().second++;
		}
		
		while(groupes.back().second >= tailleGroupe) {
			groupes.back().second -= tailleGroupe;
			taille -= tailleGroupe;
		}
		
		while(groupes.back().second == 0) {
			groupes.pop_back();
		}
	}
	
	long long somme = nbFois * taille;
	
	long long deb = 0, fin = groupes.size() - 1;
	while(deb < fin) {
		if(groupes[deb].first != groupes[fin].first) {
			cout << somme << endl;
			return 0;
		}
		
		if(groupes[deb].second + groupes[fin].second == tailleGroupe) {
			deb++;
			fin--;
			somme -= (nbFois - 1) * tailleGroupe;
			continue;
		}
		
		if(groupes[deb].second + groupes[fin].second > tailleGroupe) {
			somme -= (nbFois - 1) * tailleGroupe;
		}
		
		cout << somme << endl;
		return 0;
	}
	
	if(deb > fin) {
		cout << 0 << endl;
		return 0;
	}
	
	if(deb == fin) {
		if((groupes[deb].second * nbFois) % tailleGroupe == 0)
			cout << 0 << endl;
		else
			cout << somme - ((nbFois * groupes[deb].second) / tailleGroupe) * tailleGroupe << endl;
		return 0;
	}
	
	cout << somme << endl;
	return 0;
}