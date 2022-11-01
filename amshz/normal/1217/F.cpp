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

const int xn = 2e5 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 1e7 + 19;

int n, m, par[xn], sz[xn], a[xn], last, ans[xn];
pii E[xn];
set <pii> st;
bool flag[xn], flg;
map <int, int> mp[xn], lst[xn];
vector <ppp> seg[xn << 2];
vector <pii> his[20];

void update(int id, int l, int r, int ql, int qr, int v, int u, int ind){
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		seg[id].push_back({{v, u}, {ind, flg}});
		flg = false;
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr, v, u, ind);
	update(rc, mid, r, ql, qr, v, u, ind);
}
int get_root(int v){
	if (v == par[v])
		return v;
	return get_root(par[v]);
}
void merge(int v, int u, int h){
	v = get_root(v);
	u = get_root(u);
	if (v == u)
		return;
	if (sz[v] < sz[u])
		swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
	his[h].push_back({v, u});
}
void DFS(int id, int l, int r, int h = 0){
	for (ppp x : seg[id]){
		int v = x.A.A, u = x.A.B, ind = x.B.A;
		flg = x.B.B;
		bool fl = (E[ind].A != v || E[ind].B != u);
		mp[v][u] ^= bool(flg && ans[a[ind]] == fl);
		if (mp[v][u])
			merge(v, u, h);
	}
	if (r - l == 1 && flag[l]){
		int v = E[l].A, u = E[l].B;
		if (ans[a[l]])
			v = v % n + 1, u = u % n + 1;
		ans[l] = get_root(v) == get_root(u);
		cout << ans[l];
	}
	if (r - l > 1){
		int mid = l + r >> 1;
		DFS(lc, l, mid, h + 1);
		DFS(rc, mid, r, h + 1);
	}
	while (SZ(his[h])){
		pii x = his[h].back();
		his[h].pop_back();
		int v = x.A, u = x.B;
		par[u] = u, sz[v] -= sz[u];
	}
}

int main(){
	InTheNameOfGod;

	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		par[i] = i, sz[i] = 1;
	if (n == 2){
		while (m --){
			int t, v, u;
			cin >> t >> v >> u;
			if (t == 1)
				last ^= 1;
			else
				cout << last;
		}
		cout << endl;
		return 0;
	}
	for (int i = 1; i <= m; ++ i){
		int t, v, u, vv, uu;
		cin >> t >> v >> u;
		vv = v % n + 1, uu = u % n + 1;
		if (v < u)
			swap(v, u);
		if (vv < uu)
			swap(vv, uu);
		E[i] = {v, u};
		a[i] = last;
		if (t == 1){
			st.insert({v, u});
			st.insert({vv, uu});
			flg = true;
			update(1, 1, m + 1, lst[v][u], i, v, u, lst[v][u]);
			flg = true;
			update(1, 1, m + 1, lst[vv][uu], i, vv, uu, lst[vv][uu]);
			lst[v][u] = lst[vv][uu] = i;
		}
		else
			last = i, flag[i] = true;
	}
	for (pii x : st)
		flg = true, update(1, 1, m + 1, lst[x.A][x.B], m + 1, x.A, x.B, lst[x.A][x.B]);
	DFS(1, 1, m + 1);
	cout << endl;

	return 0;
}