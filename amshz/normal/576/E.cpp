//khodaya khodet komak kon
# include <bits/stdc++.h>

/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/

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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 5e5 + 10;
const int xm = 51;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 1e7 + 19;

int n, m, k, q, col[xn], par[xm][xn], sz[xm][xn], last[xn];
pii E[xn], query[xn];
vector <int> seg[xn << 2];
vector <pip> his[30];
bool fl[xm][xn], fp[xm][xn];

void update(int id, int l, int r, int ql, int qr, int val){
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		seg[id].push_back(val);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr, val);
	update(rc, mid, r, ql, qr, val);
}
pii get_root(int v, int c){
	int w = fl[c][v];
	while (par[c][v] != v){
		w ^= fp[c][v];
		v = par[c][v];
		w ^= fl[c][v];
	}
	return {v, w};
}
void merge(int v, int u, int c, int h){
	int w = 1;
	pii x = get_root(v, c);
	pii y = get_root(u, c);
	v = x.A, w ^= x.B;
	u = y.A, w ^= y.B;
	if (v == u || !c)
		return;
	if (sz[c][v] < sz[c][u])
		swap(v, u);
	par[c][u] = v, fp[c][u] = w;
	sz[c][v] += sz[c][u];
	his[h].push_back({c, {v, u}});
}
bool check(int v, int u, int c){
	return (get_root(v, c) != get_root(u, c));
}
void DFS(int id, int l, int r, int h = 0){
	for (int ind : seg[id])
		merge(E[ind].A, E[ind].B, col[ind], h);
	if (r - l == 1){
		int ind = query[l].A, c = query[l].B;
		int v = E[ind].A, u = E[ind].B;
		if (check(v, u, c))
			cout << "YES" << endl, col[ind] = c;
		else
			cout << "NO" << endl;
	}
	else{
		int mid = l + r >> 1;
		DFS(lc, l, mid, h + 1);
		DFS(rc, mid, r, h + 1);
	}
	while (SZ(his[h])){
		pip x = his[h].back();
		int c = x.A, v = x.B.A, u = x.B.B;
		his[h].pop_back();
		par[c][u] = u;
		sz[c][v] -= sz[c][u];
	}
}

int main(){
	InTheNameOfGod;

	cin >> n >> m >> k >> q;
	for (int i = 1; i <= m; ++ i)
		cin >> E[i].A >> E[i].B;
	for (int i = 1; i <= k; ++ i)
		for (int v = 1; v <= n; ++ v)
			par[i][v] = v, sz[i][v] = 1;
	for (int i = 1; i <= q; ++ i){
		int x, y;
		cin >> x >> y;
		update(1, 1, q + 1, last[x] + 1, i, x);
		last[x] = i, query[i] = {x, y};
	}
	for (int i = 1; i <= m; ++ i)
		update(1, 1, q + 1, last[i] + 1, q + 1, i);
	DFS(1, 1, q + 1);

	return 0;
}