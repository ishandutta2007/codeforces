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
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll n, q, a[xn], c[xn], dp[xn], x, y;
int mx1, mx2;

void add(int ind){
	if (mx1 == ind)
		return;
	if (dp[ind] < dp[mx2])
		return;
	mx2 = ind;
	if (dp[mx2] > dp[mx1])
		swap(mx1, mx2);
}
void check(){
	for (int i = 1; i <= n; ++ i)
		dp[i] = - INF;
	mx1 = 0, mx2 = 1;
	for (int i = 1; i <= n; ++ i){
		dp[c[i]] = max(dp[c[i]], dp[c[i]] + a[i] * x);
		if (mx1 != c[i]) dp[c[i]] = max(dp[c[i]], dp[mx1] + a[i] * y);
		if (mx2 != c[i]) dp[c[i]] = max(dp[c[i]], dp[mx2] + a[i] * y);
		add(c[i]);
	}
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 1; i <= n; ++ i)
		cin >> c[i];
	while (q --){
		cin >> x >> y;
		check();
		cout << dp[mx1] << endl;
	}
			
	return 0;
}