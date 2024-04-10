/*
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 





 
 

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int p[n];
	for(int i = 0; i < n; i++) cin >> p[i], --p[i];
	for(int i = 0; i < m; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		--l; --r; --x;
		int cnt = 0;
		for(int j = l; j <= r; j++) if(p[j] < p[x]) cnt++;
		if(l + cnt == x) cout << "Yes\n";
		else cout << "No\n";
	}
}