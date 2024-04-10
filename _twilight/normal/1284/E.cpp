#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

// missed charactors / ?

template <typename T>
boolean vmin(T& a, T b) {
	return (a > b) ? (a = b, true) : (false);
}
template <typename T>
boolean vmax(T& a, T b) {
	return (a < b) ? (a = b, true) : (false);
}

template <typename T>
T smax(T x) {
	return x;
}
template <typename T, typename ...K>
T smax(T a, const K &...args) {
	return max(a, smax(args...));
}

template <typename T>
T smin(T x) {
	return x;
}
template <typename T, typename ...K>
T smin(T a, const K &...args) {
	return min(a, smin(args...));
}

// debugging lib

#define VN(x) #x
#define Vmsg(x) VN(x) << " = " << (x)
#define printv(x) cerr << VN(x) << " = " << (x);
#define debug(...) fprintf(stderr, __VA_ARGS__);

template <typename A, typename B>
ostream& operator << (ostream& os, const pair<A, B>& z) {
	os << "(" << z.first << ", " << z.second << ')';
	return os;
}
template <typename T>
ostream& operator << (ostream& os, const vector<T>& a) {
	boolean isfirst = true;
	os << "{";
	for (auto z : a) {
		if (!isfirst) {
			os << ", ";
		}
		os << z;
		isfirst = false;
	}
	os << '}';
	return os;
}

#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define ll long long
#define ull unsigned long long

const int inf = (signed) (~0u >> 2);
const ll llf = (signed ll) (~0ull >> 2);

#define pb push_back
#define eb emplace_back
#define fi first
#define sc second

typedef class Point {
	public:
		ll x, y;
		
		Point() {	}
		Point(ll x, ll y) : x(x), y(y)  {	}

		void read() {
			cin >> x >> y;
		}
} Point;

Point operator - (Point a, Point b) {
	return Point(a.x - b.x, a.y - b.y);
}
double cross(Point a, Point b) {
	return 1.0 * a.x * b.y - 1.0 * a.y * b.x;
}

typedef long double ld;

const ld pi = acos(ld(-1));

int n;

typedef class Data {
	public:
		ld arc;
		int sgn;
		int id;

		Data(ld arc, int sgn, int id) : arc(arc), sgn(sgn), id(id) {	}

		boolean operator < (Data b) const {
			return arc < b.arc;
		}
} Data;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	vector<Point> P (n);
	for (auto &p : P) {
		p.read();
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		vector<Data> E;
		int cnt = -114514;
		for (int j = 0; j < n; j++) {
			if (i ^ j) {
				ld arc = atan2(ld(P[j].y - P[i].y), ld(P[j].x - P[i].x));
				E.eb(arc, -1, j);
				arc = atan2(ld(P[i].y - P[j].y), ld(P[i].x - P[j].x));
				E.eb(arc, 1, j);
			}

		}
		sort(E.begin(), E.end());
		for (auto e : E) {
			if (e.sgn < 0) {
				cnt--;
				if (cnt < 0) {
					cnt = 0;
					Point d = P[e.id] - P[i];
					for (int k = 0; k < n; k++) {
						if (k == i || k == e.id) continue;
						cnt += cross(d, P[k] - P[i]) > 0;
					}
				}
				ans += 1ll * cnt * (cnt - 1) * (cnt - 2);
			} else {
				cnt++;
			}
		}
	}
	ans = ans / 6;
	ans = 1ll * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24 - ans;
	cout << ans << '\n';
	return 0;
}