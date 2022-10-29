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

typedef class Point {
	public:
		int x, y, z, id;

		void read() {
			scanf("%d%d%d", &x, &y, &z);
		}
		boolean operator < (Point b) const {
			if (x ^ b.x)
				return x < b.x;
			if (y ^ b.y)
				return y < b.y;
			return z < b.z;
		}
} Point;

const int N = 1e5 + 5;

int n;
Point p[N];

boolean ry;
Point rpy;
void solvey(int l, int r) {
	int i;
	for (i = l; i + 1 <= r; i += 2) {
		printf("%d %d\n", p[i].id, p[i + 1].id);
	}
	if (i > r)
		return;
	if (ry) {
		ry = false;
		printf("%d %d\n", rpy.id, p[r].id);
	} else {
		ry = true;
		rpy = p[r]; 
	}
}

boolean rx;
Point rpx;
void solvex(int l, int r) {
//	debug("sx: l = %d, r = %d\n", l, r);
	int lsty = p[l].y;
	int lst = l;
	for (int i = l + 1; i <= r; i++) {
		if (p[i].y ^ lsty) {
			solvey(lst, i - 1);
			lst = i;
			lsty = p[i].y;
		}
	}
	solvey(lst, r);
	if (ry) {
		if (rx) {
			rx = false;
			printf("%d %d\n", rpx.id, rpy.id);
		} else {
			rx = true;
			rpx = rpy;
		}
	}
	ry = false;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		p[i].read();
		p[i].id = i;
	}
	sort(p + 1, p + n + 1);
	int lstx = p[1].x;
	int lst = 1;
	for (int i = 2; i <= n; i++) {
		if (p[i].x ^ lstx) {
			solvex(lst, i - 1);
			lst = i;
			lstx = p[i].x;
		}
	}
	solvex(lst, n);
	return 0;
}