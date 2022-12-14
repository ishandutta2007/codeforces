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
const ll mod = 1e9 + 7, maxn = 2e5 + 100;
vector <pair <int, int> > v[maxn];
bool visited[maxn];
long long dp[maxn][2];

void dfs (int u){
	visited[u] = 1;
	long long mxx = 0;
	for (int i = 0; i < v[u].size(); i++){
		int w = v[u][i].F;
		if (!visited[w]){
			dfs (w);
			dp[u][1] += dp[w][1] + 2 * v[u][i].S;
			dp[u][0] += dp[w][1] + 2 * v[u][i].S;
			mxx = max(mxx, dp[w][1] - dp[w][0] + v[u][i].S);
		}
	}
	dp[u][0] -= mxx;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int x, y, w;
		cin >> x >> y >> w;
		v[x].PB(MP(y, w));
		v[y].PB(MP(x, w));
	}
	dfs (1);
	cout << dp[1][0] << endl;
}