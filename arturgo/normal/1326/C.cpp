#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(false);

	int nbNombres, nbParties;
	cin >> nbNombres >> nbParties;

	vector<pair<int, int>> paires;
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		int nombre;
		cin >> nombre;

		paires.push_back({nombre, iNombre});
	}

	sort(paires.begin(), paires.end());

	vector<int> indices;
	long long somme = 0;
	for(int iFois = 0;iFois < nbParties;iFois++) {
		pair<int, int> paire = paires.back();
		paires.pop_back();

		somme += paire.first;
		indices.push_back(paire.second);
	}
	sort(indices.begin(), indices.end());
	long long nbManieres = 1;

	for(int i = 1;i < (int)indices.size();i++) {
		nbManieres = (nbManieres * (indices[i] - indices[i - 1] )) % MOD;
	}

	cout << somme << " " << nbManieres << endl;


	return 0;
}