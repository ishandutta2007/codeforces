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
typedef pair <pii, ll>                                  ppi;
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
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int TM = 3;
const int base = 257;

ll n, m, a[xn], lazy[xn << 2];
ppi seg[xn << 2], tohi = {{INF, INF}, 0};

ppi merge(ppi x, ppi y, int l, int r, int mid){
	ppi z;
	y.A.A -= x.B;
	y.A.B += x.B;
	if ((r - mid) % 2) y.B -= x.B;
	else y.B += x.B;
	z.A = x.A;
	if ((mid - l) % 2){
		z.A.A = min(z.A.A, y.A.B);
		z.A.B = min(z.A.B, y.A.A);
	}
	else{
		z.A.A = min(z.A.A, y.A.A);
		z.A.B = min(z.A.B, y.A.B);
	}
	z.B = y.B;
	return z;
}
void build(int id, int l, int r){
	if (r - l == 1){
		seg[id].A.B = INF;
		seg[id].B = seg[id].A.A = a[l] - 1;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1], l, r, mid);
}
void shift(int id, int l, int r){
	if (!lazy[id]) return;
	seg[id].A.A += lazy[id];
	if ((r - l) % 2) seg[id].B += lazy[id];
	if (r - l > 1){
		lazy[id << 1] += lazy[id];
		lazy[id << 1 | 1] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, ll val){
	shift(id, l, r);
	if (qr <= l || r <= ql) return;
	if (ql <= l && r <= qr){
		lazy[id] += val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, val);
	update(id << 1 | 1, mid, r, ql, qr, val);
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1], l, r, mid);
}
ppi get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql) return tohi;
	if (ql <= l && r <= qr) return seg[id];
	int mid = l + r >> 1;
	int L = max(l, ql);
	int R = min(r, qr);
	ppi x = get(id << 1, l, mid, ql, qr);
	ppi y = get(id << 1 | 1, mid, r, ql, qr);
	if (qr < mid) return x;
	if (ql > mid) return y;
	return merge(x, y, L, R, mid);
}

int main(){
    InTheNameOfGod;
    
    cin >> n;
    for (int i = 0; i < n; ++ i) cin >> a[i];
    build(1, 0, n);
    cin >> m;
    while (m --){
    	int t, l, r, x;
    	cin >> t >> l >> r;
    	if (t == 1){
    		cin >> x;
    		update(1, 0, n, l, r + 1, x);
		}
		else{
			ppi y = get(1, 0, n, l, r + 1);
			cout << bool(!y.B && y.A.A >= 0 && y.A.B >= 0) << endl;
		}
	}

    return 0;
}