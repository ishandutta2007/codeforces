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
		int N;
		cin >> N;
		vector<int> A(N);
		int res = 0;
		int x = 0;
		int s = 0;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			s += A[i];
			x ^= A[i];
		}
		cout << 2 << "\n";
		cout << x << " " << x + s << "\n";
		// A.push_back(x);
		// A.push_back(s + x);
		// x = 0;
		// s = 0;
		// for (int i = 0; i < N + 2; i++) {
		// 	s += A[i];
		// 	x ^= A[i];
		// }
		// cerr << s << " " << 2 * x << "\n";
	}
	return 0;
}