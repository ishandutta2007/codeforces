#include <bits/stdc++.h>

const int N = 300005, P = 998244353;

int n;
std::vector<int> E[N];

int f[N][3];

void dfs(int u, int fa = 0) {
	std::vector<int> son;
	for (int v : E[u]) {
		if (v != fa) {
			dfs(v, u);
			son.push_back(v);
		}
	}
	f[u][0] = f[u][2] = 1;
	for (int v : son) {
		f[u][0] = 1ll * f[u][0] * (2ll * f[v][1] + f[v][2]) % P;
		f[u][2] = 1ll * f[u][2] * (f[v][1] + f[v][2]) % P;
	}
	std::vector<int> pre(son.size() + 1), suf(son.size() + 1);
	pre[0] = 1;
	for (int i = 0; i < (int)son.size(); ++i) {
		int v = son[i];
		pre[i + 1] = 1ll * pre[i] * (2ll * f[v][1] + f[v][2]) % P;
	}
	suf[son.size()] = 1;
	for (int i = (int)son.size() - 1; ~i; --i) {
		int v = son[i];
		suf[i] = 1ll * suf[i + 1] * (2ll * f[v][1] + f[v][2]) % P;
	}
	f[u][1] = 0;
	for (int i = 0; i < (int)son.size(); ++i) {
		int v = son[i];
		f[u][1] = (f[u][1] + 1ll * pre[i] * suf[i + 1] % P * f[v][0]) % P;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		E[u].push_back(v), E[v].push_back(u);
	}

	dfs(1);
	std::cout << (f[1][1] + f[1][2]) % P << "\n";
}