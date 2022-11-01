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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int m, n, par[xn], sz[xn], t[xn], ptr, res;
pii a[xn], b[xn];
set <pii> seg[xn << 2];
vector <pip> compress;
vector <int> vec;

int get_root(int v){
	if (v == par[v])
		return v;
	return par[v] = get_root(par[v]);
}
void merge(int v, int u){
	v = get_root(v);
	u = get_root(u);
	if (v == u)
		return;
	if (sz[v] < sz[u])
		swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
	b[v].A = min(b[v].A, b[u].A);
	b[v].B = max(b[v].B, b[u].B);
}
void get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql)
	 	return;
	if (ql <= l && r <= qr){
		for (pii x : seg[id]){
			if (x.A >= ql - 1)
				break;
			vec.push_back(x.B);
		}
		return;
	}
	int mid = l + r >> 1;
	get(id << 1, l, mid, ql, qr);
	get(id << 1 | 1, mid, r, ql, qr);
}
void modify(int id, int l, int r, int pos, int v, bool fl){
	if (fl) seg[id].insert({b[v].A, v});
	else seg[id].erase({b[v].A, v});
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	if (pos < mid)
		modify(id << 1, l, mid, pos, v, fl);
	else
		modify(id << 1 | 1, mid, r, pos, v, fl);
}

int main(){
	InTheNameOfGod;
	
	cin >> m;
	for (int i = 0; i < m; ++ i){
		cin >> t[i] >> a[i].A >> a[i].B;
		if (t[i] == 1){
			compress.push_back({a[i].A, {i, 1}});
			compress.push_back({a[i].B, {i, 0}});
		}
	}
	sort(all(compress));
	for (int i = 0; i < SZ(compress); ++ i){
		if (!i || compress[i].A != compress[i - 1].A) ++ ptr;
		if (compress[i].B.B) a[compress[i].B.A].A = ptr;
		else a[compress[i].B.A].B = ptr;
	}
	for (int i = 0; i < m; ++ i){
		if (t[i] == 1){
			++ n, vec.clear();
			b[n] = a[i], sz[n] = 1;
			par[n] = res = n;
			get(1, 1, ptr + 1, b[n].A + 1, b[n].B + 1);
			get(1, 1, ptr + 1, b[n].B + 1, ptr + 1);
			for (int x : vec){
				modify(1, 1, ptr + 1, b[x].B, x, 0);
				merge(res, x);
				res = get_root(res);
			}
			modify(1, 1, ptr + 1, b[res].B, res, 1);
		}
		else{
			int v = get_root(a[i].A);
			int u = get_root(a[i].B);
			if (v == u || (b[u].A < b[v].A && b[v].A < b[u].B) || (b[u].A < b[v].B && b[v].B < b[u].B))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	
	return 0;
}