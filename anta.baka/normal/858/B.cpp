#include <bits/stdc++.h>

using namespace std;

int n, m, k[100], f[100];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) cin >> k[i] >> f[i];
	set<int> X;
	for(int x = 1; x <= 101; x++) {
		bool ok = true;
		for(int i = 0; i < m; i++) {
			ok &= ((k[i] - 1) / x + 1 == f[i]);
		}
		if(!ok) continue;
		X.insert((n - 1) / x + 1);
		if(X.size() != 1) return cout << -1, 0;
	}
	cout << *X.begin();
}