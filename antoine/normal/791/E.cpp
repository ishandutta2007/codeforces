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


int dp[76][76][76][2];

pair<int, string> eraseFirstOf(const string s, const char c) {
	int i = s.find_first_of(c);
	assert(i != string::npos);
	string t = s;
	t.erase(i, 1);
	return{ i, t };
}

int f(int cV, int cK, int cX, bool b, const string s) {
	assert(cV + cK + cX == s.size());
	if (s.empty()) return 0;
	int &res = dp[cV][cK][cX][b];
	if (res != -1) return res;
	res = (int)1e9;
	if (cV) {
		auto next = eraseFirstOf(s, 'V');
		res = min(res, next.first + f(cV - 1, cK, cX, true, next.second));
	}
	if (cK && !b) {
		auto next = eraseFirstOf(s, 'K');
		res = min(res, next.first + f(cV, cK - 1, cX, false, next.second));
	}
	if (cX) {
		auto next = eraseFirstOf(s, 'X');
		res = min(res, next.first + f(cV, cK, cX - 1, false, next.second));
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof dp);
	
	int n;
	string s;
	cin >> n >> s;
	replace_if(s.begin(), s.end(), [](const char c) { return c != 'K' && c != 'V'; }, 'X');
	int cV = count(s.begin(), s.end(), 'V');
	int cK = count(s.begin(), s.end(), 'K');
	int cX = count(s.begin(), s.end(), 'X');
	assert(cV + cK + cX == s.size());
	cout << f(cV, cK, cX, false, s);
	return 0;
}