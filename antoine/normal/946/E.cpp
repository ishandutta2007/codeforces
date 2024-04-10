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

int popCnt(int x) {
	int res = 0;
	while (x) {
		res++;
		x &= x - 1;
	}
	return res;
}

using namespace std;
typedef long long ll;

string f(const string &s) {
	const int n = s.size();
	assert(n % 2 == 0);
	assert(n > 2 || stoi(s) > 11);

	int mask = 0;
	int maxIdx = -1;
	int maxDigit = 0;
	int maxMask = 0;

	for (int i = 0; i < n; ++i) {
		for (int d = !i; d + '0' < s[i]; ++d) {
			mask ^= 1 << d;
			if (popCnt(mask) <= (n - (i + 1))) {
				maxIdx = i;
				maxDigit = d;
				maxMask = mask;
			}
			mask ^= 1 << d;
		}
		mask ^= (1 << (s[i] - '0'));
	}

	if (maxIdx == -1) {
		assert(s.size() > 2);
		return string(s.size() - 2, '9');
	}

	cout << s.substr(0, maxIdx) << maxDigit;
	mask = maxMask;

	for (int i = maxIdx + 1; i < n; ++i) {
		assert(popCnt(mask) <= n - i);
		if ((mask & (1 << 9)) || popCnt(mask) <= n - (i + 2)) {
			cout << 9;
			mask ^= 1 << 9;
			continue;
		}
		break;
	}
	for (int d = 8; d >= 0; --d)
		if (mask & (1 << d)) {
			cout << d;
			mask ^= 1 << d;
		}
	return "";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << f(s) << '\n';
	}
	return 0;
}