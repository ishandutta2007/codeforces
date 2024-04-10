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

int n;

int main() {
	cin >> n;
	vector<int> a (n);
	vector<int> pr (n);
	vector<int> sf (n);
	for (auto& x : a)
		cin >> x;
	int s = 0;
	for (int i = 0; i < n; i++)
		pr[i] = s, s |= a[i];
	s = 0;
	for (int i = n - 1; ~i; i--)
		sf[i] = s, s |= a[i];
	int ans = -1, id = 0;
	for (int i = 0; i < n; i++) {
		int y = pr[i] | sf[i];
		int v = (a[i] | y) - y;
		if (v > ans) {
			ans = v;
			id = i;
		}
	} 
	if (id)
		swap(a[id], a[0]);
	for (auto x : a)
		cout << x << ' ';
	return 0;
}