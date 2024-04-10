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
typedef pair <ll , ll >                                  pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;//998244353;
const int xn = 2e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = SQ + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 100 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 100 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

ll n, num[xn], pos[xn], ted, res, s;
ld ans;
pll seg[xn << 2], lazy[xn << 2], fen;

pll merge(pll a, pll b){
	pll c;
	c.A = a.A + b.A;
	c.B = a.B + b.B;
	return c;
}
void shift(int id, int l, int r){
	if (!lazy[id].A && !lazy[id].B) return;
	seg[id].A += lazy[id].A;
	seg[id].B += lazy[id].B;
	if (r - l > 1){
		lazy[id << 1].A += lazy[id].A;
		lazy[id << 1 | 1].A += lazy[id].A;
		lazy[id << 1].B += lazy[id].B;
		lazy[id << 1 | 1].B += lazy[id].B;
	}
	lazy[id].A = lazy[id].B = 0;
}
void update(int id, int l, int r, int ql, int qr, ll val){
	shift(id, l, r);
	if (qr <= l || r <= ql) return;
	if (ql <= l && r <= qr){
		++ lazy[id].A;
		lazy[id].B -= val + val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, val);
	update(id << 1 | 1, mid, r, ql, qr, val);
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}
pll get(int id, int l, int r, int p){
	shift(id, l, r);
	if (p + 1 <= l || r <= p) return {0, 0};
	if (p <= l && r <= p + 1) return seg[id];
	int mid = l + r >> 1;
	return merge(get(id << 1, l, mid, p), get(id << 1 | 1, mid, r, p));
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> num[i], pos[num[i]] = i;
	for (ll i = 1; i <= n; ++ i){
		fen = get(1, 0, xn, pos[i]);
		res += ((n - pos[i]) * (n - pos[i] + 1) / 2 + fen.B) * pos[i];
		ans += fen.A;
		update(1, 0, xn, 0, pos[i], n - pos[i] + 1);
	}
	ans += ld(res) / ld(ld(n) * ld(n + 1));
	cout << fixed << setprecision(15);
	cout << ans << endl;
	
	return 0;
}