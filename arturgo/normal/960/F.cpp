#include <iostream>
#include <map>
using namespace std;

int nbVilles, nbRoutes;
map<int, int> dyn[100 * 1000];

void ajoute(int pos, int temps, int taille) {
	auto suiv = dyn[pos].upper_bound(temps);
	suiv--;
	
	if(suiv->second >= taille) {
		return;
	}
	
	while(dyn[pos].upper_bound(temps) != dyn[pos].end()) {
		auto it = dyn[pos].upper_bound(temps);
		if(it->second <= taille) {
			dyn[pos].erase(it);
		}
		else {
			break;
		}
	}
	
	dyn[pos][temps] = taille;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nbVilles >> nbRoutes;
	
	for(int iVille = 0;iVille < nbVilles;iVille++) {
		dyn[iVille][-1] = 0;
	}
	
	int maxTaille = 0;
	for(int iRoute = 0;iRoute < nbRoutes;iRoute++) {
		int deb, fin, temps;
		cin >> deb >> fin >> temps;
		deb--; fin--;
		
		auto suiv = dyn[deb].lower_bound(temps);
		suiv--;
		
		int nouvTaille = suiv->second + 1;
		maxTaille = max(maxTaille, nouvTaille);
		
		ajoute(fin, temps, nouvTaille);
	}
	
	cout << maxTaille << endl;
	return 0;
}