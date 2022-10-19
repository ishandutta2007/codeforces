#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

using db = double;

const db EPS = 1e-9, INF = 1e12;

int sgn(db x) {return x < -EPS ? -1 : x > EPS;}

struct P {
	db x, y;
	db norm() { return hypot(x, y);} // hypot for double
	P rotate(db cos, db sin) { // (x + yi) * (cos + sini)
		return (P) {x * cos - y * sin, x * sin + y * cos};
	}

	void Print() {
		printf("(%Lf %Lf)\n", x, y);
	}

} ;

P operator + (const P &a, const P &b) {return (P) {a.x + b.x, a.y + b.y};}
P operator - (const P &a, const P &b) {return (P) {a.x - b.x, a.y - b.y};}
P operator * (const P &a, const db &k) {return (P) {a.x * k, a.y * k};}
P operator / (const P &a, const db &k) {return (P) {a.x / k, a.y / k};}
db operator * (const P &a, const P &b) {return a.x * b.x + a.y * b.y;}
db operator & (const P &a, const P &b) {return a.x * b.y - a.y * b.x;}

bool on(P p,  P a,  P b) {
	return fabs((a - p) & (b - p)) / (a - b).norm() <= EPS && sgn((a - p) * (b - p)) <= 0;
}

bool cross(const P &a, const P &b, const P &c, const P &d) {
	return sgn((a - c) & (b - c)) * sgn((a - d) & (b - d)) < 0;
}

bool intersect(const P &a, const P &b, const P &c, const P &d) {
	return on(c, a, b) || on(d, a, b) || on(a, c, d) || on(b, c, d) || (cross(a, b, c, d) && cross(c, d, a, b));
}

const int N = 25015;

int n;

db curx;

P s0[N], s[N], t[N], d[N];

db cury(int i) { return s[i].y + (t[i].y - s[i].y) * (curx - s[i].x) / (t[i].x - s[i].x); }

struct Rule {
	bool operator()(const int& u, const int &v) const {
		return cury(u) < cury(v);
	}
};

bool intersect(int u, int v) {
	return intersect(s[u], t[u], s[v], t[v]);
}

set<int, Rule>::iterator pos[N];

bool check(db tim) {
	vector<pair<P, int>> Event;

	rep(i, 1, n) {
		s[i] = s0[i];
		t[i] = s0[i] + d[i] * tim;

		if (s[i].x > t[i].x) swap(s[i], t[i]);

		Event.emplace_back(s[i],  i);
		Event.emplace_back(t[i], -i);

	}

	sort(all(Event), [&](auto u, auto v) { return u.fi.x < v.fi.x;});
	set<int, Rule> S;

	for (auto [u, _i] : Event) {
		curx = u.x;
		int i = abs(_i);

		if (_i > 0) {
			auto it = S.lower_bound(i);

			if (it != S.end())
				if (intersect(i, *it)) return 1;

			if (it != S.begin())
				if (intersect(i, *--it)) return 1;

			pos[i] = S.insert(i).fi;

		} else {
			auto it = S.erase(pos[i]);

			if (it != S.begin() && it != S.end()) {
				if (intersect(*prev(it), *it)) return 1;
			}
		}
	}

	return 0;
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	rep(i, 1, n) {
		int x, y, dx, dy, v;
		cin >> x >> y >> dx >> dy >> v;
		s0[i].x = static_cast<db>(x); s0[i].y = static_cast<db>(y);
		d[i].x = static_cast<db>(dx); d[i].y = static_cast<db>(dy);
		d[i] = d[i] / d[i].norm() * v;
	}

	db l = 0, r = INF;

	rep(_, 0, 80) {
		db mid = (l + r) / 2;
		check(mid) ? r = mid : l = mid;
	}

	if (l >= INF - 1) puts("No show :(");
	else {
		cout << fixed << setprecision(20) << l << endl;
	}

	return 0;
}