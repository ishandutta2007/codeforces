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
typedef pair <ll, ll>                                    pll;
typedef pair <pll, ll >                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
 
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
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll n, m, k, ptr, seg[xn << 2], lazy[xn << 2], ans = - INF;
pll a[xn], b[xn];
ppi c[xn];

void build(int id, int l, int r){
	if (r - l == 1){
		seg[id] = - b[l].B;
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	seg[id] = max(seg[lc], seg[rc]);
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	seg[id] += lazy[id];
	if (r - l > 1){
		lazy[lc] += lazy[id];
		lazy[rc] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, ll val){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] += val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr, val);
	update(rc, mid, r, ql, qr, val);
	seg[id] = max(seg[lc], seg[rc]);
}
void add(int ind){
	int l = 0, r = m + 1;
	while (r - l > 1){
		int mid = l + r >> 1;
		if (b[mid].A <= c[ind].A.B)
			l = mid;
		else
			r = mid;
	}
	update(1, 1, m + 1, r, m + 1, c[ind].B);
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].A >> a[i].B;
	for (int i = 1; i <= m; ++ i)
		cin >> b[i].A >> b[i].B;
	for (int i = 1; i <= k; ++ i)
		cin >> c[i].A.A >> c[i].A.B >> c[i].B;
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	sort(c + 1, c + k + 1);
	build(1, 1, m + 1);
	for (int i = 1; i <= n; ++ i){
		while (ptr < k && c[ptr + 1].A.A < a[i].A)
			add(++ ptr);
		ans = max(ans, seg[1] - a[i].B);
	}
	cout << ans << endl;
			
	return 0;
}