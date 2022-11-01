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
 
# define A                                first
# define B                                second
# define endl                             '\n'
# define sep                              ' '
# define all(x)                           x.begin(), x.end()
# define Kill(x)                          return cout << x << endl, 0
# define SZ(x)                            int(x.size())
# define InTheNameOfGod                   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 1e6 + 10;
const int xm = -20 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

ll n, k[xn], w, ans[xn], part[xn], mx, seg[xn * 4], a[xn];
vector <ll> vec[xn];


void Build(int id, int L, int R){
	if (R - L == 1){
		seg[id] = a[L];
		return;
	}
	int Mid = (L + R) / 2;
	Build(id * 2, L, Mid);
	Build(id * 2 + 1, Mid, R);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
ll get(int id, int L, int R, int Ql, int Qr){
	if (Qr <= L || R <= Ql) return -INF;
	if (Ql <= L && R <= Qr) return seg[id];
	int Mid = (L + R) / 2;
	return max(get(id * 2, L, Mid, Ql, Qr), get(id * 2 + 1, Mid, R, Ql, Qr));
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> w;
	for (int i = 0; i < n; ++ i){
		cin >> k[i];
		vec[i].resize(k[i] + 1);
		for (int j = 1; j <= k[i]; ++ j) cin >> vec[i][j];
	}
	for (int i = 0; i < n; ++ i){
		if (w >= k[i] * 2){
			mx = 0;
			for (int j = 1; j <= k[i]; ++ j) mx = max(mx, vec[i][j]), ans[j] += mx;
			part[k[i] + 1] += mx;
			part[w - k[i] + 1] -= mx;
			mx = 0;
			for (int j = k[i]; j >= 1; -- j) mx = max(mx, vec[i][j]), ans[w - k[i] + j] += mx;
			continue;
		}
		a[0] = a[k[i] + 1] = 0;
		for (int j = 1; j <= k[i]; ++ j) a[j] = vec[i][j];
		Build(1, 0, k[i] + 2);
		for (ll j = 1; j <= w; ++ j){
			int R = min(k[i] + 1, j);
			int L = max(0LL, j - w + k[i]);
			ans[j] += get(1, 0, k[i] + 2, L, R + 1);
		}
	}
	for (int i = 1; i <= w; ++ i) part[i] += part[i - 1], ans[i] += part[i];
	for (int i = 1; i <= w; ++ i) cout << ans[i] << sep;
	cout << endl;
	
	return 0;
}