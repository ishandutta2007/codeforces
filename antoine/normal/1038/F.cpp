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

int n;
string s;
map<string, pair<int, int>> mp;
pair<int, int> M[41][41][2];

bool ok(string &t) {
	for (int i = 0; i < n; ++i) {
		if (equal(s.begin(), s.end(), t.begin()))
			return true;
		rotate(t.begin(), t.begin() + 1, t.end());
	}
	return false;
}

bool ok(int pre, pair<int, int> suff) {
	string s1 = s.substr(s.size() - pre, s.size());
	string s2 = s.substr(suff.first, suff.second - suff.first);
	s1.resize(n - s2.size(), 'x');
	s1 += s2;
	assert(s1.size() == n);
	const bool res = ok(s1);
	return res;
}

map<tuple<int, int, pair<int, int>>, ll> dp;

ll f(const int i, const int pre, const pair<int, int> curr) {
	const auto tup = make_tuple(i, pre, curr);
	if (dp.count(tup)) return dp.at(tup);
	ll &res = dp[tup] = 0;
	if (curr.second - curr.first == s.size())
		return res = 1LL << (n - i);
	if (i == n)
		return res = ok(pre, curr);
	for (int c = 0; c < 2; ++c) {
		const pair<int, int> _curr = M[curr.first][curr.second][c];
		const int _pre = _curr.second == s.size() && _curr.second - _curr.first == i + 1 ? i + 1 : pre;
		res += f(i + 1, _pre, _curr);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> s;
	for (int i = 0; i < s.size(); ++i)
		for (int j = i; j <= s.size(); ++j)
			mp[s.substr(i, j - i)] = { i, j };


	for (int i = 0; i < s.size(); ++i)
		for (int j = i; j <= s.size(); ++j) {
			for (char c = '0'; c <= '1'; ++c) {
				string t = s.substr(i, j - i) + c;
				while (!mp.count(t))
					t = t.substr(1);
				M[i][j][c - '0'] = mp.at(t);
			}
		}

	cout << f(0, 0, { 0, 0 });
	return 0;
}