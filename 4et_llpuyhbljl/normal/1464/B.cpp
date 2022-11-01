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
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
long long gcd(long long i, long long j) {
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
const long long INF = 1e18;
const int mod = 1000000007;
const ld eps = 1e-12, pi = acos(-1);
const int maxN = 20100, maxT = 100010;
string s;
ll x, y;
ll f(int len) {
	ll ans = INF;
	int ct = 0;
	ll tm = 0;
	vector<ll>dp(2);
	for (auto xx : s) {
		if (xx == '?')++ct;
		if (xx == '1' || (xx == '?' && ct <= len)) {
			tm += dp[0] * x;
			++dp[1];
		}
		else {
			tm += dp[1] * y;
			++dp[0];
		}
	}
	ans = min(ans, tm);
	tm = dp[0] = dp[1] = ct = 0;
	for (auto xx : s) {
		if (xx == '?')++ct;
		if (xx == '0' || (xx == '?' && ct <= len)) {
			tm += dp[1] * y;
			++dp[0];
		}
		else {
			tm += dp[0] * x;
			++dp[1];
		}
	}
	return min(ans, tm);
}
void solve() {
	cin >> s;
	cin >> x >> y;
	int ct = 0;
	for (auto x : s)if (x == '?')++ct;
	int l = 0, r = ct;
	while (l + 2 < r) {
		int m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
		if (f(m1) < f(m2))r = m2;
		else l = m1;
	}
	ll ans = INF;
	for (int i = l; i <= r; ++i)ans = min(ans, f(i));
	cout << ans << '\n';
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