#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	int N;
	cin >> N;
	if (N <= 3) {
		cout << 0 << "\n"
			 << flush;
		return 0;
	}
	int k = 0;
	int mx = 0;
	for (int i = 2; i <= N - 1; i++) {
		int t = (i - 1) * (N / i) - (i - 1);
		t += max((int)0, (N % i) - 1);
		if (mx < t) {
			mx = t;
			k = i;
		}
	}
	vector<int> order;
	for (int i = 0; i < k - 1; i++) {
		for (int j = 0; j <= (N / k); j++) {
			int t = j * k + i;
			if (t < N - 1) {
				order.push_back(t);
			}
		}
	}
	vector<int> X(N, 0);
	while (true) {
		int c = 0;
		for (int i = 0; i < N; i++) {
			c += X[i];
		}
		if (c >= mx) break;
		vector<int> A;
		vector<int> B;
		for (const int &i : order) {
			if (X[i] == 0)
				A.push_back(i);
			else
				B.push_back(i);
		}
		A.resize(k);
		while (A.size() < k) {
			A.push_back(B.back());
			B.pop_back();
		}
		cout << A.size();
		for (int i = 0; i < A.size(); i++) {
			X[A[i]] = 1;
			cout << " " << A[i] + 1;
		}
		cout << "\n"
			 << flush;
		int x;
		cin >> x;
		x--;
		for (int i = 0; i < k; i++) {
			X[(x + i) % N] = 0;
		}
	}
	cout << 0 << "\n"
		 << flush;
	return 0;
}