#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 50;
bool visited[maxn];
vector <int> g[maxn], v[maxn], myv[maxn];
int dp[maxn];

void bfs (int col){
	memset (dp, 63, sizeof dp);
	queue <int> q;
	for (auto j : g[col]){
		dp[j] = 0;
		visited[j] = 1;
		q.push(j);
	}
	while (!q.empty()){
		int u = q.front();
		q.pop();
		myv[u].PB (dp[u]);
		for (auto w : v[u]){
			if (!visited[w]){
				dp[w] = dp[u] + 1;
				visited[w] = 1;
				q.push(w);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, k, st;
	cin >> n >> m >> k >> st;
	for (int i = 1; i <= n; i++){
		int c;
		cin >> c;
		g[c].PB (i);
	}
	for (int i = 1; i <= m; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(w);
		v[w].PB(u);
	}
	for (int i = 1; i <= k; i++){
		bfs (i);
		memset (visited, 0, sizeof visited);
	}
	for (int i = 1; i <= n; i++){
		sort (myv[i].begin(), myv[i].end());
		ll ans = 0;
		for (int j = 0; j < st; j++)
			ans += myv[i][j];
		cout << ans << " ";
	}
}