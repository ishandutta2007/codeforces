# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

# define F first
# define S second
# define pb push_back
# define endl '\n'
# define sep ' '

const int xn = 60 + 10;
const int xm = 1e3 + 10;

int n, m, r;
int a[xn][xn][xn], dist[xn][xn];
int dis[xn][xn][xn], dp[xn][xn][xm];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m >> r;
	for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) cin >> a[i][j][k];

	for (int car = 1; car <= m; car++){
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[car][i][j] = a[car][i][j];
		for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[car][i][j] = min(dis[car][i][j], dis[car][i][k] + dis[car][k][j]);
	}
	//cout << endl;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			dist[i][j] = 1e9+10;
			for (int k = 1; k <= m; k++) dist[i][j] = min(dis[k][i][j], dist[i][j]);
			//cout << dist[i][j] << sep;
		}
		//cout << endl;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1;  j <= n; j++) dp[i][j][0] = dist[i][j];
		for (int k = 1; k <= 1000; k++){
			for (int v = 1; v <= n; v++){
				dp[i][v][k] = 1e9 + 10;
				for (int u = 1; u <= n; u++){
					if (v == u) continue;
					dp[i][v][k] = min(dp[i][v][k], dp[i][u][k-1] + dist[u][v]);
				}
			}
		}
	}
	//cout << dp[1][4][1] << endl;
	while (r--){
		int s, t, k;
		cin >> s >> t >> k;
		int mn = 1e9+10;
		for (int i = 0; i <= k; i++) mn = min(mn, dp[s][t][i]);
		cout << mn << endl;
	}
}

/*
4 2 3
0 1 5 6
2 0 3 6
1 3 0 1
6 6 7 0
0 3 5 6
2 0 1 6
1 3 0 2
6 6 7 0
1 4 2
1 4 1
1 4 3

*/