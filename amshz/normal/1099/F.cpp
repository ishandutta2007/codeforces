//khodaya khodet komak kon
# include <bits/stdc++.h>

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, P[xn];
ppi a[xn];
ll T, ps[xn], dp[xn], mn[xn << 2];
pll seg[xn << 2];
vector <int> adj[xn];

void build(int id, int l, int r){
	mn[id] = INF;
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	build(lc, l, mid);
	build(rc, mid, r);
}
void modify(int id, int l, int r, int pos, bool f){
	if (r - l == 1){
		seg[id] = {0, 0}, mn[id] = INF;
		if (f){
			seg[id] = a[l].A;
			seg[id].A *= seg[id].B;
			mn[id] = a[l].A.A;
		}
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos, f);
	else
		modify(rc, mid, r, pos, f);
	seg[id].A = seg[lc].A + seg[rc].A;
	seg[id].B = seg[lc].B + seg[rc].B;
	mn[id] = min(mn[lc], mn[rc]);
}
pll get(int id, int l, int r, int ql, int qr, pll val){
	if (qr <= l || r <= ql || qr <= ql || val.A < mn[id])
		return val;
	if (ql <= l && r <= qr && seg[id].A <= val.A)
		return {val.A - seg[id].A, val.B + seg[id].B};
	if (r - l == 1){
		if (a[l].A.A == 0)
			return val;
		ll t = val.A / a[l].A.A;
		t = min(t, seg[id].B);
		val.A -= t * a[l].A.A;
		val.B += t;
		return val;
	}
	int mid = l + r >> 1;
	return get(rc, mid, r, ql, qr, get(lc, l, mid, ql, qr, val));
}
void preDFS(int v){
	modify(1, 1, n + 1, P[v], 1);
	dp[v] = get(1, 1, n + 1, 1, n + 1, {max(0ll, T - 2ll * ps[v]), 0}).B;
	for (int u : adj[v])
		ps[u] += ps[v], preDFS(u);
	modify(1, 1, n + 1, P[v], 0);
}
void DFS(int v){
	vector <ll> vec;
	vec.push_back(0);
	vec.push_back(0);
	for (int u : adj[v])
		DFS(u), vec.push_back(dp[u]);
	sort(all(vec)), reverse(all(vec));
	dp[v] = max(dp[v], vec[1]);
	if (v == 1)
		dp[v] = max(dp[v], vec[0]);
}

int main(){
	fast_io;

	cin >> n >> T;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].A.B, a[i].B = i;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].A.A;
	for (int i = 2; i <= n; ++ i){
		int p;
		cin >> p >> ps[i];
		adj[p].push_back(i);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i)
		P[a[i].B] = i;
	build(1, 1, n + 1);
	preDFS(1), DFS(1);
	cout << dp[1] << endl;

	return 0;
}