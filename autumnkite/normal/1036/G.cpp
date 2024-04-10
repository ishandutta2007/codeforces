#include <bits/stdc++.h>

const int N = 1000005, K = 20;

int n, m, k;
std::vector<int> E[N];
int in[N], out[N];
int f[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		std::cin >> u >> v;
		++in[v], ++out[u];
		E[v].push_back(u);
	}
	std::vector<int> S, T;
	for (int i = 1; i <= n; ++i) {
		if (!in[i]) {
			S.push_back(i);
		}
		if (!out[i]) {
			T.push_back(i);
		}
	}
	k = S.size();

	std::vector<int> Q;
	for (int i = 0; i < (int)T.size(); ++i) {
		Q.push_back(T[i]);
		f[T[i]] = 1 << i;
	}
	for (int i = 0; i < (int)Q.size(); ++i) {
		int u = Q[i];
		for (int v : E[u]) {
			--out[v];
			f[v] |= f[u];
			if (!out[v]) {
				Q.push_back(v);
			}
		}
	}

	for (int i = 1; i < (1 << k) - 1; ++i) {
		int mask = 0, cntS = 0, cntT = 0;
		for (int j = 0; j < k; ++j) {
			if (i >> j & 1) {
				mask |= f[S[j]];
				++cntS;
			}
		}
		for (int j = 0; j < k; ++j) {
			if (!(mask >> j & 1)) {
				++cntT;
			}
		}
		if (cntS + cntT >= k) {
			std::cout << "NO\n";
			return 0;
		}
	}
	std::cout << "YES\n";
}