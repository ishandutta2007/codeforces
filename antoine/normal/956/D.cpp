
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

//http://codeforces.com/contest/956/problem/D

using namespace std;
typedef long long ll;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

struct Fraction {
	int a, b;
	Fraction(int a, int b) {
		int g = gcd(a, b);
		a /= g;
		b /= g;
		if (b < 0) {
			a = -a;
			b = -b;
		}
		this->a = a;
		this->b = b;
	}
	bool operator!=(const Fraction &other) const {
		return a != other.a || b != other.b;
	}
	bool operator<(const Fraction &other) const {
		return (ll)a * other.b < (ll)other.a * b;
	}
};

struct FT {
	vector<int> v;
	FT(int n) : v(vector<int>(n + 1, 0)) {}
	void update(int i, const int a) {
		for (++i; i < v.size(); i += i & -i)
			v[i] += a;
	}
	int query(int i) {
		int sum = 0;
		for (++i; i; i -= i & -i)
			sum += v[i];
		return sum;
	}
	int query(int i, int j) {
		return query(j) - query(i - 1);
	}
};

ll countInversions(const vector<int> &v) {
	FT ft(v.size());
	ll ans = 0;
	for (auto &&x : v) {
		ans += ft.query(x, v.size() - 1);
		ft.update(x, 1);
	}
	return ans;
}

ll countInversions(const vector<Fraction> &v) {
	auto vs = v;
	sort(vs.begin(), vs.end());
	map<Fraction, int> mp;
	for (auto &&x : vs)
		if (!mp.count(x)) {
			int sz = mp.size();
			mp[x] = sz;

		}
	vector<int> vi;
	for (auto &&x : v)
		vi.push_back(mp[x]);
	return countInversions(vi);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, w;
	cin >> n >> w;

	typedef pair<Fraction, Fraction> pff;
	vector<pff> vect;
	for (int i = 0; i < n; ++i) {
		int x, v;
		cin >> x >> v;
		vect.push_back({ {-x, v - w}, {-x, v + w} });
	}
	sort(vect.begin(), vect.end(), [](const pff &l, const pff &r) {
		return l.first != r.first ? l.first < r.first : r.second < l.second;
	});
	vector<Fraction> u;
	for (auto &&x : vect)
		u.push_back(x.second);
	cout << countInversions(u);
	return 0;
}