#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <array>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, p;
	string s;
	cin >> n >> p >> s;

	--p;
	p = min(p, n - 1 - p);

	int ans = 0;
	int l = p;
	int r = p;

	for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
		if (s[i] != s[j]) {
			int diff = abs(s[i] - s[j]);
			ans += min(diff, 26 - diff);
			l = min(l, i);
			r = max(r, i);
		}
	}

	ans += min(p - l, r - p) + r - l;

	cout << ans;
	return 0;
}