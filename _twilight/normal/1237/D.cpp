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

const int N = 1e5 + 5;

int n;
int a[N << 1], mxv, miv;
int stk[N << 1], pmx[N << 1], pmi[N << 1], f[N << 1];

int getf(int i) {
	if (f[i] != -1)
		return f[i];
	if (pmi[i] < pmx[i]) {
		f[i] = pmi[i] - i;
	} else {
		f[i] = getf(pmx[i] % n) + pmx[i] - i;
	}
	return f[i];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		a[i + n] = a[i];
	}
	mxv = a[0];
	miv = a[0];
	for (int i = 1; i < n; i++) {
		vmax(mxv, a[i]);
		vmin(miv, a[i]);
	}
	if ((miv << 1) >= mxv) {
		for (int i = 1; i <= n; i++) {
			printf("-1 ");
		}
		return 0;
	}
	int tp = 0;
	a[n << 1] = mxv + 1;
	stk[0] = n << 1;
	for (int i = (n << 1) - 1; ~i; i--) {
		while (tp && a[i] >= a[stk[tp]])
			tp--;
		pmx[i] = stk[tp];
		stk[++tp] = i;
	}
	tp = 0;
	stk[0] = n << 1;
	a[n << 1] = -1;
	for (int i = n + n - 1; i >= n; i--) {
		while (tp && a[i] <= a[stk[tp]])
			tp--;
		stk[++tp] = i;
	}
	for (int i = n; ~i; i--) {
		int l = 0, r = tp;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if ((a[stk[mid]] << 1) < a[i]) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		pmi[i] = stk[l - 1];
		while (tp && a[i] <= a[stk[tp]])
			tp--;
		stk[++tp] = i;
	}
	for (int i = 0; i < n; i++)
		f[i] = -1;
	for (int i = 0; i < n; i++) {
		printf("%d ", getf(i));
	}
	return 0;
}