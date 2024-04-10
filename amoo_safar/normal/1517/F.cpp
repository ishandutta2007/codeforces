// vaziat meshki-ghermeze !
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

const ll Mod = 998244353ll;
const int N = 3e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<int> G[N];
ll mul(ll a, ll b){
	return (a * b) % Mod;
}
ll dp[N][N][2];
ll tmp[N][2];
int x;
int DFS(int u, int p){
	dp[u][x][0] = 1;
	dp[u][0][1] = 1;
	int sz = 1;
	vector<pll> A, B;
	for(auto adj : G[u]){
		if(adj == p) continue;
		int rs = DFS(adj, u);
		int nx = rs + sz;
		
		for(int i = 0; i <= nx; i++) tmp[i][1] = 0;
		for(int i = 0; i <= min(x, nx); i++) tmp[x - i][0] = 0;
		
		A.clear(); B.clear();
		for(int y = x; y >= x - sz && y >= 0; y--) A.pb({y, 0});
		for(int y = 0; y <= sz; y++) A.pb({y, 1});
		
		for(int y = x; y >= x - rs && y >= 0; y--) B.pb({y, 0});
		for(int y = 0; y <= rs; y++) B.pb({y, 1});

		for(auto [x1, x2] : A){
			for(auto [y1, y2] : B){
				ll cnt = mul(dp[u][x1][x2], dp[adj][y1][y2]);
				// if(cnt) debug(cnt);
				if(y2 == 1) y1 ++;
				else y1 --;
				// if(y1 < 0) continue;
				pll nx = max(pll(x1, -x2), pll(y1, -y2));
				nx.S = -nx.S;
				if(cnt){
					// cerr << "^^ " << nx.F << ' ' << nx.S << '\n';
				}
				(tmp[nx.F][nx.S] += cnt) %= Mod;
			}
		}
		nx = sz + rs;
		for(int i = 0; i <= nx; i++) dp[u][i][1] = tmp[i][1];
		for(int i = 0; i <= min(x, nx); i++) dp[u][x - i][0] = tmp[x - i][0];
		sz += rs;
	}
	// cerr << "! " << u << ' ' << sz << '\n';
	return sz;
}
ll ans[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	ll sum = 0;
	for(int i = 0; i <= n; i++){
		memset(dp, 0, sizeof dp);
		x = i;
		DFS(1, -1);
		for(int j = 0; j < N; j++)
			ans[i] += dp[1][j][0]; 
		ans[i] %= Mod;
	}
	for(int i = 0; i <= n; i++){
		// debug(ans[i]);
		for(int j = 0; j < i; j++)
			ans[i] -= ans[j];
		ans[i] %= Mod;
		// debug(ans[i]);
		sum += mul( ( i == n ? n : (i - 1) ), ans[i]);
		sum %= Mod;
	}
	// debug(sum);
	// sum --;
	sum += n;
	sum += Mod;
	sum %= Mod;
	ll iv2 = (Mod + 1) / 2;
	for(int i = 0; i < n; i++) sum = mul(sum, iv2);
		cout << sum << '\n';
	return 0;
}