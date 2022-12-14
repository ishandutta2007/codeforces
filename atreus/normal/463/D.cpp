#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <fstream>
#include <unordered_map>

#define F first
#define S second
#define PB push_back

using namespace std;

const int maxn = 1e3 + 100;
int a[10][maxn];
int var[maxn][maxn];
vector <int> v[maxn];
int dp[maxn];
bool mark[maxn];
int cnt;

void setdp(int u){
	mark[u] = 1;
//	cout << u << " " << v[u].size() << endl;
	if (v[u].empty())
		dp[u] = 1;
	for (int i = 0; i < v[u].size(); i++){
		int w = v[u][i];
		if (!mark[w])
			setdp (w);
		dp[u] = max (dp[u], dp[w] + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int j = 0; j < k; j++)
		for (int i = 0; i < n; i++)
			cin >> a[j][i];
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			for (int l = j + 1; l < n; l++)
				var[a[i][j]][a[i][l]] ++;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (var[i][j] == k)
				v[i].PB(j);
	int ans = 1;
	for (int i = 1; i <= n; i++){
		if (!mark[i])
			setdp(i);
		ans = max(ans, dp[i]);
//		cout << i << " " << dp[i] << endl;
	}
	cout << ans << endl;
}