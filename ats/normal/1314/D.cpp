#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<vector<int> > D(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> D[i][j];
		}
	}
	const int INF = (int)1 << 50;
	int res = INF;
	if (K == 2) {
		for (int i = 1; i < N; i++) {
			res = min(res, D[0][i] + D[i][0]);
		}
		cout << res << endl;
		return 0;
	}

	vector<vector<vector<pair<int, int> > > > mn(N, vector<vector<pair<int, int> > >(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (k != i && k != j) {
					mn[i][j].emplace_back(D[i][k] + D[k][j], k);
				}
			}
			sort(mn[i][j].begin(), mn[i][j].end());
		}
	}
	int K2 = K / 2;
	int x[5];
	int T[5][5];
	x[0] = 0;
	int cur = 0;
	vector<int> V(N, cur);

	for (x[1] = 0; x[1] < N; x[1]++) {
		for (x[2] = x[1]; x[2] < N; x[2]++) {
			for (x[3] = x[2]; x[3] < N; x[3]++) {
				for (x[4] = x[3]; x[4] < N; x[4]++) {
					cur++;
					for (int i = 0; i < K2; i++) {
						V[x[i]] = cur;
					}
					for (int i = 0; i < K2; i++) {
						for (int j = 0; j < K2; j++) {
							T[i][j] = INF;
							for (int t = 0; t < mn[x[i]][x[j]].size(); t++) {
								if (V[mn[x[i]][x[j]][t].second] != cur) {
									T[i][j] = mn[x[i]][x[j]][t].first;
									break;
								}
							}
						}
					}
					vector<int> ord(K2 - 1);
					for (int i = 0; i < K2 - 1; i++) {
						ord[i] = i + 1;
					}
					do {
						int tmp = T[0][ord[0]];
						for (int i = 0; i < K2 - 2; i++) {
							tmp += T[ord[i]][ord[i + 1]];
						}
						tmp += T[ord.back()][0];
						// if (res > tmp) {
						// 	for (int i = 0; i < K2; i++) {
						// 		cerr << x[ord[i]] << " ";
						// 	}
						// 	cerr << endl;
						// }
						res = min(res, tmp);
					} while (next_permutation(ord.begin(), ord.end()));
				}
			}
		}
	}
	cout << res << endl;
}