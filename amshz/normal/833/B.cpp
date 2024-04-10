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
const int xn = 35e3 + 10;
const int xm = 5e1 + 10;
const int SQ = 320;
const int sq = SQ + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";


int n, k, num[xn], last[xn], seg[xn << 2], lazy[xn << 2], dp[xn];

void Build(int id, int L, int R){
	lazy[id] = 0;
	if (R - L == 1){
		seg[id] = dp[L];
		return;
	}
	int Mid = (L + R) / 2;
	Build(id << 1, L, Mid);
	Build(id << 1 | 1, Mid, R);
	seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}
void Shift(int id, int L, int R){
	if (!lazy[id]) return;
	seg[id] += lazy[id];
	if (R - L > 1){
		lazy[id << 1] += lazy[id];
		lazy[id << 1 | 1] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int L, int R, int Ql, int Qr, int val){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return;
	if (Ql <= L && R <= Qr){
		lazy[id] += val;
		Shift(id, L, R);
		return;
	}
	int Mid = (L + R) / 2;
	update(id << 1, L, Mid, Ql, Qr, val);
	update(id << 1 | 1, Mid, R, Ql, Qr, val);
	seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}
int get(int id, int L, int R, int Ql, int Qr){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return 0;
	if (Ql <= L && R <= Qr) return seg[id];
	int Mid = (L + R) / 2;
	return max(get(id << 1, L, Mid, Ql, Qr), get(id << 1 | 1, Mid, R, Ql, Qr));
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) cin >> num[i];
	while (k --){
		memset(last, 0, sizeof last);
		Build(1, 0, xn);
		for (int i = 1; i <= n; ++ i){
			update(1, 0, xn, last[num[i]], i, 1);
			dp[i] = get(1, 0, xn, 0, i);
			last[num[i]] = i;
		}
	}
	cout << dp[n] << endl;
	
	return 0;
}