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

bool f(string &s, int i, int j) {
	if (i >= j) return true;
	return s[i] == s[j] && f(s, i + 1, j - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << fixed << setprecision(11);

	int ans = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
		for (int j = i; j < s.size(); ++j)
			if (!f(s, i, j))
				ans = max(ans, j - i + 1);
	cout << ans;
	return 0;
}