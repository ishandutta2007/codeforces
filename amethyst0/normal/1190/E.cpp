#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

struct vt {
	ld x, y;

	vt() {

	}

	vt(ld x, ld y) : x(x), y(y) {

	}
};

vt operator -(vt a, vt b) {
	a.x -= b.x;
	a.y -= b.y;

	return a;
}

vt operator *(vt a, ld x) {
	a.x *= x;
	a.y *= x;

	return a;
}

vt operator +(vt a, vt b) {
	a.x += b.x;
	a.y += b.y;

	return a;
}

ld dst(vt a) {
	return hypotl(a.x, a.y);
}

ld operator %(vt a, vt b) {
	return a.x * b.y - a.y * b.x;
}

vt norm(vt a) {
	ld d = dst(a);
	a.x /= d;
	a.y /= d;

	return a;
}

vt rot(vt a) {
	return vt(-a.y, a.x);
}

ld ang(vt a) {
	return atan2l(a.y, a.x);
}

pair <ld, ld> get_inter(vt a, vt o, ld r) {
	ld d = dst(a - o);

	ld ang = acosl(r / d);

	ld cur = atan2l(a.y, a.x);

	return mp(cur - ang, cur + ang);
}

const ld eps = 1e-18;

int tp(vt a) {
	if ((abs(a.y) < eps && a.x > eps) || a.y > eps) {
		return 0;
	}

	return 1;
}

bool operator <(vt a, vt b) {
	int tpa = tp(a), tpb = tp(b);

	if (tpa != tpb) {
		return tpa < tpb;
	}

	return a % b > eps;
}

bool operator ==(vt a, vt b) {
	return !(a < b) && !(b < a);
}

const int maxn = (int)1e5 + 10;
vt v[maxn];

int n, m;

const int maxlog = 17;
int d[maxlog][2 * maxn];

bool cmp(pii a, pii b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}

	return a.first > b.first;
}

bool solve(vector <pii> &s, int c) {
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i].first > s[i].second) {
			s[i].second += c;
		}
	}

	sort(s.begin(), s.end(), cmp);

	int le = -1;

	vector <pii> g;

	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i].first > le) {
			le = s[i].first;
			g.push_back(s[i]);
		}
	}

	int re = g[0].second;

	if (re < c) {
		while (g.back().second - c >= re) {
			g.pop_back();
		}
	}

	s = g;

	for (int i = 0; i < (int)g.size(); i++) {
		s.push_back(mp(g[i].first + c, g[i].second + c));
	}

	for (int i = 0; i < maxlog; i++) {
		d[i][(int)s.size()] = (int)s.size();
	}

	for (int i = (int)s.size() - 1; i >= 0; i--) {
		int r = s[i].second;

		int p = lower_bound(s.begin(), s.end(), mp(r + 1, -1)) - s.begin();
		d[0][i] = p;

		for (int j = 1; j < maxlog; j++) {
			d[j][i] = d[j - 1][d[j - 1][i]];
		}
	}

	for (int i = 0; i <= (int)s.size() - (int)g.size(); i++) {
		int p = i;

		for (int j = 0; j < maxlog; j++) {
			if ((m >> j) & 1) {
				p = d[j][p];
			}
		}

		if (p - i >= (int)g.size()) {
			return true;
		}
	}

	return false;
}

const ld pi = acos(-1.0);

void corr(ld &ang) {
	if (ang < -pi) {
		ang += 2 * pi;
	}

	if (ang >= pi) {
		ang -= 2 * pi;
	}
}

bool good(ld r) {
	vector <pair <ld, ld> > s;
	vector <ld> f;

	cout.precision(30);
	cout.fixed;

	for (int i = 0; i < n; i++) {
		s.push_back(get_inter(v[i], vt(0, 0), r));
		corr(s.back().first);
		corr(s.back().second);
		f.push_back(s.back().first);
		f.push_back(s.back().second);
	}

	sort(f.begin(), f.end());
	f.resize(unique(f.begin(), f.end()) - f.begin());

	vector <pii> seg;

	for (int i = 0; i < (int)s.size(); i++) {
		int lm = lower_bound(f.begin(), f.end(), s[i].first) - f.begin();
		int rm = lower_bound(f.begin(), f.end(), s[i].second) - f.begin();

		seg.push_back(mp(lm, rm));
	}

	return solve(seg, (int)f.size());
}

int main() {
	cin >> n >> m;

	ld r = 1e9;

	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
		//v[i].x = rand() - RAND_MAX / 2;
		//v[i].y = rand() - RAND_MAX / 2;

		r = min(r, dst(v[i]));
	}

	ld l = 0;

	for (int i = 0; i < 40; i++) {
		ld md = (l + r) / 2;

		if (good(md)) {
			l = md;
		}
		else {
			r = md;
		}
	}

	printf("%.20lf\n", (double)l);

	//system("pause");
}