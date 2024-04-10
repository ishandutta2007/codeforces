#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int contenu[1000];

int main() {
	int nbNombres, the;
	cin >> nbNombres >> the;
	
	vector<pair<int, int>> nombres;
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		int nombre;
		cin >> nombre;
		nombres.push_back(make_pair(nombre, iNombre));
	}
	
	sort(nombres.begin(), nombres.end());
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		contenu[nombres[iNombre].second] = nombres[iNombre].first - nombres[iNombre].first / 2;
		the -= nombres[iNombre].first - nombres[iNombre].first / 2;
	}
	
	if(the < 0) {
		cout << -1 << endl;
		return 0;
	}
	
	int cur = nbNombres - 1;
	while(the != 0 && cur != -1) {
		int val = min(the, nombres[cur].first - contenu[nombres[cur].second]);
		the -= val;
		contenu[nombres[cur].second] += val;
		cur--;
	}
	
	if(cur == -1 && the != 0) {
		cout << -1 << endl;
		return 0;
	}
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		cout << contenu[iNombre] << " ";
	}
	
	cout << endl;
	return 0;
}