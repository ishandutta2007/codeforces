#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 998244353;
int p(int a, int r) {
	if (r == 0)return 1;
	if (r == 1)return a;
	if (r % 2 == 0) {
		int t = p(a, r / 2);
		return (t*t) % MOD;
	}
	else {
		return (p(a, r - 1)*a) % MOD;
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M, X;
	cin >> N >> M >> X;
	vector<int> A(M);
	int res = 1;
	for (int i = 0; i < M; i++) {
		cin >> A[i];
	}
	int l = 0;
	int ans = 0;
	int inv2 = (MOD + 1) / 2;
	for (int i = 0; i < M; i++) {
		int w = A[i] - l;
		int same = p(X, w);
		int all = p(X, 2 * w);
		ans = same + (((all - same) * inv2) % MOD);
		ans = ans % MOD; if (ans < 0)ans += MOD;
		res = (res*ans) % MOD;

		l = A[i];
	}
	int rem = N - 2 * l;
	res = (res * p(X, rem)) % MOD;

	if (res < 0)res += MOD;
	cout << res << endl;
}