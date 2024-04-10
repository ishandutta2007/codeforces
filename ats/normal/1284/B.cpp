#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> B;
	vector<int> A;
	int res = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vector<int> X(a);
		bool ok = true;
		for (int j = 0; j < a; j++) {
			cin >> X[j];
			if (j > 0 && X[j - 1] < X[j]) {
				ok = false;
			}
		}
		if (ok) {
			A.push_back(X[0]);
			B.push_back(X.back());
		}
	}
	res = N * N;
	sort(A.begin(), A.end());
	for (int i = 0; i < B.size(); i++) {
		res -= upper_bound(A.begin(), A.end(), B[i]) - A.begin();
	}
	cout << res << endl;
}