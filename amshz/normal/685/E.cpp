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
const int xm = 2e5 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod = 1e9 + 7;
const int base = 257;

int n, m, a[xm], b[xm], dp[xn][xn], ql[xm], qr[xm], s[xm], t[xm], q;
vector <int> Q[xm];
bool ans[xm];

int main(){
    InTheNameOfGod;
    
    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++ i) cin >> a[i] >> b[i];
    for (int i = 1; i <= q; ++ i){
    	cin >> ql[i] >> qr[i] >> s[i] >> t[i];
    	Q[qr[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++ i) dp[i][i] = inf;
	for (int i = 1; i <= m; ++ i){
		for (int j = 1; j <= n; ++ j) dp[j][a[i]] = dp[j][b[i]] = max(dp[j][a[i]], dp[j][b[i]]);
		dp[a[i]][b[i]] = dp[b[i]][a[i]] = i;
		for (int x : Q[i]) ans[x] = (dp[s[x]][t[x]] >= ql[x]);
	}
	for (int i = 1; i <= q; ++ i){
		if (ans[i]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
    return 0;
}