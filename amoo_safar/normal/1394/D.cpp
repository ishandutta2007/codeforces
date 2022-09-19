// Zende bad Shoma nasime faghat !
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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll n;
ll ans = 0;
ll t[N], h[N];
ll di[N], dn[N];

ll dp[N][3];

vector<ll> G[N];

ll mk[N];

void DFS(ll u){
	mk[u] = 1;
	vector<ll> V;

	ll res = 0;
	for(auto adj : G[u]){
		if(mk[adj]) continue;
		DFS(adj);
		res += dp[adj][0];
		V.pb(dp[adj][2] - dp[adj][0]);
	}
	sort(all(V));
	int m = V.size();
	int din, dou;
	for(int i = 0; i <= m; i++){

		for(int j = 0; j < 3; j++){
			din = di[u] + (j == 0 ? 1 : 0) + i;
			dou = dn[u] + (j == 2 ? 1 : 0) + (m - i);
			dp[u][j] = min(dp[u][j], res + t[u] * max(din, dou));
		}

		if(i == m) break;
		res += V[i];
	}

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(dp, 31, sizeof dp);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> t[i];
	for(int i = 1; i <= n; i++) cin >> h[i];
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		if(h[u] > h[v]) swap(u, v);
		if(h[u] == h[v]){
			G[u].pb(v);
			G[v].pb(u);
		} else {
			di[v] ++;
			dn[u] ++;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		if(mk[i]) continue;
		DFS(i);

		ans += dp[i][1];
	}
	cout << ans << '\n';
	return 0;
}