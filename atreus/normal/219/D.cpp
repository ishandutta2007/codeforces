#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, maxn = 2e5 + 100;
vector <pair <int, bool> > v[maxn];
ll dp[maxn][2];
pair <ll, ll> cost[maxn];
bool visited[maxn];

void dfs_up(int u, int par, int uni){
	visited[u] = 1;
	if (par != -1){
		if (uni == 0)
			uni = -1;
		dp[u][1] = dp[par][1] + dp[par][0] - dp[u][0] + uni;
	}
	for (int i = 0; i < v[u].size(); i++){
		int w = v[u][i].F;
		if (!visited[w])
			dfs_up (w, u, (v[u][i].S));
	}
}

void dfs_down(int u){
	visited[u] = 1;
	for (int i = 0; i < v[u].size(); i++){
		int w = v[u][i].F;
		if (!visited[w]){
			dfs_down (w);
			dp[u][0] += dp[w][0] + (v[u][i].S ^ 1);
		}
	}
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(MP(w, 1));
		v[w].PB(MP(u, 0));
	}
	dfs_down (1);
	memset (visited, 0, sizeof visited);
	dfs_up(1, -1, 0);
	for (int i = 1; i <= n; i++){
		cost[i].F = dp[i][0] + dp[i][1];
		cost[i].S = i;
	}
	sort (cost + 1, cost + n + 1);
	cout << cost[1].F << endl;
	for (int i = 1; i <= n; i++){
		cout << cost[i].S << " ";
		if (cost[i + 1].F != cost[i].F)
			break;
	}
}