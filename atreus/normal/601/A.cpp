#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7, maxn = 5e2 + 500;
bool visited[maxn], mark[maxn];
int dp[maxn][2], n;
vector <int> v[maxn], g[maxn];

void bfs (){
	queue <int> q;
	q.push(1);
	dp[1][0] = 0;
	visited[1] = 1;
	while (!q.empty()){
		int u = q.front();
		for (auto w : v[u]){
			if (!visited[w]){
				dp[w][0] = dp[u][0] + 1;
				visited[w] = 1;
				q.push(w);
			}
		}
		q.pop();
	}
	memset (visited, 0, sizeof visited);
	q.push(1);
	dp[1][1] = 0;
	visited[1] = 1;
	while (!q.empty()){
		int u = q.front();
		for (auto w : g[u]){
			if (!visited[w]){
				dp[w][1] = dp[u][1] + 1;
				visited[w] = 1;
				q.push(w);
			}
		}
		q.pop();
	}
}

int main(){ // 0 --> red , 1 --> blue
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(w);
		v[w].PB(u);
	}
	for (int i = 1; i <= n; i++){
		memset (mark, 0, sizeof mark);
		for (int j = 0; j < v[i].size(); j++)
			mark[v[i][j]] = 1;
		for (int j = 1; j <= n; j++){
			if (j == i)
				continue;
			if (!mark[j])
				g[i].PB(j);
		}
	}
	memset (dp, -1, sizeof dp);
	bfs ();
	if (dp[n][0] == -1 || dp[n][1] == -1)
		return cout << -1 << endl, 0;
	cout << max(dp[n][0], dp[n][1]) << endl;
}