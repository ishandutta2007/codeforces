#include <iostream>
#include <algorithm>
using namespace std;


const int N = 305, T = 10 * 1000 * 1000 + 7, inf = 1000 * 1000 * 1000 + 7;

int dp1[N][N];
int adj[N][N];
int dis[N][N][N];
int a[N];
int b[N];
bool mark[N];

int main() {
	int n, t;
	cin >> n >> t;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			for (int k = 1; k <= n; k++) {
				dis[i][j][k] = -inf;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
		mark[a[i]] = true;
		dp1[i][i] = 1;
	}
	sort(b + 1, b + n + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int k = i; k < j; k++) {
				if (a[i] <= a[k] && a[k] <= a[j]) {
					dp1[i][j] = max(dp1[i][j], dp1[i][k] + 1);
				}
			}
			if (a[i] <= a[j]) {
				dis[a[i]][a[j]][1] = max(dis[a[i]][a[j]][1], dp1[i][j]);
			}
		//	cout << "47 " << i << " " << j << " " << dp1[i][j] << endl;
		//	cout << "73 " << i << " " << j << " " << dp1[i][j] << endl;
		//	if (a[i] <= a[j]) {
		//		for (int k = 1; k <= a[i]; k++) {
		//			dis[k][a[j]][1] = max(dis[k][a[j]][1], dp1[i][j]);
		//		}
		//	}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int k = i; k <= j; k++) {
				for (int q = k; q <= j; q++) {
					dis[b[i]][b[j]][1] = max(dis[b[i]][b[j]][1], dis[b[k]][b[q]][1]);
				}
			}
		//	cout << "49 " << b[i] << " " << b[j] << " " << dis[b[i]][b[j]][1] << endl;
		}
	}
/*	for (int i = N - 1; i; i--) {
		for (int j = 1; j < N; j++) {
			for (int k = 1; k <= j; k++) {
				dis[i][j][1] = max(dis[i][j][1], dis[i][k][1]);
			}
			for (int k = i; k < N; k++) {
				dis[i][j][1] = max(dis[i][j][1], dis[k][j][1]);
			}
		//	cout << dis[i][j][1] << " ";
		}
	//	cout << endl;
	}
//	for (int i = N - 1; i; i--) {
//		for (int j = N - 1; j; j--) {
//			for (int k = j; k )
//		}
//	}*/
//	for (int i = 1; i < N; i++) {
//		for (int j = 1; j < N; j++) {
//			cout << dis[i][j][1] << " ";
//		}
//		cout << endl;
//	}
	for (int k = 2; k <= n; k++) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				for (int q = i; q <= j; q++) {
					dis[b[i]][b[j]][k] = max(dis[b[i]][b[j]][k], dis[b[i]][b[q]][k - 1] + dis[b[q]][b[j]][1]);
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; j + k <= t && k <= n; k++) {
				ans = max(ans, dis[b[1]][b[i]][j] + dis[b[i]][b[n]][k] + 1ll * (t - j - k) * dis[b[i]][b[i]][1]);
			}
		}
	//	cout << "83 " << i << " " << b[i] << " " << dis[b[i]][b[i]][1] << " " << ans << endl;
	}
	cout << ans;
	return 0;
}