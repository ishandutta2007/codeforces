#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <set>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, maxn = 1e5 + 100;
vector <int> v[maxn];
ll a[maxn], dp[maxn][2];
bool visited[maxn];

void dfs (int u){
	visited[u] = 1;
	if (v[u].size() == 1 and u != 1){ // if (leaf[u] == true)
		dp[u][1] = max(0ll, -a[u]);
		dp[u][0] = max(0ll, a[u]);
//		cout << u << " " << dp[u][1] << " " << dp[u][0] << endl;
		return;
	}
	for (auto w : v[u]){
		if (!visited[w]){
			dfs (w);
			dp[u][1] = max(dp[u][1], dp[w][1]);
			dp[u][0] = max(dp[u][0], dp[w][0]);
		}
	}
	ll k = dp[u][1] - dp[u][0];
	a[u] += k;
	dp[u][1] += max(0ll, -a[u]);
	dp[u][0] += max(0ll, a[u]);
//	cout << u << " " << dp[u][1] << " " << dp[u][0] << endl;
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(w);
		v[w].PB(u);
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs (1);
	cout << dp[1][0] + dp[1][1] << endl;
}