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
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}
	int Q;
	cin >> Q;
	map<pair<int, int>, int> mp;
	vector<int> X(N, 0);

	for (int i = 0; i < Q; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		c--;
		auto x = mp.find(make_pair(a, b));
		if (x != mp.end()) {
			int cc = (*x).second;
			sum -= max((int)0, A[cc] - X[cc]);
			X[cc]--;
			sum += max((int)0, A[cc] - X[cc]);
			if (c == -1) {
				mp.erase(x);
			}
		}
		if (c != -1) {
			mp[make_pair(a, b)] = c;
			sum -= max((int)0, A[c] - X[c]);
			X[c]++;
			sum += max((int)0, A[c] - X[c]);
		}
		cout << sum << "\n";
	}
	return 0;
}