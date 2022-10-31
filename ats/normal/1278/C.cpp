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
		vector<int> B(N);
		int res = 2 * N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			A[i] = 2 * A[i] - 3;
		}
		for (int i = 0; i < N; i++) {
			cin >> B[i];
			B[i] = 2 * B[i] - 3;
		}
		reverse(A.begin(), A.end());
		A.push_back(0);
		for (int i = N - 1; i >= 0; i--) {
			A[i] += A[i + 1];
		}
		map<int, int> mp;
		B.push_back(0);
		mp[0] = N;
		for (int i = N - 1; i >= 0; i--) {
			B[i] += B[i + 1];
			mp[-B[i]] = i;
		}
		for (int i = 0; i <= N; i++) {
			auto x = mp.find(A[i]);
			if(x != mp.end()){
				res = min(res, i + (*x).second);
			}
		}
		cout << res << "\n";
	}
}