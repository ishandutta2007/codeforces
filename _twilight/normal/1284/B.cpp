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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> s (n);
	vector<int> bmi, bmx;
	int cnt1 = 0;
	for (auto& a : s) {
		int t;
		cin >> t;
		a.resize(t);
		int mi = 1e9 + 7, mx = 0;
		boolean flag = false;
		for (auto& x : a) {
			cin >> x;
			vmax(mx, x);
			if (x > mi) {
				flag = true;
			} else {
				mi = x;
			}
		}
		if (flag) {
			cnt1++;
		} else {
			bmi.pb(mi);
			bmx.pb(mx);
		}
	}	
	sort(bmi.begin(), bmi.end());
	sort(bmx.begin(), bmx.end());
	ll ans = 2ll * cnt1 * (n - cnt1) + 1ll * cnt1 * cnt1;
	int m = bmx.size();
	for (auto x : bmi) {
		int t = upper_bound(bmx.begin(), bmx.end(), x) - bmx.begin();
		ans += m - t;
;	}
	cout << ans << '\n';
	return 0;
}