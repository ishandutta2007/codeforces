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

int n, q;

int main() {
	string s;
	cin >> s;
	cin >> q;
	n = s.length();
	vector<int> pos;
	vector<vector<int>> cnt (26, vector<int>(n, 0));
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) {
			pos.push_back(i + 1);
		}
	}
	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a'][i] = 1;
	}
	for (auto& v : cnt) {
		int s = 0;
		for (auto& x : v) {
			s += x;
			x = s;
		}
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		int dif = 0;
		for (auto& v : cnt) {
			int x = v[r] - ((!l) ? 0 : v[l - 1]);
			dif += x != 0;
		}
		if (l == r) {
			puts("Yes");
		} else if (s[l] == s[r] && dif <= 2) {
			puts("No");
		} else {
			puts("Yes");
		}
	}
	return 0;
}