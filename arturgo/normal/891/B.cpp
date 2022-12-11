#include <iostream>
#include <algorithm>
using namespace std;

int nbNombres;
vector<pair<int, int>> nombres;
int solution[22];

int main() {
	cin >> nbNombres;
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		int nombre;
		cin >> nombre;
		nombres.push_back({nombre, iNombre});
	}
	
	sort(nombres.begin(), nombres.end());
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		int suiv = (iNombre + 1) % nbNombres;
		solution[nombres[suiv].second] = nombres[iNombre].first;
	}
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		cout << solution[iNombre] << " ";
	}
	cout << endl;
	return 0;
}