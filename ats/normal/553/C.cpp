#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
vector<vector<int> > g;
vector<vector<int> > r;
vector<int> V;
vector<int> X;
int cnt = 0;
int dfs(int a, int p, int k) {
	X[a] = k;
	V[a] = 1;
	for (int i = 0; i < g[a].size(); i++) {
		if (V[g[a][i]] == 0) {
			dfs(g[a][i], a, k^r[a][i]);
		}
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	g.resize(N);
	r.resize(N);
	V.resize(N, 0);
	X.resize(N, 0);
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		a--; b--; c = 1 - c;
		g[a].push_back(b);
		g[b].push_back(a);
		r[a].push_back(c);
		r[b].push_back(c);
	}
	for (int i = 0; i < N; i++) {
		if (V[i] == 0) {
			cnt++;
			dfs(i, -1, 0);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			if ((X[i] ^ X[g[i][j]]) != r[i][j]) {
				cout << 0 << endl;
				return 0;
			}
		}
	}
	int res = 1;
	for (int i = 0; i < cnt - 1; i++) {
		res = (res * 2) % MOD;
	}
	cout << res << endl;
}