#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ldouble;

int n;
int x[(int) 1e5];
int y[(int) 1e5];

ldouble sq(ldouble x) {
	return x * x;
}
const double eps = 1e-8;

bool f(const ldouble R) {
	pair<ldouble, ldouble> range = { -1e8, 1e8 };

	for (int i = 0; i < n; ++i) {
		ldouble dy;
		if(R <= x[i] + eps) {
			dy = R * R - sq(x[i] - R);
		} else {
			dy = 2*R*x[i] - sq(x[i]);
		}
		if (dy < 0)
			return false;
		dy = sqrt(dy);

		range.first = max(range.first, y[i] - dy);
		range.second = min(range.second, y[i] + dy);
	}

	return range.first <= range.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(10);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		swap(x[i], y[i]);
	}

	const bool hasNeg = any_of(x, x + n, [](const int &v) {return v < 0;});
	const bool hasPos = any_of(x, x + n, [](const int &v) {return v > 0;});
	if (hasNeg && hasPos) {
		cout << "-1\n";
		return 0;
	}
	for (auto &&v : x)
		v = abs(v);

	ldouble lo = 0;
	ldouble hi = 1e16;

	function<ldouble(ldouble, ldouble)> getMid;
	if (f(1)) {
		hi = 1;
		getMid = [](ldouble x, ldouble y) {return (x + y) / 2.0;};
	} else {
		lo = 1;
		getMid = [](ldouble x, ldouble y) {return sqrt(x*y);};
	}

	for (int rep = 0; rep <= 200; ++rep) {
		const ldouble mid = getMid(lo, hi);
		assert(lo <= mid && mid <= hi);
		if (f(mid))
			hi = mid;
		else
			lo = mid;
	}
	cerr << lo << ' ' << hi << endl;
	cout << lo << '\n';
	return 0;
}