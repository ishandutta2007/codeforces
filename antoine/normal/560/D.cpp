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

void f(string &s, int l, int r) {
	if ((r - l + 1) & 1) return;
	const int mid = (l + r) >> 1;
	f(s, l, mid);
	f(s, mid + 1, r);
	if (s.substr(l, mid - l + 1) > s.substr(mid + 1, r - mid))
		swap_ranges(s.begin() + l, s.begin() + mid + 1, s.begin() + mid + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	f(s1, 0, s1.size() - 1);
	f(s2, 0, s2.size() - 1);
	cout << (s1 == s2 ? "YES" : "NO");
	return 0;
}