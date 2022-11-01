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
 
const int xn = 5e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod = 1e9 + 7;
const int base = 257;

ll n, s, e, x[xn], a[xn], b[xn], c[xn], d[xn], dp[2][xn];
bool f;

int main(){
    InTheNameOfGod;
    
    cin >> n >> s >> e;
    for (int i = 1; i <= n; ++ i) cin >> x[i];
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) cin >> b[i];
    for (int i = 1; i <= n; ++ i) cin >> c[i];
    for (int i = 1; i <= n; ++ i) cin >> d[i]; 
    for (int i = 1; i <= n; ++ i) dp[0][i] = dp[0][i] = INF;
    for (int i = 1; i <= n; ++ i){
    	f = i % 2;
    	dp[f][0] = dp[f][0] = INF;
    	for (int j = 1; j <= n; ++ j){
    		dp[f][j] = dp[f][j] = INF;
    		if (i == s){
    			dp[f][j] = min(dp[f][j], dp[!f][j - 1] + d[i] - x[i]);
    			if (e > s || j > 1 || i == n) dp[f][j] = min(dp[f][j], dp[!f][j] + c[i] + x[i]);
			}
			else if (i == e){
				dp[f][j] = min(dp[f][j], dp[!f][j - 1] + b[i] - x[i]);
				if (s > e || j > 1 || i == n) dp[f][j] = min(dp[f][j], dp[!f][j] + a[i] + x[i]);
			}
			else{
				dp[f][j] = min(dp[f][j], dp[!f][j - 1] + b[i] + d[i] - x[i] - x[i]);
				if (j > 1 || i < s) dp[f][j] = min(dp[f][j], dp[!f][j] + b[i] + c[i]);
				if (j > 1 || i < e) dp[f][j] = min(dp[f][j], dp[!f][j] + a[i] + d[i]);
				if (j > 1 || i < s || i < e || i == n) dp[f][j] = min(dp[f][j], dp[!f][j + 1] + a[i] + c[i] + x[i] + x[i]);
			}
		}
	}
	cout << dp[n % 2][1] << endl;
	
    return 0;
}