#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<string> A(N);
	vector<string> B(M);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a;
		cin >> a;
		a--;
		cout << A[a % N] << B[a % M] << "\n";
	}
	return 0;
}