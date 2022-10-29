#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e3 + 5, M = 12, S = 1 << (M - 1);
const int Mod = 1e9 + 7;

void exgcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1, y = 0;
	} else {
		exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
}

int inv(int a) {
	int x, y;
	exgcd(a, Mod, x, y);
	return (x < 0) ? (x + Mod) : (x);
}

int add(int a, int b) {
	return ((a += b) >= Mod) ? (a - Mod) : (a);
}

int n, m;
int deg[M];
int u[M], v[M];
vector<int> id[M];
vector<int> G1[N], G2[M];

#define RT(x) (((m - 1) << 1) + x + 1) 
// 0 ~ 2m - 2: edge (u, v), u as father;
// 2m - 1 ~ 3m - 2: (i - (2m - 1)) as root
int f[N][M * 3], g[S];
template <vector<int> G[]>
void dfs(int p, int fa, int& ans) {
	for (auto& e : G[p]) {
		if (e ^ fa) {
			dfs<G>(e, p, ans);
		}
	}
	for (int r = 0; r < m; r++) {
		int full = 1 << deg[r];
		memset(g, 0, full << 2);
		g[0] = 1;
		for (auto& e : G[p]) {
			if (e == fa) {
				continue;
			}
			for (int s = full - 1; s; s--) {
				for (int i = 0, x; i < deg[r]; i++) {
					if ((s >> i) & 1) {
						x = id[r][i];
						g[s] = (g[s] + g[s ^ (1 << i)] * 1ll * f[e][x]) % Mod;
					}
				}
			}
		}
		ans = add(ans, f[p][RT(r)] = g[--full]);
		for (int i = 0; i < deg[r]; i++) {
			f[p][id[r][i] ^ 1] = g[full ^ (1 << i)];
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		--u, --v;
		G1[u].push_back(v);
		G1[v].push_back(u);
	}
	scanf("%d", &m);
	for (int i = 0, u, v; i < m - 1; i++) {
		scanf("%d%d", &u, &v);
		deg[--u]++, deg[--v]++;	
		G2[u].push_back(v);
		G2[v].push_back(u);
		id[u].push_back((i << 1));
		id[v].push_back((i << 1) | 1);
	}
	int a = 0, b = 0;
	dfs<G1>(0, -1, a);
	dfs<G2>(0, -1, b);
	a = 1ll * a * inv(b) % Mod;
	printf("%d\n", a);
	return 0;
}