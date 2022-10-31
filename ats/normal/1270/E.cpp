#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}
	while (true) {
		vector<int> X;
		for (int i = 0; i < N; i++) {
			if ((A[i] + B[i]) % 2 == 0) {
				X.push_back(i);
			}
		}
		if (X.size() == N || X.size() == 0) {
			if (X.size() == 0) {
				for (int i = 0; i < N; i++) B[i]++;
			}
			for (int i = 0; i < N; i++) {
				int a = (A[i] + B[i]) / 2;
				int b = (A[i] - B[i]) / 2;
				A[i] = a;
				B[i] = b;
			}
		} else {
			cout << X.size() << endl;
			for (int i = 0; i < X.size(); i++) {
				if (i > 0) cout << " ";
				cout << X[i] + 1;
			}
			cout << endl;
			break;
		}
	}
}