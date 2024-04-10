#include <bits/stdc++.h>
#define PB push_back

using namespace std;


const int maxn = 2e5 + 100;
int a[maxn], v[maxn][2];
long long dp[maxn][2];
bool mark[maxn][2];

void dfs (int u, bool goback){ // back : 0, front : 1
	mark[u][goback] = 1;
	if (u == 1)
		return;
	if (goback == 1){
		int w = v[u][1];
		if (!mark[w][0])
			dfs(w, 0);
		if (dp[w][0] != -1)
			dp[u][1] = dp[w][0] + a[u];
	}
	else {
		int w = v[u][0];
		if (!mark[w][1])
			dfs(w, 1);
		if (dp[w][1] != -1)
			dp[u][0] = dp[w][1] + a[u];
	}
}

int main(){
	int n, k;
	cin >> n;
	for (int i = 2; i <= n; i++){
		cin >> a[i];
		int myback = max(0, i - a[i]);
		int myfront = min(n + 1, i + a[i]);
		v[i][0] = myback;
		v[i][1] = myfront;
	}
	memset (dp, -1, sizeof dp);
	dp[n + 1][1] = 0;
	dp[n + 1][0] = 0;
	dp[0][1] = 0;
	dp[0][0] = 0;
	for (int i = 2; i <= n; i++)
		if (!mark[i][0])
			dfs(i, 0);
	for (int i = 2; i <= n; i++){
		k = 0;
		if (dp[i][0] != -1)
			k = i - 1;
		cout << dp[i][0] + k << endl;
	}
}