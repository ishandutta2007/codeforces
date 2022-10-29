#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 5e3 + 5, M = 2e6 + 5, Mod = 1e9 + 7;

int add(int a, int b) {
	return ((a += b) >= Mod) ? (a - Mod) : (a);
}

#define pii pair<int, int>

int gcd(int a, int b) {
	return (!b) ? (a) : (gcd(b, a % b));
}

boolean _pool[M << 1];
boolean *_top = _pool;

boolean* alloc(int sz) {
	boolean *top = _top;
	_top += sz;
	return top;
}

int n, a, b;
char s[M];
int sz[N];
boolean* own[N];
boolean G[N][N];

stack<int> S;
vector<int> SCC;
boolean ins[N], vis[M];
int dfs_clock, cnt_scc;
int dfn[N], low[N], bel[N];

int sz_sc[N];
boolean *own_sc[N];
void dispose() {
	int D = 0;
	for (auto p : SCC) {
		D = gcd(D, sz[p]);
	}
	sz_sc[cnt_scc] = D;
	own_sc[cnt_scc] = alloc(D);
	boolean *app = own_sc[cnt_scc];
	for (auto& p : SCC) {
		for (int i = 0; i < sz[p]; i++) {
			if (own[p][i]) {
				app[i % D] = true;
			}
		}
	}
}

void tarjan(int p) {
	dfn[p] = low[p] = ++dfs_clock;
	vis[p] = ins[p] = true;
	S.push(p);
	for (int e = 1; e <= n; e++) {
		if (G[p][e]) {
			if (!vis[e]) {
				tarjan(e);
				low[p] = min(low[p], low[e]);
			} else if (ins[e]) {
				low[p] = min(low[p], dfn[e]);
			}
		}
	}
	
	if (dfn[p] == low[p]) {
		int cur;
		SCC.clear();
		++cnt_scc;
		do {
			cur = S.top();
			S.pop();
			SCC.push_back(cur);
			bel[cur] = cnt_scc;
			ins[cur] = false;
		} while (cur != p);
		dispose();
	}
}

int deg[N];
int order[N];
boolean nG[N][N];
void rebuild() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (bel[i] != bel[j] && G[i][j]) {
				nG[bel[i]][bel[j]] = true;
			}
		}
	}
	for (int i = 1; i <= cnt_scc; i++) {
		for (int j = i + 1; j <= cnt_scc; j++) {
			if (nG[i][j]) {
				deg[j]++;
			} else {
				deg[i]++;
			}
		}
	} 
	for (int i = 1; i <= cnt_scc; i++) {
		order[deg[i]] = i;
	}
}

pii A[N];
int comb[N][N];
int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= n; j++) {
			G[i][j] = s[j] - '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", sz + i);
		own[i] = alloc(sz[i]);
		scanf("%s", s);
		for (int j = 0; j < sz[i]; j++) {
			own[i][j] = s[j] - '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			tarjan(i);
		}
	}
	rebuild();
	for (int i = 1; i < cnt_scc; i++) {
		int x = order[i - 1], y = order[i];
		int d = gcd(sz_sc[x], sz_sc[y]);
		memset(vis, false, d);
		for (int j = 0; j < sz_sc[x]; j++) {
			if (own_sc[x][j]) {
				vis[j % d] = true;
			}
		}
		for (int j = 0; j < sz_sc[y]; j++) {
			own_sc[y][j] = own_sc[y][j] || vis[j % d];	
		}
	}
	for (int i = 1; i <= n; i++) {
		boolean *app = own_sc[bel[i]];
		int D = sz_sc[bel[i]];
		for (int j = 0; j < sz[i]; j++) {
			if (own[i][j]) {
				A[i].second++;
			} else if (app[j % D]) {
				A[i].first++;
			}
		}
		A[i].first += A[i].second;
	}
	sort(A + 1, A + n + 1);
	reverse(A + 1, A + n + 1);
	comb[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = add(comb[i - 1][j - 1], comb[i - 1][j]);
		}
	}
	int c = a - b, ans = 0;
	for (int i = b; i <= n; i++) {
		int x = 0, y;
		for (int j = 1; j < i; j++) {
			if (A[j].second > A[i].first) {
				x++;
			}
		}
		y = max(x - c, 0);
		for (int j = y; j < b; j++) {
			ans = (ans + comb[x][j] * 1ll * comb[i - x - 1][b - j - 1]) % Mod;
		}
	}
	printf("%d\n", ans);
	return 0;
}