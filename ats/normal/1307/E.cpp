#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> S(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
		S[i]--;
	}
	vector<int> L(N, -1);
	vector<int> R(N, -1);
	for (int i = 0; i < M; i++) {
		int f, h;
		cin >> f >> h;
		f--;
		{
			int t = 0;
			for (int j = 0; j < N; j++) {
				if (S[j] == f) {
					t++;
					if (t == h) {
						L[j] = i;
					}
				}
			}
		}
		{
			int t = 0;
			for (int j = N - 1; j >= 0; j--) {
				if (S[j] == f) {
					t++;
					if (t == h) {
						R[j] = i;
					}
				}
			}
		}
	}
	vector<int> B(N + 1, 0);
	int mx = 0;
	for (int i = -1; i < N; i++) {
		if (i == -1 || L[i] != -1) {
			int col = -1;
			if (i >= 0) {
				col = S[i];
				B[i + 1] = 1;
			}
			vector<int> CL(N, 0);
			for (int j = 0; j < i; j++) {
				if (L[j] != -1) {
					CL[S[j]]++;
				}
			}
			vector<int> CR(N, 0);
			for (int j = i + 1; j < N; j++) {
				if (R[j] != -1) {
					CR[S[j]]++;
				}
			}
			for (int j = 0; j < N; j++) {
				if (j == col) {
					int cnt = CR[j];
					if (CL[j] < CR[j]) cnt--;
					if (cnt > 0) {
						B[i + 1]++;
					}
				} else {
					if ((CL[j] >= 1 && CR[j] >= 2) || (CL[j] >= 2 && CR[j] >= 1)) {
						B[i + 1] += 2;
					} else if (CL[j] >= 1 || CR[j] >= 1) {
						B[i + 1] += 1;
					}
				}
			}
			mx = max(mx, B[i + 1]);
		}
	}

	if (mx == 0) {
		res = 1;
	} else {
		res = 0;
		for (int i = -1; i < N; i++) {
			if ((i == -1 || L[i] != -1) && B[i + 1] == mx) {
				int tmp = 1;
				int col = -1;
				if (i >= 0) {
					col = S[i];
				}
				vector<int> CL(N, 0);
				for (int j = 0; j < i; j++) {
					if (L[j] != -1) {
						CL[S[j]]++;
					}
				}
				vector<int> CR(N, 0);
				for (int j = i + 1; j < N; j++) {
					if (R[j] != -1) {
						CR[S[j]]++;
					}
				}
				for (int j = 0; j < N; j++) {
					if (j == col) {
						if ((CL[j] >= 1 && CR[j] >= 1) || (CR[j] >= 2)) {
							int cnt = CR[j];
							if (CL[j] < CR[j]) cnt--;
							tmp = (tmp * cnt) % MOD;
						}
					} else {
						if ((CL[j] >= 1 && CR[j] >= 2) || (CL[j] >= 2 && CR[j] >= 1)) {
							tmp = (tmp * (CL[j] * CR[j] - min(CL[j], CR[j]))) % MOD;
						} else if (CL[j] >= 1 || CR[j] >= 1) {
							tmp = (tmp * (CL[j] + CR[j])) % MOD;
						}
					}
				}
				res = (res + tmp) % MOD;
			}
		}
	}

	cout << mx << " " << res << endl;
}