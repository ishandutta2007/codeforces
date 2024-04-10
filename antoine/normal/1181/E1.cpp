#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

struct Rect {
	int x1, y1, x2, y2;
};

const int MxN = (int) 1e5 + 9;
Rect a[MxN + 9];

auto compX1 = [](const int i, const int j) {
	int diff = a[i].x1 - a[j].x1;
	return diff ? diff < 0 : i < j;
};
auto compX2 = [](const int i, const int j) {
	int diff = a[i].x2 - a[j].x2;
	return diff ? diff > 0 : i < j;
};
auto compY1 = [](const int i, const int j) {
	int diff = a[i].y1 - a[j].y1;
	return diff ? diff < 0 : i < j;
};
auto compY2 = [](const int i, const int j) {
	int diff = a[i].y2 - a[j].y2;
	return diff ? diff > 0 : i < j;
};

template<class T> bool f(T first, T last);

bool f(set<int, decltype(compX1)> &sx1, set<int, decltype(compX2)> &sx2, set<int, decltype(compY1)> &sy1, set<int, decltype(compY2)> &sy2) {
	assert(sx1.size() == sx2.size());
	assert(sy1.size() == sy2.size());
	assert(sx1.size() == sy1.size());
	const int sz = (int) sx1.size();
	if (sz <= 1) {
		assert(sz == 1);
		return true;
	}

	auto itX1 = sx1.begin();
	auto itX2 = sx2.begin();
	auto itY1 = sy1.begin();
	auto itY2 = sy2.begin();

	static const ll Inf = (int) 1e9 + 9;

	int mx1 = -Inf;
	int mx2 = +Inf;
	int my1 = -Inf;
	int my2 = +Inf;

	for (int rep = 0; rep < sz / 2; ++rep) {
		mx1 = max(mx1, a[*itX1].x2);
		mx2 = min(mx2, a[*itX2].x1);
		my1 = max(my1, a[*itY1].y2);
		my2 = min(my2, a[*itY2].y1);

		++itX1, ++itX2, ++itY1, ++itY2;

		if (mx1 <= a[*itX1].x1) {
			//////DBG(mx1)
			//////DBG(a[*itX1].x1)

			//cerr << "sep x1" << endl;

			set<int, decltype(compX1)> sx1N(compX1);
			set<int, decltype(compX2)> sx2N(compX2);
			set<int, decltype(compY1)> sy1N(compY1);
			set<int, decltype(compY2)> sy2N(compY2);

			while (sx1.begin() != itX1) {
				const int x = *sx1.begin();

				sx1.erase(x);
				sx2.erase(x);
				sy1.erase(x);
				sy2.erase(x);

				sx1N.insert(x);
				sx2N.insert(x);
				sy1N.insert(x);
				sy2N.insert(x);
			}

			return f(sx1N, sx2N, sy1N, sy2N) && f(sx1, sx2, sy1, sy2);
		}
		if (mx2 >= a[*itX2].x2) {
			//cerr << "sep x2" << endl;

			set<int, decltype(compX1)> sx1N(compX1);
			set<int, decltype(compX2)> sx2N(compX2);
			set<int, decltype(compY1)> sy1N(compY1);
			set<int, decltype(compY2)> sy2N(compY2);

			while (sx2.begin() != itX2) { // 2 changes
				const int x = *sx2.begin(); // 1 change

				sx1.erase(x);
				sx2.erase(x);
				sy1.erase(x);
				sy2.erase(x);

				sx1N.insert(x);
				sx2N.insert(x);
				sy1N.insert(x);
				sy2N.insert(x);
			}

			return f(sx1N, sx2N, sy1N, sy2N) && f(sx1, sx2, sy1, sy2);
		}
		if (my1 <= a[*itY1].y1) {
			//cerr << "sep y1" << endl;

			set<int, decltype(compX1)> sx1N(compX1);
			set<int, decltype(compX2)> sx2N(compX2);
			set<int, decltype(compY1)> sy1N(compY1);
			set<int, decltype(compY2)> sy2N(compY2);

			while (sy1.begin() != itY1) { // 2 changes
				const int x = *sy1.begin(); // 1 change

				sx1.erase(x);
				sx2.erase(x);
				sy1.erase(x);
				sy2.erase(x);

				sx1N.insert(x);
				sx2N.insert(x);
				sy1N.insert(x);
				sy2N.insert(x);
			}

			return f(sx1N, sx2N, sy1N, sy2N) && f(sx1, sx2, sy1, sy2);
		}
		if (my2 >= a[*itY2].y2) {
			//cerr << "sep y2" << endl;

			set<int, decltype(compX1)> sx1N(compX1);
			set<int, decltype(compX2)> sx2N(compX2);
			set<int, decltype(compY1)> sy1N(compY1);
			set<int, decltype(compY2)> sy2N(compY2);

			while (sy2.begin() != itY2) { // 2 changes
				const int x = *sy2.begin(); // 1 change

				sx1.erase(x);
				sx2.erase(x);
				sy1.erase(x);
				sy2.erase(x);

				sx1N.insert(x);
				sx2N.insert(x);
				sy1N.insert(x);
				sy2N.insert(x);
			}

			return f(sx1N, sx2N, sy1N, sy2N) && f(sx1, sx2, sy1, sy2);
		}
	}

	return false;
}

template<class It> bool f(It first, It last) {
	set<int, decltype(compX1)> sx1(compX1);
	set<int, decltype(compX2)> sx2(compX2);
	set<int, decltype(compY1)> sy1(compY1);
	set<int, decltype(compY2)> sy2(compY2);
	while (first < last) {
		sx1.insert(*first);
		sx1.insert(*first);
		sx1.insert(*first);
		sx1.insert(*first);
		++first;
	}
	return f(sx1, sx2, sy1, sy2);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;

	set<int, decltype(compX1)> sx1(compX1);
	set<int, decltype(compX2)> sx2(compX2);
	set<int, decltype(compY1)> sy1(compY1);
	set<int, decltype(compY2)> sy2(compY2);

	for (int x = 0; x < n; ++x) {
		sx1.insert(x);
		sx2.insert(x);
		sy1.insert(x);
		sy2.insert(x);
	}

	const bool yes = f(sx1, sx2, sy1, sy2);
	cout << (yes ? "YES" : "NO");
	return 0;
}