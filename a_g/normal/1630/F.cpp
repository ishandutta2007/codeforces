#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> D[N];
int a[N];
int b[N];
bitset<N> u;
int m[N];

bool kuhn(int v, vector<vector<int>>& G) {
	if (u[v]) return 0;
	u[v] = 1;
	for (int j: G[v]) {
		if (m[j] == -1 || kuhn(m[j], G)) {
			m[j] = v;
			return 1;
		}
	}
	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j+=i) {
			D[j].push_back(i);
		}
	}
	fill(b, b+N, -1);
	fill(m, m+2*N, -1);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[a[i]] = i;
		}
		vector<vector<int>> G(2*n);
		for (int i = 0; i < n; i++) {
			for (int d: D[a[i]]) {
				if (b[d] != -1) {
					G[i].push_back(b[d]+n);
					if (d != a[i]) {
						G[i].push_back(b[d]);
						G[i+n].push_back(b[d]+n);
					}
				}
			}
		}
		for (int i = 0; i < 2*n; i++) {
			sort(G[i].begin(), G[i].end());
			G[i].resize(unique(G[i].begin(), G[i].end()) - G[i].begin());
		}
		int M = 0;
		for (int i = 0; i < 2*n; i++) {
			u = 0;
			M += kuhn(i, G);
		}
		for (int i = 0; i < n; i++) b[a[i]] = -1;
		fill(m, m+2*n, -1);
		cout << M-n << '\n';
	}
}