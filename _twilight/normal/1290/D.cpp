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

boolean query(int x) {
	static char tmp[5];
	cout << "? " << x << endl;
	cin >> tmp;
	return tmp[0] == 'Y';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<boolean> have_pre (n + 1, false);
	if (k == 1) {
		boolean first = true;
		for (int d = 1; d < n; d++) {
			for (int s = 1; s <= d && s + d <= n; s++) {
				if (!first)
					cout << 'R' << endl;
				first = false;
				for (int i = s; i <= n; i += d) {
					have_pre[i] = query(i) || have_pre[i];
				}
			}
		}
	} else {
		int C = n / k;
		boolean first = true;
		for (int d = 1; d < C || d == 1; d++) {
			for (int s = 1; s <= d && (d == 1 || s + d <= C); s++) {
				if (!first)
					cout << 'R' << endl;
				first = false;
				for (int c = s; c <= C; c += d) {
					for (int i = (c - 1) * k + 1; i <= c * k; i++) {
						have_pre[i] = have_pre[i] || query(i);
					}
				}
			}
		}
		for (int d = 1; d < C; d++) {
			for (int s = 1; s <= d && s + d <= C; s++) {
				cout << 'R' << endl;
				for (int c = s; c <= C; c += d) {
					for (int i = c * k; i > (c - 1) * k; i--) {
						have_pre[i] = have_pre[i] || query(i);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += !have_pre[i];
	cout << "! " << ans << endl;
	return 0;
}