#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];
long long ans[N];
vector <int> adj[N];
set <pair <int, int> > s;
vector <int> vec;

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		long long s = 0;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			s += a[u] + a[v];
			
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j + 1 <= adj[i].size(); j++) {
				vec.push_back(a[i]);
			}
		}
		sort(vec.begin(), vec.end());
		ans[n - 1] = s;
		for (int i = 0; i < n - 2; i++) {
			s -= vec[i];
			ans[n - i - 2] = s;
		}
		for (int i = 1; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
		vec.clear();
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
	}
	
	return 0;
}