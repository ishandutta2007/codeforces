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
#include <stack>

using namespace std;


int n;
string s, t;
vector<int> ans;


void shift(int i) {
	if (!i) return;
	ans.push_back(i);
	reverse(s.end() - i, s.end());
	rotate(s.begin(), s.end() - i, s.end());
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s >> t;
	if (multiset<char>(s.begin(), s.end()) != multiset<char>(t.begin(), t.end())) {
		cout << -1;
		return 0;
	}

	int lo = n / 2;
	int hi = lo;
	for (int i = 0; i < n; ++i)
		if (s[i] == t[lo]) {
			shift(n - i - 1);
			shift(1);
			break;
		}

	while (s != t) {
		int len = hi - lo + 1;
		int i = len;
		while (s[i] != t[lo - 1])
			++i;
		shift(n - i - 1);
		shift(i - len + 1);
		shift(len++);
		--lo;

		if (hi + 1 == n) {
			shift(n);
			break;
		}

		i = len;
		while (s[i] != t[hi + 1])
			++i;
		shift(n - i - 1);
		shift(i - len + 1);
		shift(len++);
		++hi;
	}

	cout << ans.size() << '\n';
	for (auto &&x : ans)
		cout << x << ' ';
	return 0;
}