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
const int inf = 1e9 + 7, maxn = 3e5 + 500;
string s;
vector <int> v[maxn];
int dp[maxn][40], visited[maxn], p = 1;
bool cycle;

void dfs (int u, int asc){
	visited[u] = 1;
	if (s[u - 1] == asc + 'a')
		dp[u][asc] = 1;
	for (auto w : v[u]){
		if (!visited[w])
			dfs (w, asc);
		dp[u][asc] = max(dp[u][asc], dp[w][asc] + (s[u - 1] == asc + 'a'));
	}
}

void dfs1 (int u){
	visited[u] = 2;
	for (auto w : v[u]){
		if (visited[w]){
			if (visited[w] == 2)
				cycle = 1;
		}
		else
			dfs1 (w);
	}
	visited[u] = 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(w);
	}
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			dfs1 (i);
			p ++;
		}
	}
	if (cycle)
		return cout << -1 << endl, 0;
	int ans = -1;
	for (int i = 0; i < 26; i++){
		memset (visited, 0, sizeof visited);
		for (int j = 1; j <= n; j++){
			if (!visited[j])
				dfs (j, i);
			ans = max(ans, dp[j][i]);
		}
	}
	cout << ans << endl;
}