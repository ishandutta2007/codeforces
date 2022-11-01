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
ll gcd(ll i, ll j) {
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
const int INF = 1e8;
const int mod = 998244353;
const ld eps = 1e-12, pi = acos(-1);
const int maxN = 500100, maxT = 512;
void solve() {
	string s;
	cin >> s;
	int n = s.length();
	vector<vector<int>>dp(4, vector<int>(n + 1, INF));
	dp[0][0] = 0;
	dp[1][0] = 1;
	dp[0][1] = 0;
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[3][1] = 2;
	s = "#" + s;
	for (int i = 2; i <= n; ++i) {
		if (s[i] != s[i - 1]) {
			dp[0][i] = min(dp[2][i - 1], (s[i] == s[i - 2] ? INF : dp[0][i - 1]));
		}
		dp[3][i] = min(dp[1][i - 1], dp[3][i - 1]) + 1;
		dp[2][i] = min(dp[3][i - 1], (s[i] == s[i - 2] ? INF : dp[1][i - 1]));
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + 1;
	}
	int ans = INF;
	for (int j = 0; j < 4; ++j)ans = min(ans, dp[j].back());
	cout << ans << "\n";
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
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}