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
		int n, m, k;
		cin >> n >> m >> k;
		
		int nbLigs = 0, nbCols = 0;
		bool lig3 = false, col3 = false;
		
		for(int iColor = 0;iColor < k;iColor++) {
			int nombre;
			cin >> nombre;
			
			if(nombre >= 2 * n) {
				nbCols += nombre / n;
				if(nombre / n >= 3)
					col3 = true;
			}
			if(nombre >= 2 * m) {
				nbLigs += nombre / m;
				if(nombre / m >= 3)
					lig3 = true;
			}
		}
		
		if(nbLigs >= n && (n % 2 == 0 || lig3)) {
			cout << "Yes" << endl;
			continue;
		}
		if(nbCols >= m && (m % 2 == 0 || col3)) {
			cout << "Yes" << endl;
			continue;
		}
		cout << "No" << endl;
	}
	return 0;
}