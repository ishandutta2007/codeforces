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
//#include<complex>
#include<numeric>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
//typedef complex<double> base;
using namespace std;
ll gcd(ll i, ll j) {
	if (i < j)swap(i, j);
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
int __builtin_popcount(int x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
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
const int mod = 1000000007;
const ld eps = 1e-4, pi = acos(-1);
const int maxN = 2000010, maxT = 10010, A = 179;
/*ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}*/
void panic() {
	cout << "NO\n";
	exit(0);
}
map<tuple<int, int, int, int, int, int>, int>mp;
int qw(int h, int w, int x1, int y1, int x2, int y2) {
	tuple<int, int, int, int, int, int>t = make_tuple(h, w, x1, y1, x2, y2);
	if (mp.count(t))return mp[t];
	cout << "? " << h << " " << w << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	int v;
	cin >> v;
	return mp[t] = v;
}
void solve() {
	int n, m;
	cin >> n >> m;
	vector<int>dp(n + 1, 2);
	ll res = 1;
	dp[n] = 1;
	dp[0] = 0;
	for (int i = n - 1; i > 0; --i) {
		if (n % i != 0) {
			dp[i] = 0;
			continue;
		}
		ll gd = n;
		ll mn = n;
		for (int j = 2 * i; j <= n; j += i) {
			if (n % j != 0)continue;
			mn = min(mn, (ll)j);
			if (dp[j] == 0) {
				dp[i] = 0;
			}
			gd = gcd(gd, j);
		}
		if (dp[i] == 0)continue;
		if (gd == i) {
			dp[i] = 1;
			continue;
		}
		int ct = mn / i;
		int st = 1;
		int f = 1;
		dp[i] = 0;
		while (f && ct >= 2) {
			f &= qw(i * (ct / 2), m, st, 1, st + (ct / 2) * i, 1);
			st += ct / 2 * i;
			ct = (ct + 1) / 2;
		}
		dp[i] = f;
	}
	ll ct = 0;
	for (auto x : dp) {
		if (x != 2) ct += x;
	}
	res *= ct;

	dp.assign(m + 1, 2);
	dp[m] = 1;
	dp[0] = 0;
	for (int i = m - 1; i > 0; --i) {
		if (m % i != 0) {
			dp[i] = 0;
			continue;
		}
		ll gd = m;
		ll mn = m;
		for (int j = 2 * i; j <= m; j += i) {
			if (m % j != 0)continue;
			mn = min(mn, (ll)j);
			if (dp[j] == 0) {
				dp[i] = 0;
			}
			gd = gcd(gd, j);
		}
		if (dp[i] == 0)continue;
		if (gd == i) {
			dp[i] = 1;
			continue;
		}
		int ct = mn / i;
		int st = 1;
		int f = 1;
		dp[i] = 0;
		while (f && ct >= 2) {
			f &= (dp[i * (ct / 2)] != 0) || qw(n, i * (ct / 2), 1, st, 1, st + (ct / 2) * i);
			st += ct / 2 * i;
			ct = (ct + 1) / 2;
		}
		dp[i] = f;
	}
	ct = 0;
	for (auto x : dp) {
		if (x != 2) ct += x;
	}
	res *= ct;
	cout << "! " << res << endl;

}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(3);
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
abbbbbbd
3
1 2
7 8
2 7
*/