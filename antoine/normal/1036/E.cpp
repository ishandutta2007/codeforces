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


ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

struct Fract {
	ll a = 0, b = 0;
	Fract() {};
	Fract(ll a, ll b) : a(a), b(b) {}
	Fract(Fract a, Fract b) {
		a.reduce();
		b.reduce();
		this->a = a.a * b.b;
		this->b = a.b * b.a;
		reduce();
	}

	bool valid() const { return b != 0; }

	Fract operator*(const ll x) const {
		return Fract(a*x, b);
	}

	Fract operator-() const {
		return Fract(-a, b);
	}

	Fract operator+(const ll x) const {
		return{ a + b*x, b };
	}

	Fract operator+(const Fract other) const {
		return{ a*other.b + other.a * b, b*other.b };
	}

	Fract operator-(const Fract other) const {
		return{ a*other.b - other.a * b, b*other.b };
	}

	Fract operator*(const Fract other) const {
		return Fract(a * other.a, b * other.b);
	}

	bool operator==(Fract other) {
		reduce(), other.reduce();
		return a == other.a && b == other.b;
	}

	void reduce() {
		assert(b);
		const ll g = gcd(a, b);
		assert(g);
		a /= g;
		b /= g;
		if (b < 0) {
			a = -a;
			b = -b;
		}
	}

	bool isLL() {
		reduce();
		return b == 1;
	}

	ll toLL() {
		assert(isLL());
		return a;
	}
};

struct Line {
	Fract a, b;
	ll fixX;

	Line(ll x1, ll y1, ll x2, ll y2) {
		if (x1 == x2) {
			a = b = Fract(0, 0);
			fixX = x1;
		}
		else {
			a = Fract(y2 - y1, x2 - x1);
			b = -a * x1 + y1;
		}
	}

	bool vertical() const {
		return !a.valid();
	}

	Fract at(Fract x) const {
		assert(!vertical());
		return a*x + b;
	}

	Fract intersect(const Line other) const {
		if (vertical()) {
			assert(!other.vertical());
			return Fract(fixX, 1);
		}
		if (other.vertical())
			return Fract(other.fixX, 1);

		return Fract(b - other.b, other.a - a);
		// a1 x + b1 = a2 x + b2
		// (a1 - a2) x = (b2 - b1)
		// x = (b2 - b1) / (a1 - a2)
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<ll> x1(n), y1(n), x2(n), y2(n);
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		res += 1 + gcd(llabs(x2[i] - x1[i]), llabs(y2[i] - y1[i]));
	}

	map<pair<ll, ll>, vector<pair<int, int>>> occ;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			Line linei(x1[i], y1[i], x2[i], y2[i]);
			Line linej(x1[j], y1[j], x2[j], y2[j]);
			if ((linei.vertical() && linej.vertical())
				|| (!linei.vertical() && !linej.vertical() && linei.a == linej.a)) continue;
			Fract xf = linei.intersect(linej);
			Fract yf = (linei.vertical() ? linej : linei).at(xf);
			if (!xf.isLL() || !yf.isLL()) continue;
			const ll x = xf.toLL();
			const ll y = yf.toLL();

			bool ok = true;
			for (int k : {i, j})
				ok = ok && min(x1[k], x2[k]) <= x && x <= max(x1[k], x2[k])
				&& min(y1[k], y2[k]) <= y && y <= max(y1[k], y2[k]);
			if (ok)
				occ[{x, y}].emplace_back(i, j);
		}
	}
	// assert(!occ.empty());

	for (auto &&x : occ) {
		int cnt = 2;
		while (cnt * (cnt - 1) / 2 < x.second.size())
			++cnt;
		if (cnt * (cnt - 1) / 2 != x.second.size()) {
			cout << "SZ: " << x.second.size() << endl;
			for (auto &&y : x.second)
				cout << y.first << ' ' << y.second <<
				" (" << x1[y.first] << ", " << y1[y.first] << "), (" << x2[y.first] << ", " << y2[y.first] << ")\t\t" <<
				" (" << x1[y.second] << ", " << y1[y.second] << "), (" << x2[y.second] << ", " << y2[y.second] << ")\n";
		}
		// assert(cnt * (cnt - 1) / 2 == x.second);
		res -= cnt - 1;
	}

	cout << res << '\n';
	return 0;
}