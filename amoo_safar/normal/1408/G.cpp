// That's How much we have in common
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

const ll Mod = 998244353;
const int N = 1500 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll dis[N][N];
ll n;

vector<ll> C[N];
ll dp[N][N], tmp[N];

ll com[N], mx[N];
vector< pair<ll, pll> > E;

ll mul(ll a, ll b){
	return (a * b) % Mod;
}
void Unite(int u, int v, ll w){
	u = com[u]; v = com[v];
	//cerr << u << ' ' << v << ' ' << w << '\n';
	if(u > v) swap(u, v);
	// u < v;
	if(w > mx[u]) dp[u][1] ++;
	if(w > mx[v]) dp[v][1] ++;
	
	memset(tmp, 0, sizeof tmp);
	for(int i = 1; i <= (int) C[u].size(); i++){
		for(int j = 1; j <= (int) C[v].size(); j++){
			tmp[i + j] = (tmp[i + j] + mul(dp[u][i], dp[v][j])) % Mod;
		}
	}
	for(int i = 1; i <= (int)(C[u].size() + C[v].size()); i++)
		dp[u][i] = tmp[i];
	//cerr << dp[u][C[u].size() + C[v].size()] << '\n';
	mx[u] = max(mx[u], mx[v]);
	for(auto x : C[u])
		for(auto y : C[v])
			mx[u] = max(mx[u], dis[x][y]);

	for(auto x : C[v]){
		C[u].pb(x);
		com[x] = u;
	}
	C[v].clear();
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	scanf("%lld", &n);
	ll v;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%lld", &v);
			dis[i][j] = v;
			E.pb({v, {i, j}});
		}
		C[i] = {i};
		mx[i] = 0;
		com[i] = i;
		//dp[i][1] = 1;
	}
	sort(all(E));
	for(auto [w, e] : E){
		if(com[e.F] == com[e.S]) continue;
		Unite(e.F, e.S, w);
	}
	dp[1][1] ++;
	for(int i = 1; i <= n; i++) cout << dp[1][i] % Mod << " \n"[i == n];
	return 0;
}