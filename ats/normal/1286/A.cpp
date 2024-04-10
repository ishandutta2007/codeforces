#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

int N;
int solve(vector<int> A) {
	int a[2];
	a[0] = N / 2;
	a[1] = N - a[0];
	int l = -1;
	vector<int> X[2];
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] != 0) {
			a[A[i] % 2]--;

			if (l != -1) {
				if (A[l] % 2 == 0 && A[i] % 2 == 0) {
					X[0].push_back(i - l - 1);
				} else if (A[l] % 2 == 1 && A[i] % 2 == 1) {
					X[1].push_back(i - l - 1);
				} else {
					res++;
				}
			}
			l = i;
		}
	}
	for (int i = 0; i < 2; i++) {
		sort(X[i].begin(), X[i].end());
		for (int j = 0; j < X[i].size(); j++) {
			a[i] -= X[i][j];
			if (a[i] < 0) res += 2;
		}
	}
	// for (int i = 0; i < A.size(); i++) {
	// 	cerr << A[i] << " ";
	// }
	// cerr << res << endl;
	return res;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	vector<int> A(N);
	int res = N;
	int a[2];
	a[0] = N / 2;
	a[1] = N - a[0];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] != 0) {
			a[A[i] % 2]--;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			vector<int> B = A;
			if (B[0] == 0) {
				if (a[i] > 0) {
					B[0] = 2 + i;
				}
			}
			if (B.back() == 0) {
				if (a[j] > 0) {
					B.back() = 2 + j;
				}
			}
			if (B[0] != 0 && B.back() != 0) {
				res = min(res, solve(B));
			}
		}
	}
	cout << res << endl;
}