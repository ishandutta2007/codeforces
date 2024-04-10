#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <fstream>

#define F first
#define S second
#define PB push_back

using namespace std;

const int maxn = 1e5 + 100;
vector <int> v[maxn];
bool mark[maxn];
int dp[maxn];

int main(){
	int n, m;
	cin >> n >> m;
	fill (dp, dp + n + 10, 1);
	for (int i = 0; i < m; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(w);
		v[w].PB(u);
	}
	for (int i = 1; i <= n; i ++){
		for (int j = 0; j < v[i].size(); j++){
			int u = v[i][j];
			if (u < i)
				dp[i] = max(dp[i], dp[u] + 1);
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		int m = v[i].size();
		ans = max(ans, 1ll * dp[i] * m);
	}
	cout << ans << endl;
}