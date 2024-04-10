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
using db = long double;
const db EPS = 1e-11, INF = 1e12;

int sgn(db x) {return x < -EPS ? -1 : x > EPS;}

struct P {
	db x, y;
	void read() {cin >> x >> y;}
	friend P operator + (const P &a, const P &b) {return (P) {a.x + b.x, a.y + b.y};}
	friend P operator - (const P &a, const P &b) {return (P) {a.x - b.x, a.y - b.y};}
	friend P operator * (const P &a, const db &k) {return (P) {a.x * k, a.y * k};}
	friend P operator / (const P &a, const db &k) {return (P) {a.x / k, a.y / k};}
	db len() { return hypotl(x, y);} // hypotl for long double
	P norm() {return *this / len();}
	P rotate(db cos, db sin) { // (x + yi) * (cos + sini)
		return (P) {x * cos - y * sin, x * sin + y * cos};
	}
};

db operator * (const P &a, const P &b) {return a.x * b.x + a.y * b.y;}
db operator & (const P &a, const P &b) {return a.x * b.y - a.y * b.x;}
bool operator < (const P &a, const P &b) { return sgn(a.x - b.x) != 0 ? sgn(a.x - b.x) < 0 : sgn(a.y - b.y) < 0;}
bool operator == (const P &a, const P &b) {return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;}


struct Circle {
	P o; db rad;

	bool inside(P x) {
		return sgn((o - x).len() - rad) <= 0;
	}
};

vector<P> get(Circle a, Circle b) {
	db d = (a.o - b.o).len();

	if (sgn(d - a.rad - b.rad) > 0) return {};

	P o = a.o + (b.o - a.o).norm() * a.rad;

	db cos = min((db) 1.0, (- b.rad * b.rad + a.rad * a.rad + d * d) / (2 * a.rad * d)); db sin = sqrt(max((db) 0.0, 1 - cos * cos));

	return {a.o + (o - a.o).rotate(cos, sin), a.o + (o - a.o).rotate(cos, -sin)};
}

bool check(vector<Circle> v) {
	vector<P> u;

	rep(i, 0, SZ(v) - 1) rep(j, i + 1, SZ(v) - 1) {
		auto o = get(v[i], v[j]);

		for (P i : o) u.pb(i);
	}

	for (Circle C : v) u.pb(C.o);

	for (P i : u) {
		bool fl = 1;

		for (Circle C : v) if (!C.inside(i)) fl = 0;

		if (fl) return 1;
	}

	return 0;
}

int tA, tB;
db dA, dB, dAA;
P C, H, S;

db calc1() {
	db l = 0, r = min(dA + tA, dB + tB) - EPS;

	rep(_, 1, 100) {
		db d = (l + r) * 0.5;
		bool fl = 0;

		// cout << d << endl;

		//  S
		vector<Circle> T = {(Circle) {C, d}, (Circle) {S, dA + tA - d}, (Circle) {H, dB + tB - d}};

		if (check(T)) fl = 1;//, cout << "111\n";

		if (fl) l = d;
		else r = d;
	}

	return l;
}

db calc2() {
	db l = dA, r = min(dAA + tA, dB + tB) - EPS;

	if (l > r) return 0;

	bool Fl = 0;
	rep(_, 1, 60) {
		db d = (l + r) * 0.5;
		bool fl = 0;

		// cout << d << endl;

		//  S

		if (sgn(d - dA) >= 0) {
			vector<Circle> T = {(Circle) {S, d - dA}, (Circle) {H, min(dAA + tA - d, dB + tB - d)}};

			if (check(T)) fl = 1, Fl = 1;
		}

		if (fl) l = d;
		else r = d;
	}

	return Fl ? l : 0;
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	cin >> tA >> tB;
	C.read(); H.read(); S.read();
	dA = (C - S).len(); dB = (C - H).len(); dAA = dA + (S - H).len();
	cerr << calc1() << ' ' << calc2() << endl;
	cout << fixed << setprecision(9) << max(calc1(), calc2()) << endl;
	return 0;
}