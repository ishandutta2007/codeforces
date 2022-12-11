#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void io() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	io();

	int nbCells, nbCouleurs;
	cin >> nbCells >> nbCouleurs;

	vector<int> tailles;
	for(int iCouleur = 0;iCouleur < nbCouleurs;iCouleur++) {
		int taille;
		cin >> taille;
		tailles.push_back(taille);
	}

	vector<int> sol;

	int pos = nbCells;
	for(int iTaille = nbCouleurs - 1;iTaille >= 0;iTaille--) {
		int n = pos - tailles[iTaille];
		n = max(n, iTaille);

		if(n >= pos || n + tailles[iTaille] > nbCells) {
			cout << -1 << endl;
			return 0;
		}

		pos = n;
		sol.push_back(n);
	}

	if(pos != 0) {
		cout << -1 << endl;
		return 0;
	}

	while(!sol.empty()) {
		cout << 1 + sol.back() << " ";
		sol.pop_back();
	}

	cout << endl;
	return 0;
}