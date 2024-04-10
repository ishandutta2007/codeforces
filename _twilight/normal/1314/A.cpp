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
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> a (n);
	for (auto& x : a)
		cin >> x.first;
	for (auto& x : a)
		cin >> x.second;
	sort(a.begin(), a.end());
	int curt = -1;
	priority_queue<pair<int, int>> Q;
	auto it = a.begin(), _it = a.end();
	long long ans = 0;
	while (!Q.empty() || it != _it) {
		if (Q.empty()) {
			curt = (*it).first;
		} else {
			curt++;
		}
		while (it != _it && (*it).first == curt) {
			Q.push(pair<int, int>((*it).second, (*it).first));
			it++;
		}
		int p = Q.top().second;
		int c = Q.top().first;
		ans += 1ll * (curt - p) * c;
		Q.pop();
	}
	cout << ans << '\n';
	return 0;
}