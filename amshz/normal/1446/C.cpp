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
 
const int xn = 2e5 + 10;
const int xm = 23 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, ptr = 1, a[xn], sz[xn * xm], ans = inf;
pii col[xn * xm], c[xn * xm];

void add(int val, int bit = 32, int id = 1){
	++ sz[id];
	if (!bit)
		return;
	if ((val & (1 << (bit - 1))) > 0){
		if (!col[id].B)
			col[id].B = ++ ptr;
		add(val, bit - 1, col[id].B);
		c[id].B = sz[col[id].B] - 1;
	}
	else{
		if (!col[id].A)
			col[id].A = ++ ptr;
		add(val, bit - 1, col[id].A);
		c[id].A = sz[col[id].A] - 1;
	}
}
void solve(int bit = 32, int id = 1, int res = 0){
	if (!bit){
		ans = min(ans, res);
		return;
	}
	if (col[id].A)
		solve(bit - 1, col[id].A, res + c[id].B);
	if (col[id].B)
		solve(bit - 1, col[id].B, res + c[id].A);
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], add(a[i]);
	solve();
	cout << ans << endl;
	
	return 0;
}