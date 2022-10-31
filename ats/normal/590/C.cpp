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
const int INF = 1e9;
const int dx[4] = { 0,-1,0,1 };
const int dy[4] = { -1,0,1,0 };
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	//vector<vector<vector<int> > > A(N, vector<vector<int> >(M, vector<int>(3)));
	vector<vector<vector<int> > > D(N, vector<vector<int> >(M, vector<int>(3, INF)));
	int res = 0;
	vector<string> S(N);
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	for (int k = 0; k < 3; k++) {
		queue<pair<int, int> >qu;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (S[i][j] == k + 1 + '0') {
					D[i][j][k] = 0;
					qu.emplace(i, j);
				}
			}
		}
		pair<int, int> p;
		while (qu.size()) {
			p = qu.front(); qu.pop();
			
			for (int dir = 0; dir < 4; dir++) {
				int nx = p.first + dx[dir];
				int ny = p.second + dy[dir];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
					if (S[nx][ny] != '#') {
						if (D[nx][ny][k] > D[p.first][p.second][k] + 1) {
							D[nx][ny][k] = D[p.first][p.second][k] + 1;
							qu.emplace(nx, ny);
						}
					}
				}
			}

		}
	}
	res = INF;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (S[i][j] == '.') {
				res = min(res, D[i][j][0] + D[i][j][1] + D[i][j][2] - 2);
			}
		}
	}
	int d[3];
	d[0] = d[1] = d[2] = INF;
	for (int x = 0; x < 3; x++) {
		int a1 = x;
		int a2 = (x + 1) % 3;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (S[i][j] == a1 + 1 + '0') {
					d[x] = min(d[x], D[i][j][a2]);
				}
			}
		}
	}

	for (int x = 0; x < 3; x++) {
		int a1 = x;
		int a2 = (x + 1) % 3;
		res = min(res, d[a1] + d[a2] - 2);
	}
	if (res >= INF-5) {
		res = -1;
	}
	cout << res << endl;
}