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
 
const int xn = 1e5 + 10;
const int xm = 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, q, a[xn], b[xn][xm], lazy[xn << 2][xm];
ll ans, pw[xm], seg[xn << 2][xm], res[xm];

void build(int id, int l, int r){
	for (int i = 0; i < xm; ++ i)
		lazy[id][i] = i;
	if (r - l == 1){
		for (int i = 0; i < 10; ++ i)
			if (b[l][i] != - 1)
				seg[id][b[l][i]] += pw[i];
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	for (int i = 0; i < 10; ++ i)
		seg[id][i] = seg[id << 1][i] + seg[id << 1 | 1][i];
}
void shift(int id, int l, int r){
	for (int i = 0; i < 10; ++ i)
		res[i] = seg[id][i], seg[id][i] = 0;
	for (int i = 0; i < 10; ++ i)
		seg[id][lazy[id][i]] += res[i];
	if (r - l > 1){
		for (int i = 0; i < 10; ++ i){
			lazy[id << 1][i] = lazy[id][lazy[id << 1][i]];
			lazy[id << 1 | 1][i] = lazy[id][lazy[id << 1 | 1][i]];
		}
	}
	for (int i = 0; i < 10; ++ i)
		lazy[id][i] = i;
}
void update(int id, int l, int r, int ql, int qr, int x, int y){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return;
	if (ql <= l && r <= qr){
		for (int i = 0; i < 10; ++ i)
			if (lazy[id][i] == x)
				lazy[id][i] = y;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, x, y);
	update(id << 1 | 1, mid, r, ql, qr, x, y);
	for (int i = 0; i < 10; ++ i)
		seg[id][i] = seg[id << 1][i] + seg[id << 1 | 1][i];
}
void get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return;
	if (ql <= l && r <= qr){
		for (ll i = 1; i < 10; ++ i)
			ans += i * seg[id][i];
		return;
	}
	int mid = l + r >> 1;
	get(id << 1, l, mid, ql, qr);
	get(id << 1 | 1, mid, r, ql, qr);
}

int main(){
    InTheNameOfGod;
    
    pw[0] = 1;
    for (int i = 1; i < xm; ++ i)
    	pw[i] = pw[i - 1] * 10LL;
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i){
    	cin >> a[i];
    	int ptr = 0;
    	while (a[i]){
    		b[i][ptr ++] = a[i] % 10;
    		a[i] /= 10;
		}
		while (ptr < xm)
			b[i][ptr ++] = - 1;
	}
	build(1, 1, n + 1);
	while (q --){
		int t, l, r, x, y;
		cin >> t >> l >> r;
		if (t == 1){
			cin >> x >> y;
			if (x == y) continue;
			update(1, 1, n + 1, l, r + 1, x, y);
		}
		else{
			ans = 0;
			get(1, 1, n + 1, l, r + 1);
			cout << ans << endl;
		}
	}

    return 0;
}