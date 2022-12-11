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
		
		int maxi = 0, somme = 0;
		for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
			int nombre;
			cin >> nombre;
			somme += nombre;
			maxi = maxi + (nombre + x - 1) / x;
		}
		
		cout << (somme + x - 1) / x << " " << maxi << endl;
	}
	return 0;
}