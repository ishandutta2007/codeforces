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
int MOD = 998244353;
vector<vector<int> > g;
vector<int> A;
vector<int> X;
int c = 0;
int b = 0;
int dfs(int a, int Z) {
	X[a] = Z;
	b++;
	if (Z == 0)c++;
	A[a] = 1;
	for (auto x : g[a]) {
		if (A[x] == 0) {
			dfs(x, 1 - Z);
		}
	}
}

int p2[300005];
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	p2[0] = 1;
	for (int i = 1; i < 300005; i++) {
		p2[i] = (2 * p2[i - 1]) % MOD;
	}
	while (t--) {
		int N, M;
		cin >> N >> M;
		int res = 0;
	
		A.clear(); A.resize(N, 0);
		X.clear(); X.resize(N, 0);
		g.clear(); g.resize(N);
		{
			int a, b;
			for (int i = 0; i < M; i++) {
				cin >> a >> b; a--; b--;
				g[a].push_back(b);
				g[b].push_back(a);
			}
		}
		res = 1;
		for (int i = 0; i < N; i++) {
			if (A[i] == 0) {
				c = 0;
				b = 0;
				dfs(i, 0);
				res = (res * ((p2[c] + p2[b - c]) % MOD)) % MOD;
			}
		}
		bool f = true;
		for (int i = 0; i < N; i++) {
			for (auto j : g[i]) {
				if (X[i] == X[j]) {
					f = false;
				}
			}
		}
		if (!f){
			res = 0;
		}

		cout << res << endl;
	}
}