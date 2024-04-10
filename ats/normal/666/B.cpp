#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<vector<int> > g(N);
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
	}
	int INF = (int)1 << 60;
	vector<vector<int> > dist(N, vector<int>(N, INF));
	for (int i = 0; i < N; i++) {
		dist[i][i] = 0;

		queue<int> qu;
		qu.push(i);
		while (qu.size()) {
			int a = qu.front(); qu.pop();
			for (int j : g[a]) {
				if (dist[i][j] > dist[i][a] + 1) {
					dist[i][j] = dist[i][a] + 1;
					qu.push(j);
				}
			}
		}
	}
	vector<vector<pair<int, int>  > > X(N);
	vector<vector<pair<int, int>  > > Y(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[i][j] == INF) {
				dist[i][j] = -((int)1 << 50);
			}
			X[j].emplace_back(dist[i][j], i);
			Y[i].emplace_back(dist[i][j], j);
		}
	}
	for (int i = 0; i < N; i++) {
		sort(X[i].rbegin(), X[i].rend());
		sort(Y[i].rbegin(), Y[i].rend());
	}
	int mx = -1;
	vector<int> res(4);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {


				for (int x = 0; x < 3; x++) {
					if (X[i][x].second != i && X[i][x].second != j) {
						for (int y = 0; y < 3; y++) {
							if (Y[j][y].second != i && Y[j][y].second != j) {
								if (X[i][x].second != Y[j][y].second) {
									if (mx < dist[i][j] + X[i][x].first + Y[j][y].first) {
										mx = dist[i][j] + X[i][x].first + Y[j][y].first;
										res[0] = X[i][x].second;
										res[1] = i;
										res[2] = j;
										res[3] = Y[j][y].second;
									}
								}
							}
						}
					}
				}

			}
		}
	}

	//cerr << mx << endl;
	cout << res[0] + 1 << " " << res[1] + 1 << " " << res[2] + 1 << " " << res[3] + 1 << endl;
}