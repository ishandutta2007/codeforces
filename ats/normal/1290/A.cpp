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
		int N, M, K;
		cin >> N >> M >> K;
		K = min(K, M - 1);
		vector<int> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		int ok = 0;
		int ng = 1e9 + 2;
		while (ng - ok > 1) {
			vector<int> B(M, 0);
			int m = (ok + ng) / 2;
			for (int i = 0; i < M; i++) {
				if (A[i] < m && A[N - M + i] < m) {
					B[i] = 1;
				}
			}
			int mx = 0;
			int t = 0;
			for (int i = 0; i <= M; i++) {
				if (i == M || B[i] == 1) {
					mx = max(mx, t);
					t = 0;
				} else {
					t++;
				}
			}
			if(mx >= M - K){
				ok = m;
			}else{
				ng = m;
			}
		}
		cout << ok << "\n";
	}
	return 0;
}