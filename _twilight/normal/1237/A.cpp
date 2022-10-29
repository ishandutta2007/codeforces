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

const int N = 14000;

int n;
int a[N];

int main() {
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if (a[i] & 1) {
			cnt++;
		}
	}
	cnt >>= 1;
	for (int i = 1; i <= n; i++) {
		if (!(a[i] & 1)) {
			printf("%d\n", a[i] >> 1);
		} else if (cnt) {
			printf("%d\n", (a[i] + 1) >> 1);
			cnt--;
		} else {
			printf("%d\n", a[i] >> 1);
		}
	}
	return 0;
}