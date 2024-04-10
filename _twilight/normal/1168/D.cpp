#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 150005, Sigma = 26;

int n,q;
char s[N];
int D = -1;
int sum[N];
int cnt_bad;
int f[N][26];
int g[N][26];
int L[N], R[N];
vector<int> G[N];
int fa[N], rfa[N];
int dep[N], bel[N];

int dfs(int p, int dp) {
	int d = G[p].size();
	dep[p] = dp;
	if (!d) {
		return bel[p] = p;
	}
	if (d == 1) {
		return bel[p] = dfs(G[p][0], dp + 1);
	}
	rfa[L[p] = dfs(G[p][0], dp + 1)] = p;
	rfa[R[p] = dfs(G[p][1], dp + 1)] = p;
	return bel[p] = p;
}

void upd(int p, int c) {
	sum[p] -= f[p][c];
	f[p][c] = max(f[L[p]][c] + g[L[p]][c], f[R[p]][c] + g[R[p]][c]);
	sum[p] += f[p][c];
}

boolean is_bad(int p) {
	return D - dep[p] < sum[p];
}
void dfs(int p) {
	if (!p) {
		return;
	}
	dfs(L[p]);
	dfs(R[p]);
	for (int i = 0; i < 26; i++) {
		upd(p, i);
	}
	cnt_bad += is_bad(p);
}

void update(int p, int c, int dt) {
	g[p][c] += dt;
	while (p) {
		cnt_bad -= is_bad(p);
		upd(p, c);
		cnt_bad += is_bad(p);
		p = rfa[p];
	}
}

void query() {
	if (cnt_bad) {
		puts("Fou");
	} else {
		int ans = 0, avai = D - sum[bel[1]];
		for (int i = 0; i < 26; i++) {
			avai -= g[bel[1]][i];
		}
		for (int i = 0; i < 26; i++) {
			ans += (i + 1) * (f[bel[1]][i] + avai + g[bel[1]][i]);
		}
		printf("Shi %d\n", ans);
	}
}

int main() {
//	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++) {
		scanf("%d%s", fa + i, s + i);
		G[fa[i]].push_back(i);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		if (!G[i].size()) {
			if (D == -1) {
				D = dep[i];
			} else if (D != dep[i]) {
				while (q--) {
					puts("Fou");
				}
				return 0;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (s[i] != '?') {
			g[bel[i]][s[i] - 'a']++;
		}
	}
	dfs(bel[1]);
	int x;
	char buf[5];
	while (q--) {
		scanf("%d%s", &x, buf);
		if (s[x] != '?') {
			update(bel[x], s[x] - 'a', -1);
		}
		s[x] = buf[0];
		if (s[x] != '?') {
			update(bel[x], s[x] - 'a', 1);
		}
		query();
	}
	return 0;
}