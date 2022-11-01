#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; i++) {
		 for(int j = 0; j < m; j++) {
		 	cin >> a[i][j];
		 }
	}
		vector<vector<int>> pf(n, vector<int>(m, 1));
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i - 1][j] <= a[i][j]) {
					pf[i][j] += pf[i - 1][j];
				}
			}
		}
		vector<int> hi(n, 0);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				hi[i] = max(hi[i], pf[i][j]);
			}
		}
		int q;
		cin >> q;
		for(int i = 0; i < q; i++) {
			int l, r;
			cin >> l >> r;
			--l; --r;
			if(hi[r] >= r - l + 1) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
}