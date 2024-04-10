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
typedef pair <ll, ll>                                  pii;
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
 
const int xn = 1e5 + 10;
const int xm = 20 + 10;
const int SQ = 320;
const int sq = 500 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e14 + 10;
const int MOD = 1e9 + 7;
const int TM = 1e7;
const int BASE = 257;

int n, m, ptr, lazy[xn << 2];
ll seg[xn << 2], val[xn << 2], sum[xn << 2];

void build(int id, int l, int r){
	if (r - l == 1){
		val[id] = l;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
}
void shift(int id, int l, int r){
	if (!lazy[id]) return;
	val[id] = lazy[id];
	seg[id] += sum[id] * (r - l);
	if (r - l > 1){
		lazy[id << 1] = lazy[id];
		lazy[id << 1 | 1] = lazy[id];
		sum[id << 1] += sum[id];
		sum[id << 1 | 1] += sum[id];
	}
	sum[id] = lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, ll x){
	shift(id, l, r);
	if (qr <= l || r <= ql) return;
	if (ql <= l && r <= qr && val[id]){
		lazy[id] = x;
		sum[id] += abs(x - val[id]);
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, x);
	update(id << 1 | 1, mid, r, ql, qr, x);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
	if (val[id << 1] == val[id << 1 | 1]) val[id] = val[id << 1];
	else val[id] = 0;
}
ll get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql) return 0;
	if (ql <= l && r <= qr) return seg[id];
	int mid = l + r >> 1;
	return get(id << 1, l, mid, ql, qr) + get(id << 1 | 1, mid, r, ql, qr);
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> m;
    build(1, 1, n + 1);
    while (m --){
    	int t, l, r, x;
    	cin >> t >> l >> r;
    	if (t == 1){
    		cin >> x;
    		update(1, 1, n + 1, l, r + 1, x);
		}
		else cout << get(1, 1, n + 1, l, r + 1) << endl;
	}
    
    return 0;
}