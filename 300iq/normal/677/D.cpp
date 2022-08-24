#include <bits/stdc++.h>

using namespace std;

int n, m, p, l, r, x, y, xx, yy, ost, to_x, to_y, target_x, target_y;
const int MAXN = 307, INF = INT_MAX / 2;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int d[MAXN][MAXN];
int q[MAXN];
vector <int> px[MAXN * MAXN], py[MAXN * MAXN];
vector <pair <int, int> > memes;

bool check(int a, int b) {
	return (a >= 1 && a <= n && b >= 1 && b <= m);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == p) {
				target_x = i;
				target_y = j;
			}
			px[a[i][j]].push_back(i);
			py[a[i][j]].push_back(j);
			dp[i][j] = INF;
		}
	}
	for (int i = 0; i < (int) px[1].size(); i++) {
		x = px[1][i];
		y = py[1][i];
		dp[x][y] = (x - 1) + (y - 1);
	}
	for (int i = 1; i < p; i++) {
		ost = (int) px[i].size() * px[i + 1].size();
		if (ost <= n * m) {
			for (int s = 0; s < (int) px[i].size(); s++) {
				for (int t = 0; t < (int) px[i + 1].size(); t++) {
					x = px[i][s], y = py[i][s];
					xx = px[i + 1][t], yy = py[i + 1][t];
					dp[xx][yy] = min(dp[xx][yy], dp[x][y] + abs(x - xx) + abs(y - yy));
				}
			}
		} else {
			for (int s = 1; s <= n; s++) {
				for (int t = 1; t <= m; t++) {
					d[s][t] = INF;
				}
			}
			queue <int> qx, qy;
			memes.clear();
			for (int s = 0; s < (int) px[i].size(); s++) {
				d[px[i][s]][py[i][s]] = dp[px[i][s]][py[i][s]];
				qx.push(px[i][s]);
				qy.push(py[i][s]);
			}
			while (!qx.empty()) {
				x = qx.front();
				y = qy.front();
				qx.pop();
				qy.pop();
				for (int t = 0; t < 4; t++) {
					to_x = x + dx[t], to_y = y + dy[t];
					if (d[x][y] + 1 < d[to_x][to_y]) {
						d[to_x][to_y] = d[x][y] + 1;
						qx.push(to_x);
						qy.push(to_y);
					}
				}
			}
			for (int t = 0; t < (int) px[i + 1].size(); t++) {
				dp[px[i + 1][t]][py[i + 1][t]] = d[px[i + 1][t]][py[i + 1][t]];
			}
		}
	}
	cout << dp[target_x][target_y] << endl;
}