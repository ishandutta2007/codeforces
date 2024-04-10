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
const int sq = 500 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 1e5;
const int BASE = 257;

int n, lazy[xn << 2], p[xn], a[xn];
ll ans;
pll seg[xn << 2];

void build(int id, int l, int r){
	seg[id].B = r - l;
	if (r - l == 1) return;
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
}
void shift(int id, int l, int r){
	if (!lazy[id]) return;
	seg[id].A += lazy[id];
	if (r - l > 1){
		lazy[id << 1] += lazy[id];
		lazy[id << 1 | 1] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, int val){
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
	seg[id].A = min(seg[id << 1].A, seg[id << 1 | 1].A);
	seg[id].B = 0;
	if (seg[id << 1].A == seg[id].A) seg[id].B += seg[id << 1].B;
	if (seg[id << 1 | 1].A == seg[id].A) seg[id].B += seg[id << 1 | 1].B;
}
int get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql) return 0;
	if (ql <= l && r <= qr){
		if (!seg[id].A) return seg[id].B;
		return 0;
	}
	int mid = l + r >> 1;
	return get(id << 1, l, mid, ql, qr) + get(id << 1 | 1, mid, r, ql, qr);
}

int main(){
    InTheNameOfGod;
    
    cin >> n;
    for (int i = 1; i <= n; ++ i){
    	int x, y;
    	cin >> x >> y;
    	a[x] = y;
	}
	build(1, 1, n + 1);
	for (int i = 1; i <= n; ++ i){
		update(1, 1, n + 1, 1, i, 1);
		update(1, 1, n + 1, 1, p[a[i] + 1] + 1, - 1);
		update(1, 1, n + 1, 1, p[a[i] - 1] + 1, - 1);
		p[a[i]] = i;
		ans += seg[1].B - n + i;
	}
	cout << ans << endl;
    
    return 0;
}