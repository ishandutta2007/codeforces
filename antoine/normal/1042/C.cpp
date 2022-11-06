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


void f(vector<pair<int, int>> &v) {
	while (v.size() >= 2) {
		const int i = v.back().second;
		v.pop_back();
		cout << "1 " << i + 1 << ' ' << v.back().second + 1 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> pos, neg, rem;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x > 0)
			pos.emplace_back(x, i);
		else if (x < 0)
			neg.emplace_back(x, i);
		else
			rem.emplace_back(x, i);
	}

	if (neg.size() & 1) {
		sort(neg.begin(), neg.end());
		rem.push_back(neg.back());
		neg.pop_back();
	}


	pos.insert(pos.end(), neg.begin(), neg.end());

	if (pos.empty()) {
		assert(!rem.empty());
		pos.push_back(rem.front());
		rem.erase(rem.begin());
	}

	f(pos);
	f(rem);

	if (!rem.empty()) {
		cout << "2 " << rem.back().second + 1 << '\n';
	}


	return 0;
}