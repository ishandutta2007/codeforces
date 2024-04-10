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
const int mod = 1e9 + 7, N = 200001, logN = 20, K = 80000;

lli modpow(lli a, int b) {
	lli ans = 1;
	for (; b; b >>= 1, a = a * a % mod) {
		if (b & 1) ans = ans * a % mod;
	}
	return ans;
}

int main () {
	owo;
	int n;
	cin >> n;
	vector <int> a(n);
	vv <lli> inv(n, n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		inv[i][j] = modpow((a[i] + a[j]) % mod, mod - 2);
	}
	vv <lli> pre(1 << n, n, 1);
	for (int i = 0; i < n; ++i) {
		for (int s = 1; s < 1 << n; ++s) if (~s >> i & 1) {
			int j = __lg(s & (-s));
			pre[s][i] = pre[s ^ (1 << j)][i] * inv[i][j] % mod * a[i] % mod;
		}
	}
	vector <lli> dp(1 << n, 1);
	for (int s = 0; s < 1 << n; ++s) {
		for (int t = s ^ (s & (-s)); t > 0; t = (t - 1) & s) {
			lli res = dp[t];
			for (int j = 0; j < n; ++j) if (t >> j & 1) {
				res = res * pre[t ^ s][j] % mod;
			}
			dp[s] -= res;
			if (dp[s] < 0) dp[s] += mod;
		}
	}
	lli ans = 0;
	for (int s = 0; s < 1 << n; ++s) {
		int k = __builtin_popcount(s);
		lli res = dp[s];
		for (int i = 0; i < n; ++i) if (s >> i & 1) {
			res = res * pre[s ^ ((1 << n) - 1)][i] % mod;
		}
		ans += res * k % mod;
		if (ans >= mod) ans -= mod;
	}
	cout << ans << endl;
}