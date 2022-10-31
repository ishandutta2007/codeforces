#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;
struct P {
	int X;
	int Y;
	P(int x, int y) {
		X = x;
		Y = y;
	}
	bool operator<(const P &R) const {
		if (X < 0 && 0 <= R.X) {
			return false;
		}
		if (X >= 0 && 0 > R.X) {
			return true;
		}
		if (X == 0 && R.X == 0) {
			return Y < R.Y;
		}
		return Y * R.X < X * R.Y;
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<int, int> > A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}
	int res = 0;
	int NC4 = (N - 1) * (N - 2) * (N - 3) * (N - 4) / 24;
	vector<int> T(N + 1);
	for (int i = 0; i < T.size(); i++) {
		T[i] = i * (i - 1) * (i - 2) / 6;
	}
	for (int i = 0; i < N; i++) {
		vector<P> X;
		for (int j = 0; j < N; j++) {
			if (i != j) {
				X.emplace_back(A[i].first - A[j].first, A[i].second - A[j].second);
			}
		}
		int ans = 0;
		sort(X.begin(), X.end());
		for (int j = 0; j < X.size(); j++) {
			P g(-X[j].X, -X[j].Y);
			int A = lower_bound(X.begin(), X.end(), g) - X.begin();
			if (A > j) A = A - j - 1;
			else A = j - A;
			//cerr << i << " " << j << " " << A << endl;
			ans += T[A];
			ans += T[N - 2 - A];
		}
		//cerr << i << " " << ans << endl;
		//cerr << NC4 - (ans / 2) << endl;
		res += NC4 - (ans / 2);
	}

	cout << res << endl;
}