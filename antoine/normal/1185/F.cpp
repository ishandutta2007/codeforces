#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

int in() {
	int k;
	cin >> k;
	int res = 0;
	while (k--) {
		int i;
		cin >> i;
		--i;
		res |= 1 << i;
	}

	return res;
}

void upd(int &x, pair<int, int> &p1, int y, pair<int, int> p2) {
	if (!x || x > y) {
		x = y;
		p1 = p2;
	}
}

int dp[1 << 9];
int twos[1 << 9];
pair<int, int> ch2[1 << 9];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int x = in();
		dp[x]++;
	}
	for (int i = 0; i < 9; ++i) {
		for (int x = 0; x < (1 << 9); ++x)
			if (!(x & (1 << i)))
				dp[x | (1 << i)] += dp[x];
	}

	{

		static int ones[1 << 9];
		static int ch1[1 << 9];

		for (int i = 0; i < m; ++i) {
			int c;
			cin >> c;
			const int x = in();
			if (!ones[x]) {
				ones[x] = c;
				ch1[x] = i;
			} else {
				upd(twos[x], ch2[x], c + ones[x], { i, ch1[x] });
				if (c < ones[x]) {
					ones[x] = c;
					ch1[x] = i;
				}
			}
		}

		for (int x = 0; x < (1 << 9); ++x)
			for (int y = x + 1; y < (1 << 9); ++y)
				if (ones[x] && ones[y])
					upd(twos[x | y], ch2[x | y], ones[x] + ones[y], { ch1[x], ch1[y] });
	}

	int ans1 = 0, ans2 = INT_MAX;
	pair<int, int> ch;

	for (int x = 0; x < (1 << 9); ++x)
		if (twos[x]) {
			const int cnt = dp[x];
			if (cnt > ans1 || (cnt == ans1 && twos[x] < ans2)) {
				ans1 = cnt;
				ans2 = twos[x];
				ch = ch2[x];
			}
		}
	cout << ch.first + 1 << ' ' << ch.second + 1;
	return 0;
}