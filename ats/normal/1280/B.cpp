#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<string> S(N);
		for (int i = 0; i < N; i++) {
			cin >> S[i];
		}
		int res = 5;
		{
			bool ok = true;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (S[i][j] == 'P') {
						ok = false;
					}
				}
			}
			if (ok) {
				res = min(res, (int)0);
			}
		}
		{
			bool ok = true;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (S[i][j] == 'A') {
						ok = false;
					}
				}
			}
			if (!ok) {
				res = min(res, (int)4);
			}
		}
		for (int i = 0; i < N; i++) {
			bool ok = true;
			for (int j = 0; j < M; j++) {
				if (S[i][j] == 'P') {
					ok = false;
				}
			}
			if (ok) {
				if (i == 0 || i == N - 1) {
					res = min(res, (int)1);
				} else {
					res = min(res, (int)2);
				}
			}
		}
		for (int i = 0; i < M; i++) {
			bool ok = true;
			for (int j = 0; j < N; j++) {
				if (S[j][i] == 'P') {
					ok = false;
				}
			}
			if (ok) {
				if (i == 0 || i == M - 1) {
					res = min(res, (int)1);
				} else {
					res = min(res, (int)2);
				}
			}
		}
		if (S[0][0] == 'A' || S[0][M - 1] == 'A' ||
			S[N - 1][0] == 'A' || S[N - 1][M - 1] == 'A') {
			res = min(res, (int)2);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (S[i][j] == 'A') {
					if (i == 0 || j == 0 || i == N - 1 || j == M - 1) {
						res = min(res, (int)3);
					}
				}
			}
		}
		if (res == 5) {
			cout << "MORTAL\n";
		} else {
			cout << res << "\n";
		}
	}
	return 0;
}