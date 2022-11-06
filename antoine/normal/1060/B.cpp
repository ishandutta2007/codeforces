#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
int dp[100][200];

int f(const int i, const int carry) {
	if (i < 0)
		return carry == 0 ? 0 : -(int) 1e7;
	int &res = dp[i][carry];
	if (res != -1)
		return res;
	res = -(int) 1e7;

	for (int d1 = 0; d1 <= 9; ++d1)
		for (int d2 = 0; d2 <= 9; ++d2)
			if ((d1 + d2 + carry) % 10 == s[i] - '0') {
				res = max(res, d1 + d2 + f(i - 1, (d1 + d2 + carry) / 10));
			}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof dp);

	cin >> s;
	const int res = f((int) s.size() - 1, 0);
	cout << res << endl;
	return 0;
}