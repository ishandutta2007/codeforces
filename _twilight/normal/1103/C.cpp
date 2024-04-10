#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2.5e5 + 5;

int n, m, k;
int d[N], fa[N];
vector<int> g[N];
vector<int> leaf;

inline void init() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void dfs(int p, int _fa) {
	fa[p] = _fa, d[p] = d[_fa] + 1;
	boolean aflag = false;
	for (auto e : g[p]) {
		if (!d[e]) {
			dfs(e, p);
			aflag = true;
		}
	}
	if (!aflag) {
		leaf.push_back(p);
	}
}

inline void solve() {
	int mx = -1, pid = -1;
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		if (d[i] > mx) {
			pid = i, mx = d[i];
		}
	}
	if (mx >= n / k) {
		puts("PATH");
		vector<int> path;
		for (int p = pid; p; p = fa[p]) {
			path.push_back(p);
		}
		printf("%d\n", (signed) path.size());
		for (auto p : path) {
			printf("%d ", p);
		}
		return;
	}
	puts("CYCLES");
	assert((signed) leaf.size() >= k);
	for (int _ = 0; _ < k; _++) {
		int l = leaf[_];
		int a = -1, b = -1;
		for (int i = 0; i < (signed) g[l].size() && (a < 0 || b < 0); i++) {
			int p = g[l][i];
			if (p == fa[l]) {
				continue;
			}
			if (a == -1) {
				a = p;
			} else if (b == -1) {
				b = p;
			}
		}
		assert(a != -1 && b != -1);

		vector<int> cir;
		if ((d[l] - d[a] + 1) % 3) {
			for (int p = l; ; p = fa[p]) {
				cir.push_back(p);
				if (p == a) {
					break;
				}
			}
		} else if ((d[l] - d[b] + 1) % 3) {
			for (int p = l; ; p = fa[p]) {
				cir.push_back(p);
				if (p == b) {
					break;
				}
			}
		} else {
			cir.push_back(l);
			if (d[a] < d[b]) {
				swap(a, b);
			}
			for (int p = a; ; p = fa[p]) {
				cir.push_back(p);
				if (p == b) {
					break;
				}
			}
		}
		assert(cir.size() > 3);
		assert(cir.size() % 3);
		printf("%d\n", (signed) cir.size());
		for (auto p : cir) {
			printf("%d ", p);
		}
		putchar('\n');
	}
}

int main() {
	init();
	solve();
	return 0;
}