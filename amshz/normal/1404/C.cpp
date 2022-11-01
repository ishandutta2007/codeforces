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
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int TM = 3;
const int base = 257;

int n, q, a[xn], mn[xn << 2], seg[xn << 2], lazy[xn << 2], mx[xn << 2], ans[xn];
vector <pii> Q[xn];

void shift(int id, int l, int r){
	if (!lazy[id]) return;
	seg[id] += lazy[id];
	mn[id] += lazy[id];
	mx[id] += lazy[id];
	if (r - l > 1){
		lazy[id << 1] += lazy[id];
		lazy[id << 1 | 1] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql) return;
	if (ql <= l && r <= qr && mn[id] >= val){
		++ lazy[id];
		shift(id, l, r);
		return;
	}
	if (mx[id] < val) return;
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, val);
	update(id << 1 | 1, mid, r, ql, qr, val);
	mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
	mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
}
int get(int id, int l, int r, int pos){
	shift(id, l, r);
	if (r - l == 1) return seg[id];
	int mid = l + r >> 1;
	if (pos < mid) return get(id << 1, l, mid, pos);
	return get(id << 1 | 1, mid, r, pos);
}

int main(){
    InTheNameOfGod;
    
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	for (int i = 1; i <= q; ++ i){
		int x, y;
		cin >> x >> y;
		Q[n - y].push_back({x, i});
	}
	for (int i = 1; i <= n; ++ i){
		if (a[i] <= i) update(1, 0, n, 0, i, i - a[i]);
		for (pii x : Q[i]) ans[x.B] = get(1, 0, n, x.A);
	}
	for (int i = 1; i <= q; ++ i) cout << ans[i] << endl;
 
    return 0;
}