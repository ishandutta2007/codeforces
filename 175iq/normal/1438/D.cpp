#include <bits/stdc++.h>
 
int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
	int N; cin >> N;
	vector<int> A(N); for (int& a : A) cin >> a;
 
	if (N % 2 == 0) {
		int tot = 0;
		for (int i = 0; i < N; i++) {
			tot ^= A[i];
		}
		if (tot != 0) {
			cout << "NO" << '\n';
			exit(0);
		}
		N--;
	}
	cout << "YES" << '\n';
	cout << N-1 << '\n';
	for (int i = 0; i < (N-1) / 2; i++) {
		cout << 1 << ' ' << 2*i+2 << ' ' << 2*i+3 << '\n';
	}
	for (int i = 0; i < (N-1) / 2; i++) {
		cout << 1 << ' ' << 2*i+2 << ' ' << 2*i+3 << '\n';
	}
 
	return 0;
}