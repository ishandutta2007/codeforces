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
 
const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, a[xn], seg[xn << 2], ans[xn], q;
pii part[xn];
vector <int> adj[xn], adj2[xn];
vector <pii> vec[2][xn];
bool isp[xn];

void build(int id, int l, int r){
	seg[id] = 1;
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
}
void modify(int id, int l, int r, int pos, int val){
	if (r - l == 1){
		seg[id] = ll(seg[id]) * ll(val) % mod;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid) modify(id << 1, l, mid, pos, val);
	else modify(id << 1 | 1, mid, r, pos, val);
	seg[id] = ll(seg[id << 1]) * ll(seg[id << 1 | 1]) % mod;
}
int get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql)
		return 1;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return ll(get(id << 1, l, mid, ql, qr)) * ll(get(id << 1 | 1, mid, r, ql, qr)) % mod;
}

int main(){
    InTheNameOfGod;
    
	for (int i = 2; i < xn; ++ i){
		if (isp[i]) continue;
		adj[i].push_back(i);
		for (int j = i + i; j < xn; j += i)
			isp[j] = true, adj[j].push_back(i);
	}
	cin >> n;
	part[0] = {1, 1};
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		part[i].A = ll(part[i - 1].A) * ll(a[i]) % mod;
		part[i].B = power(part[i].A, mod - 2, mod);
	}
	for (int i = 1; i <= n; ++ i)
		for (int x : adj[a[i]])
			adj2[x].push_back(i);
	for (int i = 2; i < xn; ++ i){
		if (isp[i]) continue;
		int last = 0;
		int res = ll(i - 1) * power(i, mod - 2, mod) % mod;
		for (int ind : adj2[i])
			vec[1][last].push_back({ind, res}), last = ind;
	}
	cin >> q;
	for (int i = 1; i <= q; ++ i){
		int l, r;
		cin >> l >> r;
		vec[0][l].push_back({i, r});
		ans[i] = ll(part[r].A) * ll(part[l - 1].B) % mod;
	}
	build(1, 1, n + 1);
	for (int i = 0; i <= n; ++ i){
		for (pii x : vec[0][i])
			ans[x.A] = ll(ans[x.A]) * get(1, 1, n + 1, i, x.B + 1) % mod;
		for (pii x : vec[1][i])
			modify(1, 1, n + 1, x.A, x.B); 
	}
	for (int i = 1; i <= q; ++ i)
		cout << ans[i] << endl;

    return 0;
}