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
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			A[i] = i - A[i];
		}
		vector<int> ne(2 * N);
		for (int i = 0; i < N; i++) {
			ne[i] = A[i] + N;
		}
		for (int i = 0; i < N; i++) {
			ne[i + N] = i;
		}
		int cur = 0;
		vector<int> V(2 * N, 0);
		vector<int> res;
		while (true) {
			if (V[cur] == 1) break;
			V[cur] = 1;
			cur = ne[cur];
		}
		while (true) {
			if (V[cur] == 2) break;
			if (cur < N) {
				res.push_back(cur);
			}
			V[cur] = 2;
			cur = ne[cur];
		}
		cout << res.size() << "\n";
		for (int i = 0; i < res.size(); i++) {
			if (i > 0) cout << " ";
			cout << res[i] + 1;
		}
		cout << "\n";
	}
	return 0;
}