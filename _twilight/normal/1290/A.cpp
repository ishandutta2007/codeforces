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

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a (n + 1);
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int ans = 0;
		if (k >= m) {
			for (int i = 0; i < m; i++) {
				ans = max(ans, max(a[i + 1], a[n - (m - i) + 1]));
			}
		} else {
			for (int i = 0; i <= k; i++) {
				int l = i, r = n - (k - i), rs = m - k;
				int tmp = 1e9 + 3;
				for (int j = 0; j < rs; j++) {
					tmp = min(tmp, max(a[l + j + 1], a[r - (rs - j) + 1]));
				}
				ans = max(ans, tmp);
			}
		}
		cout << ans << '\n';
	}	
	return 0;
}