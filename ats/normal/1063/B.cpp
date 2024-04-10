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
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int isinside(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int sx, sy;
	int x, y;
	cin >> N >> M;
	cin >> sx >> sy;
	sx--; sy--;
	cin >> x >> y;
	vector<string> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	priority_queue<pair<int, pair<int,int> > > pq;
	pq.emplace(0, make_pair(sx, sy));
	int INF = (int)1 << 60;
	vector<vector<int> > V(N, vector<int>(M, INF));
	V[sx][sy] = 0;
	while ((int)pq.size() > 0) {
		pair<int, int>  t = pq.top().second; pq.pop();
		int c = V[t.first][t.second];
		int nc = c;
		for (int k = 0; k < 4; k++) {
			int xx = t.first + dx[k];
			int yy = t.second + dy[k];
			if (isinside(xx, yy) && A[xx][yy] == '.') {
				if (dy[k] == -1) {
					nc = c + 1;
				}
				else {
					nc = c;
				}
				if (V[xx][yy] > nc) {
					V[xx][yy] = nc;
					pq.emplace(-nc, make_pair(xx, yy));
				}
			}
		}
	}
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (V[i][j] != INF) {
				if (V[i][j] <= x && j - sy + V[i][j] <= y) {
					res++;
				}
			}
		}
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (V[i][j] == INF) {
				cerr << -1 << " ";
			}
			else {
				cerr << V[i][j] << " ";
			}
		}
		cerr << endl;
	}*/
	cout << res << endl;
}