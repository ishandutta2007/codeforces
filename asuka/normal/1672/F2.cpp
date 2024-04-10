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

int n, p[N], q[N], to[N], buc[N], deg[N];
bool vis[N];
vector<int> a[N], e[N];

void add(int u, int v) {
	e[u].pb(v);
	deg[v]++;
}

bool solve() {
	scanf("%d", &n);

	rep(i, 1, n) a[i].clear(), e[i].clear(), vis[i] = 0, buc[i] = 0, deg[i] = 0;

	rep(i, 1, n) scanf("%d", &p[i]), a[p[i]].pb(i);

	int ps = 0, mx = 0;

	rep(i, 1, n) if (SZ(a[i]) > mx) mx = SZ(a[i]), ps = i;

	rep(i, 1, n) scanf("%d", &q[i]), to[a[q[i]].back()] = i, a[q[i]].pop_back();

	rep(i, 1, n) {
		if (p[i] != ps) continue;

		int x = i;
		vector<int> vec;

		while (1) {
			vis[x] = 1;
			vec.pb(p[x]);

			if (p[to[x]] == ps) break;

			x = to[x];
		}

		for (int x : vec) if (++buc[x] > 1) return 0;

		for (int x : vec) buc[x] = 0;

		rep(i, 1, SZ(vec) - 1) add(vec[i - 1], vec[i]);
	}

	rep(i, 1, n) if (!vis[i]) return 0;

	queue<int> q;

	rep(i, 1, n) if (!deg[i]) q.push(i);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : e[u]) {
			if (--deg[v] == 0)
				q.push(v);
		}
	}

	rep(i, 1, n) if (deg[i]) return 0;

	return 1;
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int T;

	for (scanf("%d", &T); T; T--) puts(solve() ? "AC" : "WA");

	return 0;
}