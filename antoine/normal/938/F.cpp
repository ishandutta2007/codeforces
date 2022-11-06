#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>

using namespace std;

struct BitIter {
	int x;
	BitIter(int x) : x(x) {}
	bool hasNext() { return x; }
	int next() {
		int res = x ^ (x & (x - 1));
		x &= x - 1;
		return res;
	}
};

bool dp[5001][4096] = { false };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;

	const int N = s.size();
	const int M = (1 << (int)log2(s.size())) - 1;

	for (int i = 0; i <= M; ++i)
		dp[i][i] = true;

	string res(N - M, 'z');

	for (int l = 1; l <= N - M; ++l) {
		char &ch = res[l - 1];
		for (int n = l; n <= N; ++n) {
			const int m = n - l;
			if (m > M) break;
			if (dp[n - 1][m])
				ch = min(ch, s[n - 1]);
		}
		for (int n = l; n <= N; ++n) {
			const int m = n - l;
			if (m > M) break;
			dp[n][m] = dp[n - 1][m] && s[n - 1] == ch;
			for (BitIter it(m); !dp[n][m] && it.hasNext();) {
				const int j = it.next();
				dp[n][m] = dp[n - j][m - j];
			}
		}
	}

	cout << res;
	return 0;
}