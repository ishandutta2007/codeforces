#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;
inline void amax(int &a, const int &b) {
	a = max(a, b);
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	int res = 0;
	vector<int> T(1 << N, 0);
	for (int i = 0; i < K; i++) {
		int a;
		cin >> a;
		a--;
		T[a] = 1;
	}
	int INF = (int)1 << 60;
	vector<vector<vector<int> > > X(1 << (N - 1), vector<vector<int> >(2, vector<int>(2, -INF)));
	for (int i = 0; i < (1 << N); i += 2) {
		int a = i;
		int b = i + 1;
		int j = i / 2;
		if (T[a] + T[b] == 0) {
			X[j][0][0] = 0;
		} else if (T[a] + T[b] == 1) {
			X[j][1][0] = 1;
			X[j][0][1] = 1;
		} else {
			X[j][1][1] = 1;
		}
	}
	while ((int)X.size() > 1) {
		vector<vector<vector<int> > > nX(X.size() / 2, vector<vector<int> >(2, vector<int>(2, -INF)));
		for (int i = 0; i < X.size(); i += 2) {
			int a = i;
			int b = i + 1;
			int j = i / 2;
			for (int awin = 0; awin < 2; awin++) {
				for (int alose = 0; alose < 2; alose++) {
					for (int bwin = 0; bwin < 2; bwin++) {
						for (int blose = 0; blose < 2; blose++) {
							int winsum = awin + bwin;
							int losesum = alose + blose;
							int base = X[a][awin][alose] + X[b][bwin][blose];

							if (winsum == 0 && losesum == 0) {
								amax(nX[j][0][0], base);
							} else if (winsum == 1 && losesum == 0) {
								amax(nX[j][1][0], base + 1);
								amax(nX[j][0][1], base + 2);
							} else if (winsum == 2 && losesum == 0) {
								amax(nX[j][1][1], base + 2);
							} else if (winsum == 0 && losesum == 1) {
								amax(nX[j][0][1], base + 2);
							} else if (winsum == 1 && losesum == 1) {
								amax(nX[j][1][1], base + 3);
							} else if (winsum == 2 && losesum == 1) {
								amax(nX[j][1][1], base + 3);
							} else if (winsum == 0 && losesum == 2) {
								amax(nX[j][0][1], base + 2);
							} else if (winsum == 1 && losesum == 2) {
								amax(nX[j][1][1], base + 3);
							} else if (winsum == 2 && losesum == 2) {
								amax(nX[j][1][1], base + 3);
							}
						}
					}
				}
			}
		}
		swap(X, nX);
	}
	for (int win = 0; win < 2; win++) {
		for (int lose = 0; lose < 2; lose++) {
			amax(res, X[0][win][lose] + ((win == 0 && lose == 0) ? 0 : 1));
		}
	}
	cout << res << endl;
}