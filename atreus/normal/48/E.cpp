#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#define PB push_back
#define MP make_pair
#define S second
#define F first

using namespace std;

const int inf = 1e9 + 7;
const int maxn = 400;
bool mark[maxn][maxn], mark1[maxn][maxn], cycle;
int h, t, r, n, m, dp[maxn][maxn], ans;
pair <int, int> a[maxn], b[maxn];
queue <pair <int, int> > qu;

void dfs (int x, int y){
	mark[x][y] = 1;
	mark1[x][y] = 1;
	dp[x][y] = 1;
	for (int i = 1; i <= min (x, n); i++){
		int l = x - i + a[i].F;
		int tm = y + a[i].S;
		if (tm + l > r)
			continue;
		if (mark[l][tm])
			cycle = 1;
		if (!mark1[l][tm])
			dfs(l, tm);
		dp[x][y] = max(dp[x][y], dp[l][tm] + 1);
	}
	for (int i = 1; i <= min (y, m); i++){
		int l = x + b[i].F;
		int tm = y - i + b[i].S;
		if (tm + l > r)
			continue;
		if (mark[l][tm])
			cycle = 1;
		if (!mark1[l][tm])
			dfs(l, tm);
		dp[x][y] = max(dp[x][y], dp[l][tm] + 1);
	}
	ans = max(ans, dp[x][y]);
	mark[x][y] = 0; 
}	

void bfs (int x, int y){
	mark[x][y] = 1;
	qu.push(MP(x, y));
	dp[x][y] = 0;
	while (!qu.empty()){
		x = qu.front().F, y = qu.front().S;
		for (int i = 1; i <= min (n, x); i++){
			int l = x - i + a[i].F;
			int tm = y + a[i].S;
			if (l + tm > r)
				continue;
			if (!mark[l][tm]){
				mark[l][tm] = 1;
				qu.push(MP(l, tm));
			}
			if (dp[l][tm] == -1)
				dp[l][tm] = inf;
			dp[l][tm] = min(dp[l][tm], dp[x][y] + 1);
		}
		for (int i = 1; i <= min (m, y); i++){
			int l = x + b[i].F;
			int tm = y - i + b[i].S;
			if (l + tm > r)
				continue;
			if (!mark[l][tm]){
				mark[l][tm] = 1;
				qu.push(MP(l, tm));
			}
			if (dp[l][tm] == -1)
				dp[l][tm] = inf;
			dp[l][tm] = min(dp[l][tm], dp[x][y] + 1);
		}
		qu.pop();
	}
}

int main (){
	ios_base::sync_with_stdio(false);
	cin >> h >> t >> r >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].F >> a[i].S;
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> b[i].F >> b[i].S;
	memset (dp, -1, sizeof dp);
	bfs (h, t);
	if (dp[0][0] != -1){
		cout << "Ivan" << '\n' << dp[0][0] << endl;
		return 0;
	}
	memset (dp, -1, sizeof dp);
	memset (mark, 0, sizeof mark);
	dfs (h, t);
	if (cycle)
		return cout << "Draw" << endl, 0;
	cout << "Zmey" << '\n' << ans << endl;
}