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

int len(pair<int, int> &p) {
	return p.second - p.first;
}

int f(const multiset<pair<int, int>> &ms) {
	int l = 0, r = 2e9;
	for (auto &&x : ms) {
		l = max(l, x.first);
		r = min(r, x.second);
	}
	return r - l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	multiset<pair<int, int>> ms;

	pair<int, int> cand1, cand2;

	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		pair<int, int> p = make_pair(l, r);
		ms.insert(p);
		if (!i)
			cand1 = cand2 = p;
		else {
			if (l > cand1.first || (l == cand1.first && len(p) < len(cand1)))
				cand1 = p;
			if (r < cand2.second || (r == cand2.second && len(p) < len(cand2)))
				cand2 = p;
		}
	}

	int ans = 0;
	for (auto cand : { cand1, cand2 }) {
		ms.erase(ms.find(cand));
		ans = max(ans, f(ms));
		ms.insert(cand);
	}
	cout << ans << endl;
	return 0;
}