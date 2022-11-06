#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Vec {
	ll dx = 0, dy = 0;

	Vec() {
	}

	Vec(ll dx, ll dy) :
			dx(dx), dy(dy) {
	}

	Vec(const char c) {
		if (c == 'U')
			dy = 1;
		else if (c == 'D')
			dy = -1;
		else if (c == 'L')
			dx = -1;
		else if (c == 'R')
			dx = 1;
	}

	Vec operator+(const Vec &other) const {
		return Vec(dx + other.dx, dy + other.dy);
	}

	Vec operator*(const ll k) {
		return Vec(dx * k, dy * k);
	}

	ll dist(const Vec &other) const {
		return llabs(dx - other.dx) + llabs(dy - other.dy);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	Vec dest;

	{
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		dest = Vec(x2 - x1, y2 - y1);
	}

	int n;
	cin >> n;

	vector<Vec> vecs(n);
	for (Vec &v : vecs) {
		char c;
		cin >> c;
		v = Vec(c);
	}

	const ll Inf = (ll) 1e16;

	ll lo = 0;
	ll hi = Inf;
	while (lo < hi) {
		const ll mid = (lo + hi) / 2;
		const Vec curr = accumulate(vecs.begin(), vecs.end(), Vec()) * (mid / n) + accumulate(vecs.begin(), vecs.begin() + mid % n, Vec());
		if (curr.dist(dest) <= mid)
			hi = mid;
		else
			lo = mid + 1;
	}
	cout << (lo == Inf ? -1 : lo);

	return 0;
}