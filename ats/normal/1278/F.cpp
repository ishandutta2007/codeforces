#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 998244353;

void extgcd(int a, int b, int& x, int& y) {
	if (b != 0) {
		extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1;
		y = 0;
	}
}

int mod_inverse(int a, int p) {
	int x, y;
	extgcd(a, p, x, y);
	return (p + x % p) % p;
}
int add(int& a, const int& b) {
	a += b;
	if (a >= MOD) a -= MOD;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M, K;
	cin >> N >> M >> K;
	int P = mod_inverse(M, MOD);
	vector<vector<int> > A(K + 1, vector<int>(K + 1, 0));
	A[1][1] = (N * P) % MOD;
	for (int i = 1; i < K; i++) {
		for (int j = 1; j < K; j++) {
			if (N >= j) add(A[i + 1][j + 1], (A[i][j] * P % MOD) * (N - j) % MOD);
			add(A[i + 1][j], (A[i][j] * j) % MOD);
		}
	}
	int res = 0;
	for (int i = 1; i <= K; i++) {
		add(res, A[K][i]);
	}
	res %= MOD;
	res += MOD;
	res %= MOD;
	cout << res << endl;
}