#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int> C(21, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 21; j++) {
			if (A[i] & (1 << j)) {
				C[j]++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		A[i] = 0;
		for (int j = 0; j < 21; j++) {
			if (C[j] > 0) {
				C[j]--;
				A[i] += (1 << j);
			}
		}
		res += A[i] * A[i];
	}
	cout << res << endl;
}