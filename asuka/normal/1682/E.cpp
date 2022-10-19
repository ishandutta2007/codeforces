#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

const int N = 200015;

int n, m, p[N], rk[N], deg[N], X[N], Y[N];
bool vis[N];
vector<pii> e[N];
vector<int> g[N];

void add(int u, int v) {
	g[u].pb(v);
	deg[v]++;
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);

	rep(i, 1, n) scanf("%d", &p[i]);

	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		X[i] = u; Y[i] = v;
		e[u].emplace_back(v, i);
		e[v].emplace_back(u, i);
	}

	rep(i, 1, n) {
		if (vis[i]) continue;

		int x = i, o = 0;
		vector<int> vec;

		while (!vis[x]) {
			vis[x] = 1;
			rk[x] = ++o;
			x = p[x];
			vec.pb(x);
		}

		for (int u : vec) {
			sort(all(e[u]), [&](pii x, pii y) {
				return (rk[x.fi] < rk[u] ? rk[x.fi] + o : rk[x.fi]) < (rk[y.fi] < rk[u] ? rk[y.fi] + o : rk[y.fi]);
			});

			rep(j, 1, SZ(e[u]) - 1) {
				add(e[u][j - 1].se, e[u][j].se);
			}
		}
	}

	queue<int> q;

	rep(i, 1, m) if (deg[i] == 0) q.push(i);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		printf("%d ", u);
		swap(p[X[u]], p[Y[u]]);

		for (int v : g[u]) {
			if (--deg[v] == 0) q.push(v);
		}
	}

	// printf("\n");

	rep(i, 1, n) assert(p[i] == i);

	return 0;
}