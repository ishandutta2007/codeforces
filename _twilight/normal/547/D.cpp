#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5;

#define pii pair<int, int>

int n;
char ans[N << 1];
boolean vis[N << 1];
vector<pii> G[N << 1];

vector<int> E;
void dfs(int p) {
	while (!G[p].empty()) {
		pii par = G[p].back();
		G[p].pop_back();
		if (!vis[par.second]) {
			vis[par.second] = true;
			dfs(par.first);
			E.push_back(par.second);
		}
	}
}

int main() {
	scanf("%d", &n);
	const int V = 2e5;
	for (int i = 1, x, y; i <= n; i++) {
		scanf("%d%d", &x, &y);
		G[x].emplace_back(y + V, i);
		G[y + V].emplace_back(x, i);
	}
	int ls = 0, _n = n;
	for (int i = 1; i <= V + V; i++) {
		if (G[i].size() & 1) {
			if (ls) {
				G[ls].emplace_back(i, ++_n);
				G[i].emplace_back(ls, _n);
				ls = 0;
			} else {
				ls = i;
			}
		}
	}
	for (int i = 1; i <= V + V; i++) {
		E.clear();
		dfs(i);
		if (E.size()) {
			for (int j = 0; j < (signed) E.size(); j++) {
				if (E[j] <= n) {
					ans[E[j]] = "br"[j & 1];
				}
			}
			if (E.size() & 1) {
				int x;
				while ((x = E.back()) <= n) {
					ans[x] = "br"[E.size() & 1];
					E.pop_back();
				}
			}
		}
	}
	puts(ans + 1);
	return 0;
}