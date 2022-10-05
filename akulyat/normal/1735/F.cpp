#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
const ld eps = 1e-9; 
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }
 
 
int n, a, b;
vector<int> p, q;
 
 
struct Seg {
	ll init_x, init_y;
	int num;
	ld x, y;
	Seg() {}
	Seg(int p, int q, int num): init_x(q), init_y(-p), num(num) {
		x = init_x;
		y = init_y;
	}
 
	friend bool operator<(const Seg &s1, const Seg &s2) {
		if (s1.init_x * s2.init_y == s1.init_y * s2.init_x)
			return s1.num < s2.num;
		return s1.init_x * s2.init_y < s1.init_y * s2.init_x;
	}
	Seg operator*=(ld ratio) { x *= ratio; y *= ratio; return *this; }
 
	void show() {
		cout << "Seg(" << x << ' ' << y << ")";
	}
};
 
struct Point {
	ld x, y;
	Point() {}
	Point(int a, int b): x(b), y(a) {}
	Point operator+=(const Point &v) { x += v.x; y += v.y; return *this; }
    Point operator-=(const Point &v) { x -= v.x; y -= v.y; return *this; }
	Point operator+=(const Seg &v) { x += v.x; y += v.y; return *this; }
    Point operator-=(const Seg &v) { x -= v.x; y -= v.y; return *this; }
 
	void show() {
		cout << "Point(" << x << ' ' << y << ")";
	}
};
 
 
struct Stock {
	Point best_a;
	Point best_b;
	multiset<Seg> segs;
 
	Stock(int a, int b) {
		best_a = Point(a, 0);
		best_b = Point(0, b);
 
		Seg seg_1 = Seg(a, 0, -2);
		Seg seg_2 = Seg(0, b, -1);
		if (a)
			segs.insert(seg_1);
		if (b)
			segs.insert(seg_2);
	}
 
	void add_seg(int p, int q, int num) {
		Seg new_seg = Seg(2 * p, 2 * q, num);
		segs.insert(new_seg);
 
		Point shift(p, -q);
		best_a += shift;
		best_b -= shift;
 
		cut_left();
		cut_down();
	}
 
	void cut_left() {
		while (best_a.x < 0) {
			Seg l_seg = *segs.begin();
			Point new_best_a = best_a;
			new_best_a += l_seg;
 
			if (new_best_a.x > eps) {
				ld ratio = new_best_a.x / l_seg.x;
				Seg l_seg_left = l_seg;
				l_seg_left *= ratio;
				segs.erase(segs.find(l_seg));
				segs.insert(l_seg_left);
				new_best_a -= l_seg_left;
				new_best_a.x = max(new_best_a.x, (ld)0);
			} else {
				segs.erase(segs.begin());
			}
			best_a = new_best_a;
		}
	}
 
	void cut_down() {
		while (best_b.y < 0) {
			Seg d_seg = *segs.rbegin();
			Point new_best_b = best_b;
			new_best_b -= d_seg;
 
			if (new_best_b.y > eps) {
				ld ratio = new_best_b.y / -d_seg.y;
				Seg d_seg_left = d_seg;
				d_seg_left *= ratio;
				segs.erase(segs.find(d_seg));
				segs.insert(d_seg_left);
				new_best_b += d_seg_left;
				new_best_b.y = max(new_best_b.y, (ld)0);
			} else {
				segs.erase(segs.find(d_seg));
			}
			best_b = new_best_b;
		}
	}
 
	void print_best() {
		cout << best_a.y << '\n';
	}
 
	void show() {
		cout << "----\tStock\t----\n";
		cout << "best_a = ";
		best_a.show();
		cout << endl;
 
		Point cur = best_a;
		for (auto seg : segs) {
			cur += seg;
			cout << "\t";
			cur.show();
			cout << endl;
		}
 
		cout << "best_b = ";
		best_b.show();
		cout << endl;
		cout << "----\tEnd\t----\n\n";
	}
};
 
void solve() {
	cin >> n >> a >> b;
	p.resize(n);
	q.resize(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	for (int i = 0; i < n; i++)
		cin >> q[i];
 
	Stock st(a, b);
	for (int i = 0; i < n; i++) {
		st.add_seg(p[i], q[i], i);
		st.print_best();
	}
 
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();
 
	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}