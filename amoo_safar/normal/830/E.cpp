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
const int N = 1e5 + 10;
const int Inf = 1e9;
const ll Log = 30;

int n, m;
vector<int> G[N];

int mk[N], sd;
void DFS(int u, int col){
	mk[u] = col;
	sd -= 2;
	sd += G[u].size();
	for(auto adj : G[u]) if(!mk[adj]) DFS(adj, col);
}
bool Cycle(){
	fill(mk, mk + n + 1, 0);
	int c = 1;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!mk[i]){
			sd = 0;
			DFS(i, c++);
			cnt ++;
			if(sd >= 0){
				cout << "YES\n";
				for(int j = 1; j <= n; j++) cout << (mk[j] == c - 1 ? 1 : 0) << ' ';
				cout << '\n';
				return true;
			}
		}
	}
	return false;
}

int ans[N];
const int K = 7;
int dp[N][K];
void dfs(int u){
	mk[u] = 1;
	for(int i = 1; i < K; i++) dp[u][i] = -(i*i);
	int mx;
	for(auto adj : G[u]){
		if(mk[adj]) continue;
		dfs(adj);
		for(int k = 1; k < K; k++){
			mx = -Inf;
			for(int k2 = 1; k2 < K; k2 ++)
				mx = max(mx, dp[adj][k2] + k2 * k);
			dp[u][k] += mx;
		}
	}
}

void Set(int u, int x){
	ans[u] = x;
	int mx;
	for(auto adj : G[u]){
		if(ans[adj]) continue;
		mx = 1;
		for(int k = 2; k < K; k++){
			if(dp[adj][k] + x * k > dp[adj][mx] + x * mx) mx = k;
		}
		Set(adj, mx);
	}
}

void Reset(){
	for(int i = 1; i <= n; i++) G[i].clear();
}
void Main(){
	cin >> n >> m;
	Reset();
	
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	if(Cycle()) return ;
	fill(mk + 1, mk + n + 1, 0);
	fill(ans + 1, ans + n + 1, 0);
	for(int i = 1; i <= n; i++){
		if(mk[i]) continue;
		dfs(i);
		for(int k = 1; k < K; k++) if(dp[i][k] >= 0){
			Set(i, k);
			cout << "YES\n";
			for(int j = 1; j <= n; j++) cout << ans[j] << ' ';
			cout << '\n';
			return ;
		}

	}
	cout << "NO\n";
	return ;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}