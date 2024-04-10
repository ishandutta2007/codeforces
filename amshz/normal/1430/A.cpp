# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, qq, par[xn], ans[3];
bool dp[xn];

int main(){
    InTheNameOfGod;
    
    dp[0] = true;
    for (int i = 1; i < xn; ++ i){
    	if (i >= 3 && dp[i - 3]){
    		dp[i] = true;
    		par[i] = 0;
		}
		if (i >= 5 && dp[i - 5]){
			dp[i] = true;
			par[i] = 1;
		}
		if (i >= 7 && dp[i - 7]){
			dp[i] = true;
			par[i] = 2;
		}
	}
	cin >> qq;
	while (qq --){
		cin >> n;
		if (!dp[n]){
			cout << - 1 << endl;
			continue;
		}
		int res = n;
		ans[0] = ans[1] = ans[2] = 0;
		while (res){
			++ ans[par[res]];
			if (par[res] == 0) res -= 3;
			else if (par[res] == 1) res -= 5;
			else res -= 7;
		}
		cout << ans[0] << sep << ans[1] << sep << ans[2] << endl;
	}
	
    return 0;
}