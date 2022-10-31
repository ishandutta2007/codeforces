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
	int X = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
		X += (A[i] + (i % 2)) / 2;
	}

	cout << min(X, sum - X) << endl;
}