/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
	cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
	while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
	return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
	return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
	bool is = false;
	for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
	return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
	vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
	vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
	vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
	vvv() {}
};
#ifdef Doludu
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 200001, logN = 20, K = 80000;

int main () {
	owo;
	int n;
	cin >> n;
	lli ans = 0;
	vector <lli> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 1; i < n; i += 2) {
		lli mn = 0, now = 0;
		for (int j = i + 1; j < n; j += 2) {
			now -= a[j - 1];
			mn = max(mn, -now);
			now += a[j];
			if (j + 1 < n) {
				// x >= mn (, now + x )
				// mn <= x <= a[i - 1]
				// 0 <= now + x <= a[j + 1]
				// -now <= x <= a[j + 1] - now
				lli l = max(mn, -now), r = min(a[i - 1], a[j + 1] - now);
				l = max(l, 0ll);
				if (l <= r) ans += r - l + 1;
			}
		}
	}
	for (int i = 0; i + 1 < n; i += 2) ans += min(a[i], a[i + 1]);
	cout << ans << endl;
}