#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int B = 5000;
const int C = 2 * sqrt(B + 1) + 9;
int dp[2 * B + 1][C];

ll C2(ll x) {
	return x * (x - 1) / 2;
}

void f() {
	int n;
	cin >> n;
	if (n < B) {
		cout << string(n, '1') << "337\n";
		return;
	}
	for (int j = 2 * B; j >= 1; --j) {
		bool ok = n > 2 * B ? n - C2(j) >= B : n - C2(j) >= 0 && dp[n][j] == 1;
		if (ok) {
			n -= C2(j);
			assert(n >= 0);
			cout << 1;
		}
		cout << 3;
	}
	assert(!n);
	cout << "7\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	for (int i = 0; i <= 2 * B; ++i)
		for (int j = 0; C2(j) <= i; ++j) {
			assert(j <= C);
			int &res = dp[i][j];
			if (j == 0)
				res = i == 0 ? 2 : 0;
			else {
				if (dp[i][j - 1])
					res = 2;
				else if (dp[i - C2(j)][j - 1])
					res = 1;
				else {
					res = 0;
					if (i >= 500 && C2(j + 1) > i)
						assert(false);
				}
			}
		}

	int t;
	cin >> t;
	while (t--)
		f();
	return 0;
}