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
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int TM = 3;
const int base = 257;

ll n, m, seg[xn << 2], a[xn], mx[xn << 2];

void build(int id, int l, int r){
	if (r - l == 1){
		seg[id] = mx[id] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
	mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
}
void modify(int id, int l, int r, int pos, int val){
	if (r - l == 1){
		seg[id] = mx[id] = val;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid) modify(id << 1, l, mid, pos, val);
	else modify(id << 1 | 1, mid, r, pos, val);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
	mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
}
void update(int id, int l, int r, int ql, int qr, int val){
	if (qr <= l || r <= ql || mx[id] < val) return;
	if (r - l == 1){
		seg[id] %= val;
		mx[id] %= val;
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, val);
	update(id << 1 | 1, mid, r, ql, qr, val);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
	mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
}
ll get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql) return 0;
	if (ql <= l && r <= qr) return seg[id];
	int mid = l + r >> 1;
	return get(id << 1, l, mid, ql, qr) + get(id << 1 | 1, mid, r, ql, qr);
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    build(1, 1, n + 1);
    while (m --){
    	int t, l, r, x;
    	cin >> t;
    	if (t == 1){
    		cin >> l >> r;
    		cout << get(1, 1, n + 1, l, r + 1) << endl;
		}
		else if (t == 2){
			cin >> l >> r >> x;
			update(1, 1, n + 1, l, r + 1, x);
		}
		else{
			cin >> l >> r;
			modify(1, 1, n + 1, l, r);
		}
	}

    return 0;
}