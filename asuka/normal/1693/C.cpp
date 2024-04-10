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
const int N = 200015;
int n, m, f[N], d[N];
vector<int> e[N];
map<int, int> w[N];
bool vis[N];

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);

	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);

		if (w[v][u]++ == 0)
			e[v].pb(u);

		d[u]++;
	}

	priority_queue<pii, vector<pii>, greater<pii>> q;

	memset(f, 0x3f, sizeof f);
	f[n] = 0;
	q.emplace(0, n);

	while (!q.empty()) {
		auto [x, u] = q.top();
		q.pop();

		if (vis[u]) continue;

		vis[u] = 1;
		x = f[u];

		for (int v : e[u]) {
			d[v] -= w[u][v];

			if (f[v] > f[u] + d[v] + 1) {
				f[v] = f[u] + d[v] + 1;
				q.emplace(f[v], v);
			}
		}
	}

	printf("%d\n", f[1]);
	return 0;
}