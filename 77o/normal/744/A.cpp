#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int N = 1001;

vector<int> g[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> c(k);
	for (int& i : c) cin >> i;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> sz(k);
	vector<int> used(n + 1);
	int t = n;
	int total = 0;
	for (int i = 0; i < k; i++) {
		queue<int> q;
		q.push(c[i]);
		used[c[i]] = 1;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			sz[i]++;
			for (int u : g[v]) {
				if (!used[u]) {
					used[u] = 1;
					q.push(u);
				}
 			}
		}
		t -= sz[i];
		total += sz[i] * (sz[i] - 1) / 2;
	}
	total += t * (*max_element(sz.begin(), sz.end())) + t * (t - 1) / 2;
	cout << total - m << endl;
	return 0;
}