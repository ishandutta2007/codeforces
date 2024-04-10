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
typedef pair <ld, ld>                                  pll;
 
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

//const ll md = 1e9 + 7;//998244353;
const int xn = 5e6 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int Md = 987654319;
const int Base = 257;
 
int n, PH[xn], pw[xn], inv[xn], dp[xn], ans, HASH[2][xn], INV;
bool flag[xn];
string s;

void Build(){
    for (int i = 1; i <= n; ++ i)
    	PH[i] = (PH[i - 1] + (int(s[i - 1]) * ll(pw[i]) % Md)) % Md;
}
int get(int l, int r){return (ll(ll(PH[r] - PH[l - 1] + Md) % Md) * ll(inv[l - 1])) % Md;}

int main(){
    InTheNameOfGod;
    
    cin >> s;
    n = SZ(s);
    INV = power(Base, Md - 2, Md);
    pw[0] = inv[0] = 1;
    for (int i = 1; i <= n; ++ i){
    	pw[i] = ll(pw[i - 1]) * Base % Md;
    	inv[i] = ll(inv[i - 1]) * ll(INV) % Md;
	}
    Build();
    for (int i = 1; i <= n; ++ i)	HASH[0][i] = get(1, i);
    reverse(all(s));
    Build();
    for (int i = 1; i <= n; ++ i)	HASH[1][i] = get(n - i + 1, n);
	for (int i = 1; i <= n; ++ i){
		flag[i] = true;
		for (int j = 0; j < 1; ++ j)	flag[i] &= HASH[0][i] == HASH[1][i];
	}
    for (int i = 1; i <= n; ++ i){
    	if (flag[i])	dp[i] = dp[i / 2] + 1;
    	ans += dp[i];
	}
	cout << ans << endl;
    
    return 0;
}