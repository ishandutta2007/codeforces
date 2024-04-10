// har ki ro didi goft mikhad beshe meslemon !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll dp[N][N];

vector<pll> E;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	memset(dp, 31, sizeof dp);
	for(int i = 1; i <= n; i++) dp[i][i] = 0;
	int u, v, d;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> d;
		E.pb({u, v});
		if(d == 1){
			dp[u][v] = 1;
			dp[v][u] = -1;
		} else {
			dp[u][v] = 1;
			dp[v][u] = 1;
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				if(dp[i][j] <= -n)
					return cout << "NO\n", 0;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		if(dp[i][i] < 0)
			return cout << "NO\n", 0;

	int ans = -1, id = -1;
	for(int i = 1; i <= n; i++){
		ll mn = *min_element(dp[i] + 1, dp[i] + n + 1);
		if(mn < 0) continue;
		ll mx = *max_element(dp[i] + 1, dp[i] + n + 1);
		if(mx > ans){
			id = i;
			ans = mx;
		}
	}
	if(ans == -1) return cout << "NO\n", 0;
	for(auto X : E){
		ll zj = abs(dp[id][X.F] - dp[id][X.S]);
		if(zj % 2 == 0)
			return cout << "NO\n", 0;
	}
	cout << "YES\n" << ans << '\n';
	for(int i = 1; i <= n; i++) 
		cout << dp[id][i] << " \n"[i == n];
	return 0;
}