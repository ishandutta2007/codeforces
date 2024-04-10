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

const int MaxN = (int) 5e5;

int n;
string s, t;
ll occ[MaxN + 9];

void f(const int i, const bool b1, const bool b2) {
	if (!b1 && !b2) {
		++occ[n - i];
		return;
	}
	if (i == n)
		return;
	for (char c = 'a'; c <= 'b'; ++c) {
		if (b1 && c < s[i])
			continue;
		if (b2 && c > t[i])
			continue;
		f(i + 1, b1 && c == s[i], b2 && c == t[i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int k;
	cin >> n >> k >> s >> t;

	ll ans = n;
	k--;

	if (k) {
		for (int i = 0; i < n; ++i)
			if (s[i] != t[i]) {
				ans += n - i;
				k--;
				break;
			}
	}

	f(0, true, true);

	ll lazy = 0;

	for (int i = n; i >= 0; --i) {
		occ[i] += lazy;

		const ll taken = min((ll) k, occ[i]);
		k -= taken;
		lazy += taken;
		ans += taken * (i + 1LL);
	}
	cout << ans << endl;
	return 0;
}