#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int queryCnt = 0;

struct Rect {
	int x1, y1, x2, y2;

	bool query() const {
		assert(++queryCnt <= 2019);

		cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

		int x;
		cin >> x;
		return x & 1;
	}

	Rect prefix(const int mid) const {
		return x1 == x2 ? Rect { x1, 1, x2, mid } : Rect { 1, y1, mid, y2 };
	}

	pair<int, int> f(const int mid) const {
		return x1 == x2 ? pair<int, int> { x1, mid } : pair<int, int> { mid, y1 };
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<Rect> rects;

	for (int i = 1; i <= n; ++i) {
		Rect rect { i, 1, i, n };
		if (rect.query())
			rects.push_back(rect);
	}

	if (rects.size() != 2) {
		rects.clear();

		for (int i = 1; i < n; ++i) {
			Rect rect { 1, i, n, i };
			if (rect.query())
				rects.push_back(rect);
		}
		if (rects.size() == 1)
			rects.push_back( { 1, n, n, n });
	}

	assert(queryCnt <= 1999);

	vector<pair<int, int>> res;
	for (const Rect rect : rects) {
		int lo = 1;
		int hi = n;
		while (lo < hi) {
			const int mid = (lo + hi) / 2;
			if (rect.prefix(mid).query())
				hi = mid;
			else
				lo = mid + 1;
		}
		res.push_back(rect.f(lo));
	}
	cout << "! " << res[0].first << ' ' << res[0].second << ' ' << res[1].first << ' ' << res[1].second;
	return 0;
}