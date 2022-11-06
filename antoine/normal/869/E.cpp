#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 2509;
int dp[MxN + 9][MxN + 9];

const int MxQ = (int) 1e5 + 9;

int f(const int r, const int c) {
	stack<int> st;
	st.push(0);
	for (int j = 1; j <= c; ++j) {
		const int x = dp[r][j];
		if (x > 0)
			st.push(x);
		else if (x < 0) {
			assert(!st.empty());
			assert(-x == st.top());
			st.pop();
		}

	}
	return st.top();
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m, q;
	cin >> n >> m >> q;

	for (int i = 1; i <= q; ++i) {
		int type, r1, c1, r2, c2;
		cin >> type >> r1 >> c1 >> r2 >> c2;
		switch (type) {
		case 1:
			for (int r = r1; r <= r2; ++r) {
				assert(dp[r][c1] == 0);
				dp[r][c1] = i;
				assert(dp[r][c2 + 1] == 0);
				dp[r][c2 + 1] = -i;
			}
			break;
		case 2:
			for (int r = r1; r <= r2; ++r) {
				dp[r][c1] = 0;
				dp[r][c2 + 1] = 0;
			}
			break;
		case 3: {
			const bool ok = f(r1, c1) == f(r2, c2);
			cout << (ok ? "Yes" : "No") << '\n';
		}
			break;
		default:
			assert(false);
			break;
		}
	}
	return 0;
}