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
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, t;
	cin >> s >> t;
	int n = s.size();

	sort(s.begin(), s.end());
	sort(t.rbegin(), t.rend());

	while (s.size() > (n + 1) / 2)
		s.pop_back();
	while (t.size() > n / 2)
		t.pop_back();

	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());

	int turn = 0;
	string res;
	for (; res.size() != n && (s.empty() || t.empty() || s.back() < t.back()); turn ^= 1) {
		if (!turn) {
			res += s.back();
			s.pop_back();
		}
		else {
			res += t.back();
			t.pop_back();
		}
	}

	n -= res.size();
	cout << res;
	res = "";
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());

	for (; res.size() != n; turn ^= 1) {
		if (!turn) {
			assert(!s.empty());
			res += s.back();
			s.pop_back();
		}
		else {
			assert(!t.empty());	
			res += t.back();
			t.pop_back();
		}
	}
	reverse(res.begin(), res.end());
	cout << res;
	return 0;
}