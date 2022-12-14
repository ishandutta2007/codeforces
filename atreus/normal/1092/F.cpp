#include <bits/stdc++.h>
#include <chrono>
#include <random>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;

ll sum, dp[maxn], sz[maxn];

ll ans = 0;

vector <int> t[maxn];

ll a[maxn];

void dfs_down(int v, int par = -1){
	if (par != -1){
		dp[v] = dp[par] - 2 * sz[v] + sum;
	}
	ans = max(ans, dp[v]);
	for (auto u : t[v]){
		if (u != par){
			dfs_down(u, v);
		}
	}
}

void dfs_up(int v, int par = -1){
	sz[v] = a[v];
	for (auto u : t[v]){
		if (u != par){
			dfs_up(u, v);
			sz[v] += sz[u];
			dp[v] += dp[u] + sz[u];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); 
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs_up(1);
	dfs_down(1);
	cout << ans << endl;
}