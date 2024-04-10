#include <bits/stdc++.h>

const int P = 998244353;

int enlarge(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

int qpow(int a, int b) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % P;
		}
		a = 1ll * a * a % P;
	}
	return s;
}

typedef std::vector<std::vector<int>> matrix;

std::vector<int> Gauss(matrix a, std::vector<int> b) {
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		int k = -1;
		for (int j = i; j < n; ++j) {
			if (a[j][i] != -1) {
				k = j;
				break;
			}
		}
		if (k != i) {
			std::swap(a[k], a[i]);
			std::swap(b[k], b[i]);
		}
		int inv = qpow(a[i][i], P - 2);
		for (int j = i; j < n; ++j) {
			a[i][j] = 1ll * a[i][j] * inv % P;
		}
		b[i] = 1ll * b[i] * inv % P;
		for (int j = 0; j < n; ++j) {
			if (j != i && a[j][i]) {
				int t = P - a[j][i];
				for (int k = i; k < n; ++k) {
					a[j][k] = (a[j][k] + 1ll * a[i][k] * t) % P;
				}
				b[j] = (b[j] + 1ll * b[i] * t) % P;
			}
		}
	}
	return b;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> E(n);
	std::vector<int> deg(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		++deg[v];
	}
	
	std::vector<int> Q;
	for (int i = 0; i < n; ++i) {
		if (!deg[i]) {
			Q.push_back(i);
		}
	}
	for (int i = 0; i < (int)Q.size(); ++i) {
		int u = Q[i];
		for (int v : E[u]) {
			--deg[v];
			if (!deg[v]) {
				Q.push_back(v);
			}
		}
	}

	std::reverse(Q.begin(), Q.end());
	std::vector<int> vis(n + 1, -1);
	std::vector<int> SG(n);
	int mx = 0;
	for (int u : Q) {
		for (int v : E[u]) {
			vis[SG[v]] = u;
		}
		SG[u] = 0;
		while (vis[SG[u]] == u) {
			++SG[u];
		}
		mx = std::max(mx, SG[u]);
	}
	mx = enlarge(mx + 1);
	std::vector<int> cnt(mx);
	for (int i = 0; i < n; ++i) {
		++cnt[SG[i]];
	}

	matrix A(mx, std::vector<int>(mx));
	std::vector<int> b(mx);
	int inv = qpow(n + 1, P - 2);
	for (int i = 0; i < mx; ++i) {
		A[i][i] = 1;
		for (int j = 0; j < mx; ++j) {
			A[i][j] = (A[i][j] + 1ll * (P - cnt[i ^ j]) * inv) % P;
		}
	}
	b[0] = 1;
	std::vector<int> res = Gauss(A, b);
	std::cout << (P + 1 - 1ll * res[0] * inv % P) % P << "\n";
}