#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int nbTests;
	cin >> nbTests;
	
	for(int iTest = 0;iTest < nbTests;iTest++) {
		int nbNombres, x;
		cin >> nbNombres >> x;
		
		vector<pair<int, int>> nombres;
		
		int somme = 0;
		for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
			int nombre;
			cin >> nombre;
			nombres.push_back({1, nombre});
		}
		
		int iNombre = 0;
		for(;iNombre != (int)nombres.size();iNombre++) {
			pair<int, int> paire = nombres[iNombre];
			
			if(paire.second % x != 0)
				break;
			somme += paire.first * paire.second;
			nombres.push_back({x * paire.first, paire.second / x});
		}
		
		for(;iNombre != (int)nombres.size();iNombre++) {
			pair<int, int> paire = nombres[iNombre];
			somme += paire.first * paire.second;
		}
		
		cout << somme << endl;
	}
	return 0;
}