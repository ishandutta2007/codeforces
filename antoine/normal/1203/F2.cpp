#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

struct D {
	int a, b;
	bool operator<(const D &other) const {
		if ((b > 0) != (other.b > 0))
			return b > 0 && !(other.b > 0);
		return b > 0 ? a < other.a : a + b > other.a + other.b;
	}
};

const int MxX = (int) 6e4 + 9;
int dp[2][MxX + 309];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, R;
	cin >> n >> R;
	vector<D> v(n);
	for (D &d : v)
		cin >> d.a >> d.b;
	sort(v.begin(), v.end());

	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j <= MxX; ++j) {
			int &res = dp[i & 1][j] = dp[~i & 1][j];
			if (j >= v[i].a && j + v[i].b >= 0)
				res = max(res, 1 + dp[~i & 1][j + v[i].b]);
		}
	}
	cout << dp[0][R];
	return 0;
}