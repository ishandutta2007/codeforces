#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

struct P {
	ll x, y, z;
	P() {}
	P(ll x, ll y, ll z) : x(x), y(y), z(z) {}
	bool operator ==(const P& r) const {
		return x == r.x && y == r.y && z == r.z;
	}
};

P neg(const P& p) {
	return P(-p.x, -p.y, -p.z);
};

P add(const P& a, const P& b) {
	return P(a.x + b.x, a.y + b.y, a.z + b.z);
}

P sub(const P& a, const P& b) {
	return P(a.x - b.x, a.y - b.y, a.z - b.z);
}

ll dot(const P& a, const P& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

ll norm(const P& p) {
	return dot(p, p);
}

bool cont(const vector<P>& xx, const P& val) {
	auto it = find(xx.begin(), xx.end(), val);
	return it != xx.end();
}

void output(const P& a) {
	cout << a.x << " " << a.y << " " << a.z << endl;
}

int main() {
	vector<P> p(8);
	FOR(i, 8) cin >> p[i].x >> p[i].y >> p[i].z;
	const P o = p[0];

	vector<vector<P> > shp;
	FOR(i, 7) {
		shp.emplace_back();
		P& bs = p[i + 1];
		shp.back().emplace_back(bs.x, bs.y, bs.z);
		shp.back().emplace_back(bs.x, bs.z, bs.y);
		shp.back().emplace_back(bs.y, bs.x, bs.z);
		shp.back().emplace_back(bs.y, bs.z, bs.x);
		shp.back().emplace_back(bs.z, bs.x, bs.y);
		shp.back().emplace_back(bs.z, bs.y, bs.x);
		for (P& a : shp.back()) {
			a = sub(a, o);
		}
	}

	vector<int> v(7);
	FOR(i, 7) v[i] = i;

	do {
		for (const P& a : shp[v[0]]) {
			const ll oa_nr = norm(a);
			if (oa_nr == 0) continue;
			for (const P& b : shp[v[1]]) {
				if (dot(a, b) != 0) continue;
				const ll ob_nr = norm(b);
				if (oa_nr != ob_nr) continue;
				for (const P& c : shp[v[2]]) {
					if (dot(a, c) != 0) continue;
					if (dot(a, c) != 0) continue;
					const ll oc_nr = norm(c);
					if (oa_nr != oc_nr) continue;

					const P d = add(a, b);
					const P e = add(b, c);
					const P f = add(c, a);
					const P g = add(d, c);

					if (!cont(shp[v[3]], d)) continue;
					if (!cont(shp[v[4]], e)) continue;
					if (!cont(shp[v[5]], f)) continue;
					if (!cont(shp[v[6]], g)) continue;

					puts("YES");

					vector<P> outputs(7);
					outputs[v[0]] = a;
					outputs[v[1]] = b;
					outputs[v[2]] = c;
					outputs[v[3]] = d;
					outputs[v[4]] = e;
					outputs[v[5]] = f;
					outputs[v[6]] = g;

					output(o);
					FOR(i, 7) output(add(o,outputs[i]) );
					return 0;
				}
			}
		}
	}
	while (next_permutation(v.begin(), v.end()));

	puts("NO");

	return 0;
}