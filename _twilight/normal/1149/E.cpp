#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m;
bool tmp[N];
int h[N], f[N], b[N];
vector<int> G[N];

int deg[N];
vector<int> ord;
void topusort() {
	queue<int> Q;
	for (int i = 1; i <= n; i++) {
		if (!deg[i]) {
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int p = Q.front();
		Q.pop();
		ord.push_back(p);
		for (auto e : G[p]) {
			if (!--deg[e]) {
				Q.push(e);
			}
		}
	}
}

int qwq(int x) {
	int t = 0;
	while (x)
		x >>= 1, t++;
	return t;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", h + i);
	}
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		G[u].emplace_back(v);
		deg[v]++;
	}
	topusort();
	reverse(ord.begin(), ord.end());
	for (auto p : ord) {
		int t = G[p].size();
		fill(tmp, tmp + t + 1, false);
		for (auto e : G[p]) {
			tmp[f[e]] = true;
		}
		while (tmp[f[p]])
			f[p]++;
	}
	for (int i = 1; i <= n; i++) {
		b[f[i]] ^= h[i];
	}
	int mx = n;
	while (mx--) {
		if (b[mx]) {
			break;
		}
	}
	if (mx < 0) {
		puts("LOSE");
	} else {
		puts("WIN");
		int p; 
		for (p = 1; p <= n; p++) {
			if (f[p] == mx && (h[p] ^ b[mx]) < h[p]) {
				break;
			}
		}
		assert(p <= n);
		h[p] ^= b[mx];
		b[mx] = 0;
		for (auto e : G[p]) {
			h[e] ^= b[f[e]];
			b[f[e]] = 0;
		}
		for (int i = 1; i <= n; i++) {
			printf("%d ", h[i]);
		}
	}
	return 0;
}