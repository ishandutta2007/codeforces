#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k, m; cin >> n >> k >> m;
	vector<int> v[m];
	for(int i = 0; i < n; i++) {
		int x; cin >> x; v[x % m].push_back(x);
	}
	for(int i = 0; i < m; i++)
		if(v[i].size() >= k) {
			cout << "Yes\n";
			for(int j = 0; j < k; j++) cout << v[i][j] << ' ';
			return 0;
		}
	cout << "No";
}