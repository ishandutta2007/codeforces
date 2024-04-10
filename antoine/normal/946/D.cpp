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
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

void prec(const string &s, int * pre) {
	vector<int> cs(s.size() + 1, 0);
	for (int i = 0; i < s.size(); ++i)
		cs[i + 1] = cs[i] + s[i] - '0';
	for (int i = 0; i < cs.size(); ++i)
		for (int j = i; j < cs.size(); ++j) {
			int &res = pre[cs.back() - (cs[j] - cs[i])];
			res = min(res, j - i);
		}
}

int n, m, k;
int pre[500][500];
int dp[501][501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		fill(begin(pre[i]), end(pre[i]), 1 << 30);
		prec(s, pre[i]);
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int k = ::k; k >= 0; --k) {
			int &res = dp[i][k] = 1 << 30;
			for (int x = k; x >= 0; --x)
				res = min(res, pre[i][x] + dp[i + 1][k - x]);
		}
	}
	cout << dp[0][k];
	return 0;
}