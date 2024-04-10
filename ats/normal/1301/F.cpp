#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000007;
const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0, 0, -1};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<int> > A(N, vector<int>(M));
	vector<vector<pair<int, int> > > B(K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
			A[i][j]--;
			B[A[i][j]].emplace_back(i, j);
		}
	}
	int INF = (int)1 << 30;
	vector<vector<vector<int> > > D(K, vector<vector<int> >(N, vector<int>(M, INF)));
	for (int k = 0; k < K; k++) {
		vector<int> X(K, 0);
		queue<pair<int, int> > qu;
		for (int i = 0; i < B[k].size(); i++) {
			D[k][B[k][i].first][B[k][i].second] = 1;
			qu.emplace(B[k][i].first, B[k][i].second);
		}
		X[k] = 1;
		while (qu.size() > 0) {
			int a = qu.front().first;
			int b = qu.front().second;
			qu.pop();
			int ne = D[k][a][b] + 1;
			if (X[A[a][b]] == 0) {
				X[A[a][b]] = 1;
				int t = A[a][b];
				for (int i = 0; i < B[t].size(); i++) {
					if (D[k][B[t][i].first][B[t][i].second] > ne) {
						D[k][B[t][i].first][B[t][i].second] = ne;
						qu.emplace(B[t][i].first, B[t][i].second);
					}
				}
			}
			for (int i = 0; i < 4; i++) {
				int aa = a + dx[i];
				int bb = b + dy[i];
				if (aa >= 0 && aa < N && bb >= 0 && bb < M) {
					if (D[k][aa][bb] > ne) {
						D[k][aa][bb] = ne;
						qu.emplace(aa, bb);
					}
				}
			}
		}
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int X1, Y1, X2, Y2;
		cin >> X1 >> Y1 >> X2 >> Y2;
		X1--;
		Y1--;
		X2--;
		Y2--;
		int res = abs(X1 - X2) + abs(Y1 - Y2);
		for (int k = 0; k < K; k++) {
			res = min(res, D[k][X2][Y2] + D[k][X1][Y1] - 1);
		}
		cout << res << "\n";
	}
	return 0;
}