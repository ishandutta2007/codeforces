#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, m;
		cin >> n >> m;
		for (int j = 0; j < n; ++j) {
			for (int l = 0; l < m; ++l) {
				if (l == m - 1 && j == n - 1)
					break;
				cout << "B";
			}
			if (j == n - 1)
				break;
			cout << endl;
		}	
		cout << "W" << endl;
	}
	return 0;
}