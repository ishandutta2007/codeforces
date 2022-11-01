# include <bits/stdc++.h>
 
using namespace std;
 
/*
// ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
typedef long long                         ll;
typedef long double                       ld;
typedef pair <int, int>                   pii;
typedef pair <pii, int>                   ppi;
typedef pair <pii, pii>                   pip;
typedef pair <ll, ll>                     pll;
 
# define A                                first
# define B                                second
# define endl                             '\n'
# define sep                              ' '
# define all(x)                           x.begin(), x.end()
# define Kill(x)                          return cout << x << endl, 0
# define SZ(x)                            int(x.size())
# define InTheNameOfGod                   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 2e5 + 10;
const int xm = 5e3 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int n, m;
ll num[xn], dp[xn], seg[xn * 4], lazy[xn * 4];
vector <pll> Q[xn];

void Shift(int id, int L, int R){
	if (lazy[id] == 0) return;
	seg[id] += lazy[id];
	if (R - L > 1){
		lazy[id * 2] += lazy[id];
		lazy[id * 2 + 1] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int L, int R, int Ql, int Qr, ll val){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return;
	if (Ql <= L && R <= Qr){
		lazy[id] += val;
		Shift(id, L, R);
		return;
	}
	int Mid = (L + R) / 2;
	update(id * 2, L, Mid, Ql, Qr, val);
	update(id * 2 + 1, Mid, R, Ql, Qr, val);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
ll get(int id, int L, int R, int Ql, int Qr){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return 0;
	if (Ql <= L && R <= Qr) return seg[id];
	int Mid = (L + R) / 2;
	return max(get(id * 2, L, Mid, Ql, Qr), get(id * 2 + 1, Mid, R, Ql, Qr));
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> num[i];
	for (int i = 0; i < m; ++ i){
		ll l, r, x;
		cin >> l >> r >> x;
		Q[r].push_back({l, x});
	}
	for (int i = 1; i <= n; ++ i){
		dp[i] = dp[i - 1];
		for (pll q : Q[i])
			update(1, 0, xn, 1, q.A + 1, q.B);
		update(1, 0, xn, 1, i + 1, - num[i]);
		update(1, 0, xn, i, i + 1, dp[i - 1]);
		dp[i] = max(dp[i], get(1, 0, xn, 1, i + 1));
	}
	cout << dp[n] << endl;
	
	return 0;
}