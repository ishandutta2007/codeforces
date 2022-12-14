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
const ll INF = 1LL << 61;
bool cmpA;
struct Line { // ax+b. xl = the x-coord of intersection with previous line in set
	ll a, b;
	mutable long double xl;
	bool operator <(const Line &l) const {
		if (cmpA)
			return a < l.a;
		else
			return xl < l.xl;
	}
};
struct DynamicHull: multiset<Line> {
	iterator prev(iterator y) {
		return --y;
	} // skip if using c++0x/c++11
	iterator next(iterator y) {
		return ++y;
	} // skip if using c++0x/c++11
	bool bad(iterator y) {
		iterator z = next(y), x;
		if (y == begin()) {
			if (z == end())
				return 0;
			return y->a == z->a && y->b <= z->b;
		}
		x = prev(y);
		if (z == end())
			return y->a == x->a && y->b <= x->b;
		return 1.0L * (x->b - y->b) * (z->a - y->a) >= 1.0L * (y->b - z->b) * (y->a - x->a);
	}
	void add(ll a, ll b) { // add a line ax+b to the convex hull
		cmpA = 1;
		iterator y = insert((Line ) { a, b, -INF });
		if (bad(y)) {
			erase(y);
			return;
		}
		while (next(y) != end() && bad(next(y)))
			erase(next(y));
		while (y != begin() && bad(prev(y)))
			erase(prev(y));
		if (next(y) != end())
			next(y)->xl = 1.0L * (y->b - next(y)->b) / (next(y)->a - y->a);
		if (y != begin())
			y->xl = 1.0L * (y->b - prev(y)->b) / (prev(y)->a - y->a);
	}
	ll eval(ll x) { // find max ax+b, over all lines added, for given x
		if (empty())
			return -INF;
		cmpA = 0;
		iterator it = prev(lower_bound((Line ) { 0, 0, 1.0L * x }));
		return it->a * x + it->b;
	}
};

struct Rect {
	ll x, y, a;
	bool operator<(const Rect &other) const {
		return x < other.x;
	}
};

const int MaxN = (int) 1e6 + 9;
Rect rects[MaxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> rects[i].x >> rects[i].y >> rects[i].a;

	sort(rects, rects + n);

	DynamicHull hull;
	hull.add(0,0);

	ll curr = 0;
	for_each(rects, rects + n, [&](const Rect &rect) {
		curr = max(curr, -rect.a + rect.x * rect.y + hull.eval(-rect.y));
		hull.add(rect.x, curr);
	});
	cout << curr << '\n';
	return 0;
}