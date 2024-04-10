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

const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, m, ans[xn], ptr, res, par[xn], sz[xn];
ppp E[xn];
vector <int> seg[xn << 2], his[20];

int get_root(int v){
	if (v == par[v])
		return v;
	return get_root(par[v]);
}
void merge(int v, int u, int id){
	v = get_root(v);
	u = get_root(u);
	if (v == u)
		return;
	if (sz[v] < sz[u])
		swap(v, u);
	if (sz[v] % 2 && sz[u] % 2)
		res -= 2;
	sz[v] += sz[u];
	par[u] = v;
	his[id].push_back(u);
}
void update(int id, int l, int r, int ql, int qr, int val){
	if (r <= ql || qr <= l || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		seg[id].push_back(val);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr, val);
	update(rc, mid, r, ql, qr, val);
}
void build(int id, int l, int r, int h = 0){
	for (int ind : seg[id])
		merge(E[ind].B.A, E[ind].B.B, h);
	if (r - l == 1){
		while (ptr < m && res){
			++ ptr;
			if (l < E[ptr].A.B)
				continue;
			merge(E[ptr].B.A, E[ptr].B.B, h);
			update(1, 1, m + 1, E[ptr].A.B, l, ptr);
		}
		if (res)
			ans[l] = - 1;
		else
			ans[l] = E[ptr].A.A;
	}
	else{
		int mid = l + r >> 1;
		build(rc, mid, r, h + 1);
		build(lc, l, mid, h + 1);
	}
	while (SZ(his[h])){
		int u = his[h].back(), v = par[u];
		his[h].pop_back();
		sz[v] -= sz[u];
		if (sz[v] % 2 && sz[u] % 2)
			res += 2;
		par[u] = u;
	}
}

int main(){
	fast_io;

	for (int i = 0; i < xn; ++ i)
		par[i] = i, sz[i] = 1;
	cin >> n >> m, res = n;
	for (int i = 1; i <= m; ++ i)
		cin >> E[i].B.A >> E[i].B.B >> E[i].A.A, E[i].A.B = i;
	sort(E + 1, E + m + 1);
	build(1, 1, m + 1);
	for (int i = 1; i <= m; ++ i)
		cout << ans[i] << endl;

	return 0;
}