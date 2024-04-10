#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <cmath>


using namespace std;

const int maxn = 1e5 + 100;
bool f[maxn], mark[maxn];
int dp[maxn];
vector <int> v[maxn];

void dfs (int u, int d){
	mark[u] = 1;
	dp[u] = f[u];
	for (int i = 0; i < v[u].size(); i++){
		int w = v[u][i];
		if (mark[w]){
			dp[u] = max(dp[u], dp[w]);
			if (f[w] == 0 and f[u] == 1){
				dp[u] = max(dp[u], dp[w] + 1);
			}
//			cout << '+' << " " << u << " " << w << " " << dp[w] << endl;
		}
		else {
			dfs (w, u);
			dp[u] = max(dp[u], dp[w]);
			if (f[w] == 0 and f[u] == 1)
				dp[u] = max(dp[u], dp[w] + 1);
//			cout << u << " " << w << " " << dp[w] << endl;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> f[i];
	for (int j = 0; j < m; j++){
		int u, w; 
		cin >> u >> w;
		v[w].push_back(u);
	}
	for (int i = 0; i < n; i++){
		if (!mark[i])
			dfs (i, -1);
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}