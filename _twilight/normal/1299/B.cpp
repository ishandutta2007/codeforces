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

typedef class point_t {
	public:
		int x, y;

		point_t() {	}
		point_t(int x, int y) : x(x), y(y) {	}
} point_t;

point_t operator - (point_t a, point_t b) {
	return point_t(a.x - b.x, a.y - b.y);
}

int n;

int main() {
	cin >> n;
	if (n & 1) {
		cout << "NO";
		return 0;
	}
	vector<point_t> P (n);
	vector<point_t> D (n);
	for (int i = 0; i < n; i++) {
		cin >> P[i].x >> P[i].y;
	}
	for (int i = 0; i < n; i++) {
		D[i] = P[(i + 1) % n] - P[i];
	}
	int hn = n >> 1;
	for (int i = 0; i < n; i++) {
		if (D[i].x != -D[(i + hn) % n].x || D[i].y != -D[(i + hn) % n].y) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}