#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353, MAXN = 4007, MAXK = 77;
int f[2][MAXK][MAXN], C[MAXK][MAXK];

int main()
{
	for (int i = 0; i < MAXK; ++i) C[i][0] = 1;
	for (int i = 1; i < MAXK; ++i) for (int j = 1; j < MAXK; ++j) {
		C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		if (C[i][j] >= MOD) C[i][j] -= MOD;
	}

	ios_base::sync_with_stdio(0); cin.tie(0);
	int N[2], K;
	cin >> N[0] >> N[1] >> K;
	if (K & 1) return cout << 0 << endl, 0;

	for (int id = 0; id < 2; ++id) {
		vector<pair<int, int>> edges((N[id] - 1) << 1);
		for (int e = 0; e < N[id] - 1; ++e) {
			int u, v; cin >> u >> v;
			edges[e << 1] = pair<int, int>(u, v);
			edges[e << 1 | 1] = pair<int, int>(v, u);
		}

		vector<vector<int>> g(K + 1, vector<int>((N[id] - 1) << 1, 0));
		vector<vector<int>> h(K + 1, vector<int>(N[id] + 1, 0));
		for (int u = 1; u <= N[id]; ++u) f[id][0][u] = 1;
		for (int e = 0; e < ((N[id] - 1) << 1); ++e) h[0][edges[e].second] += (g[0][e] = 1);

		for (int k = 2; k <= K; k += 2) {
			for (int e = 0; e < ((N[id] - 1) << 1); ++e) {
				for (int k0 = 2; k0 <= k; k0 += 2) {
					f[id][k][edges[e].second] = (f[id][k][edges[e].second] + 1ll * g[k0 - 2][e] * f[id][k - k0][edges[e].second]) % MOD;

					g[k][e] = (g[k][e] + 1ll * (h[k0 - 2][edges[e].first] - g[k0 - 2][e ^ 1]) * g[k - k0][e]) % MOD;
					if (g[k][e] < 0) g[k][e] += MOD;
				}

				h[k][edges[e].second] += g[k][e];
				if (h[k][edges[e].second] >= MOD) h[k][edges[e].second] -= MOD;
			}
		}
	}

	int ans = 0;
	for (int k = 0; k <= K; k += 2) {
		int x0 = 0, x1 = 0;
		for (int u = 1; u <= N[0]; ++u) {
			x0 += f[0][k][u];
			if (x0 >= MOD) x0 -= MOD;
		}
		for (int v = 1; v <= N[1]; ++v) {
			x1 += f[1][K - k][v];
			if (x1 >= MOD) x1 -= MOD;
		}
		ans = (ans + 1ll * x0 * x1 % MOD * C[K][k]) % MOD;
	}
	cout << ans << endl;
}