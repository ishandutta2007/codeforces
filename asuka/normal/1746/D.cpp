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
int n, k, s[N];
ll d[N];
vector<int> e[N];

pair<ll, ll> dfs(int u, int c) {
	d[u] += s[u];
	int m = SZ(e[u]);
	if (!m) return mp((ll) c * d[u], d[u]);

	int nc = c / m;
	vector<ll> vec;
	ll sum = 0;

	for (int v : e[u]) {
		d[v] = d[u];
		auto [x, y] = dfs(v, nc);
		sum += x;
		vec.pb(y);
	}

	sort(all(vec), greater<ll>());

	rep(i, 1, c % m) {
		sum += vec[i - 1];
	}

	return mp(sum, vec[c % m]);
}

int main() {
#ifdef Asuka
	freopen("in","r",stdin);
	freopen("out","w",stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		rep(i, 1, n) e[i].clear(), d[i] = 0;
		rep(i, 2, n) { int x; scanf("%d", &x); e[x].pb(i); }
		rep(i, 1, n) scanf("%d", &s[i]);
		auto [x, y] = dfs(1, k);
		printf("%lld\n", x);
	}

	return 0;
}