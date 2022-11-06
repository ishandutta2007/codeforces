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

struct Vec {
	int id;
	ll dx, dy;

	ll normSq() const {
		return dx * dx + dy * dy;
	}

	bool operator<(const Vec &other) const {
		return normSq() < other.normSq();
	}
};

ll normSq(const pair<int, int> &v) {
	return (ll)v.first * v.first + (ll)v.second * v.second;
}

Vec vecs[(int)1e5];
int ans[(int)1e5];
int chosen[(int)1e5];

void f(const int start, const int i, const int j, pair<int, int> &curr, pair<int, int> &res) {
	if (i == j) {
		if (normSq(curr) < normSq(res)) {
			res = curr;
			for (int i = start; i < j; ++i)
				ans[i] = chosen[i];
		}
	} else {
		int &chosen_i = chosen[i];
		for (chosen_i = -1; chosen_i <= 1; chosen_i += 2) {
			curr.first += chosen_i * vecs[i].dx;
			curr.second += chosen_i * vecs[i].dy;
			f(start, i + 1, j, curr, res);
			curr.first -= chosen_i * vecs[i].dx;
			curr.second -= chosen_i * vecs[i].dy;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		vecs[i].id = i;
		cin >> vecs[i].dx >> vecs[i].dy;
	}
	sort(vecs, vecs + n);
	reverse(vecs, vecs + n);

	pair<int, int> pos = { 0, 0 };
	for (int i = 0; i < n;) {
		int j = min(n, i + 5);
		pair<int, int> res = { (int)1e9, (int)1e9 };
		f(i, i, j, pos, res);
		pos = res;
		i = j;
	}

	map<int, int> mp;
	for (int i = 0; i < n; ++i)
		mp[vecs[i].id] = ans[i];
	for (auto &&x : mp)
		cout << x.second << ' ';
	return 0;
}