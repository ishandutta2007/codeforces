#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;
vector<vector<pair<int, int> > > g;
vector<int> sz;
int N;
int center;
int res1 = 0;
int res2 = 0;
void dfs(int a, int p) {
	int mx = -1;
	sz[a] = 1;
	for (pair<int, int> pa : g[a]) {
		int i = pa.first;
		if (i != p) {
			dfs(i, a);
			sz[a] += sz[i];
			mx = max(mx, sz[i]);
			if (sz[i] % 2 == 1) {
				res1 += pa.second;
			}
		}
	}
	mx = max(mx, N - sz[a]);
	if (mx <= N / 2) {
		center = a;
	}
}
void dfs2(int a, int p, int d) {
	res2 += d;
	for (pair<int, int> pa : g[a]) {
		int i = pa.first;
		if (i != p) {
			dfs2(i, a, d + pa.second);
		}
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		N *= 2;
		g.clear();
		g.resize(N);
		sz.clear();
		sz.resize(N, 0);
		int res = 0;
		for (int i = 0; i < N - 1; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			a--;
			b--;
			g[a].emplace_back(b, c);
			g[b].emplace_back(a, c);
		}
		res1 = 0;
		res2 = 0;
		dfs(0, -1);
		dfs2(center, -1, 0);
		cout << res1 << " " << res2 << "\n";
	}
	return 0;
}