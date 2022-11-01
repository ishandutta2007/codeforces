#pragma comment(linker, "/STACK:9759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<unordered_map>
#include<random>
#include<ctime>
//#define double long double
typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
using namespace std;
ll gcd(ll i, ll j) {
	if (i < j)swap(i, j);
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
template<typename T> inline T getint() {
	T val = 0;
	char c;

	bool neg = false;
	while ((c = getchar()) && !(c >= '0' && c <= '9')) {
		neg |= c == '-';
	}

	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));

	return val * (neg ? -1 : 1);
}
//#define int long long
const ll INF = 1e18;
const int mod = 1000000007, mod1 = 1000000009;
const ld eps = 1e-9, pi = acos(-1);
const int maxN = 1000100, maxT = 1601;
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void solve() {
	int n, k, q;
	cin >> n >> k >> q;
	vector<vector<int>>dp(k + 1, vector<int>(n, 0));
	dp[0] = vector<int>(n, 1);
	vector<vector<int>>dp1(k + 1, vector<int>(n, 0));
	dp1[k] = vector<int>(n, 1);
	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j)dp[i][j] += dp[i - 1][j - 1];
			if (j + 1 < n)dp[i][j] += dp[i - 1][j + 1];
			dp[i][j] %= mod;
		}
	}
	for (int i = k - 1; i >= 0; --i) {
		for (int j = 0; j < n; ++j) {
			if (j)dp1[i][j] += dp1[i + 1][j - 1];
			if (j + 1 < n)dp1[i][j] += dp1[i + 1][j + 1];
			dp1[i][j] %= mod;
		}
	}
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[k][j] = (dp[k][j] + (ll)dp1[i][j] * dp[i][j] % mod) % mod;
		}
	}
	ll res = 0;
	vector<ll>a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		res = (res + a[i] * dp.back()[i]) % mod;
	}
	while (q--) {
		int i, v;
		cin >> i >> v;
		--i;
		res = (res + ((ll)v - a[i]) * dp.back()[i] % mod + mod) % mod;
		cout << res << "\n";
		a[i] = v;
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("epic.in", "r", stdin); freopen("epic.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}