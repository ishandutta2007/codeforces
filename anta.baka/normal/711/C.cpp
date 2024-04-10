#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

ll c[100], p[100][100], dp[101][101][101],
	pmin[101][101][101], smin[101][101][101];

const ll INF = 1e17;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		cin >> c[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			cin >> p[i][j];
			if(c[i] != 0 && j+1 != c[i])
				p[i][j] = INF;
		}
	for(int j = 1; j < k; j++)
		for(int w = 0; w < m; w++) {
			dp[0][j][w] = INF;
			pmin[0][j][w] = INF;
			smin[0][j][w] = INF;
		}
	for(int w = 0; w < m; w++) {
		dp[0][0][w] = p[0][w];
		pmin[0][0][w] = dp[0][0][w];
		if(w > 0)
			pmin[0][0][w] = min(pmin[0][0][w], pmin[0][0][w-1]);
	}
	for(int w = m-1; w > 0; w--) {
		smin[0][0][w] = dp[0][0][w];
		if(w != m-1)
			smin[0][0][w] = min(smin[0][0][w], smin[0][0][w+1]);
	}
	for(int i = 1; i < n; i++)
		for(int j = 0; j < k; j++) {
			for(int w = 0; w < m; w++) {
				dp[i][j][w] = INF;
				dp[i][j][w] = min(dp[i][j][w], dp[i-1][j][w] + p[i][w]);
				if(j > 0) {
					if(w != 0)
						dp[i][j][w] = min(dp[i][j][w], pmin[i-1][j-1][w-1] + p[i][w]);
					if(w != m-1)
						dp[i][j][w] = min(dp[i][j][w], smin[i-1][j-1][w+1] + p[i][w]);
				}
				pmin[i][j][w] = dp[i][j][w];
				if(w > 0)
					pmin[i][j][w] = min(pmin[i][j][w], pmin[i][j][w-1]);
			}
			for(int w = m-1; w > 0; w--) {
				smin[i][j][w] = dp[i][j][w];
				if(w != m-1)
					smin[i][j][w] = min(smin[i][j][w], smin[i][j][w+1]);
			}
		}
	ll res = pmin[n-1][k-1][m-1];
	if(res == INF)
		cout << -1;
	else {
		for(int i = 0; i < n; i++)
			if(c[i] != 0)
				res -= p[i][c[i]-1];
		cout << res;
	}
}