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
		string res = "YES";
		int N;
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			A[i] = (((A[i] + i) % N) + N) % N;
		}
		vector<int> X(N, 0);
		for (int i = 0; i < N; i++) {
			if (X[A[i]] == 1) {
				res = "NO";
				break;
			}
			X[A[i]] = 1;
		}
		cout << res << endl;
	}
}