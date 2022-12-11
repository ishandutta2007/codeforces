#include <iostream>
#include <algorithm>
using namespace std;

class Comp {
	public:
		bool operator () (const pair<int, int> &a, const pair<int, int> &b) {
			return a.first < b.first;
		}
};

int nbNombres;
int nombres[100 * 1000];

pair<int, int> paires[100 * 1000];

int ids[100 * 1000];

int ocGauche[100 * 1000];
int ocDroite[100 * 1000];

int trouve(int val) {
	auto it = lower_bound(paires, paires + nbNombres, make_pair(val, 0), Comp());
	
	if(it->first == val) {
		return ids[it->second];
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(false);
	cin >> nbNombres;
	
	long long somme = 0;
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		cin >> nombres[iNombre];
		
		paires[iNombre] = make_pair(nombres[iNombre], iNombre);
		
		somme += nombres[iNombre];
	}
	
	if(somme % 2 == 1) {
		cout << "NO" << endl;
		return 0;
	}
	
	sort(paires, paires + nbNombres);
	
	ocDroite[0]++;
	for(int iNombre = 1;iNombre < nbNombres;iNombre++) {
		if(paires[iNombre].first == paires[iNombre - 1].first) {
			ids[paires[iNombre].second] = ids[paires[iNombre - 1].second];
		}
		else {
			ids[paires[iNombre].second] = ids[paires[iNombre - 1].second] + 1;
		}
		ocDroite[ids[paires[iNombre].second]]++;
	}
	
	long long sommeGauche = 0;
	
	if(trouve(somme / 2) != -1) {
		cout << "YES" << endl;
		return 0;
	}
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		ocDroite[ids[iNombre]]--;
		ocGauche[ids[iNombre]]++;
		sommeGauche += nombres[iNombre];
		
		long long sauveur = sommeGauche - somme / 2;
		
		if(sauveur == 0) {
			cout << "YES" << endl;
			return 0;
		}
		
		if(abs(sauveur) > 1000 * 1000 * 1000) {
			continue;
		}
		
		int pos = trouve(abs(sauveur));
		
		if(pos == -1)
			continue;
		
		if(sauveur < 0 && ocDroite[pos] != 0) {
			cout << "YES" << endl;
			return 0;
		}
		else if(sauveur > 0 && ocGauche[pos] != 0) {
			cout << "YES" << endl;
			return 0;
		}
	}
	
	cout << "NO" << endl;
	return 0;
}