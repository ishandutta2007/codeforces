#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 20015, M = N * 20;
// <= x, > x
int n, m, k, a[N][15], b[N][15], tot;
vector<int> e[M];

void add(int u, int v) { e[u].pb(v); }

int dfn[M], scc[M], low[M], cnt, clk;
vector<int> stk;

void Tarjan(int u) {
	dfn[u] = low[u] = ++clk;
	stk.pb(u);

	for (int v : e[u]) {
		if (!dfn[v]) {
			Tarjan(v);
			low[u] = min(low[u], low[v]);

		} else if (!scc[v]) low[u] = min(low[u], dfn[v]);
	}

	if (dfn[u] == low[u]) {
		int x;
		cnt++;

		do {
			x = stk.back();
			stk.pop_back();
			scc[x] = cnt;
		} while (x != u);
	}
}

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	tot = 0;
	rep(i, 1, n) rep(j, 1, k) a[i][j] = ++tot, b[i][j] = ++tot;
	rep(i, 1, tot) e[i].clear();
	rep(i, 1, n) {
		add(b[i][k], a[i][k]);
		rep(j, 1, k - 1) add(a[i][j], a[i][j + 1]);
		rep(j, 2, k) add(b[i][j], b[i][j - 1]);

		if (i < n) rep(j, 1, k) add(b[i][j], b[i + 1][j]), add(a[i + 1][j], a[i][j]);
	}

	rep(_, 1, m) {
		int op, i, j, x;
		scanf("%d%d", &op, &i);

		if (op == 1) {
			scanf("%d", &x);

			if (x > 1) add(a[i][x], a[i][x - 1]), add(b[i][x - 1], b[i][x]);
			else add(a[i][x], b[i][x]);

		} else {
			scanf("%d%d", &j, &x);

			if (op == 2) {
				rep(y, 1, k) {
					int ny = x - y - 1;

					if (ny < 1) {
						add(b[i][y], a[i][y]);
						add(b[j][y], a[j][y]);

					} else if (ny <= k) {
						add(b[i][y], a[j][ny]);
						add(b[j][y], a[i][ny]);
					}
				}

			} else {
				rep(y, 1, k) {
					int ny = x - y - 1;

					if (ny > k) {
						add(a[i][y], b[i][y]);
						add(a[j][y], b[j][y]);

					} if (1 <= ny) {

						add(a[i][y], b[j][ny]);
						add(a[j][y], b[i][ny]);
					}
				}
			}
		}
	}

	cnt = clk = 0;
	rep(i, 1, tot) dfn[i] = low[i] = scc[i] = 0;

	rep(i, 1, tot) if (!dfn[i]) Tarjan(i);

	rep(i, 1, n) {
		rep(j, 1, k) {
			if (scc[a[i][j]] == scc[b[i][j]]) {
				puts("-1");
				return;
			}
		}
	}

	rep(i, 1, n) {
		rep(j, 1, k) {
			if (scc[b[i][j]] > scc[a[i][j]]) {
				printf("%d ", j);
				break;
			}
		}
	}

	printf("\n");
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int T;

	for (scanf("%d", &T); T--;) solve();

	return 0;
}