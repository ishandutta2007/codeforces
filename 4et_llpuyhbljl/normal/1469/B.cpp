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
int n, m;
vector<int>a, b;
void solve() {
	cin >> n;
	a.assign(n, 0);
	for (auto& x : a)cin >> x;
	cin >> m;
	b.assign(m, 0);
	for (auto& x : b)cin >> x;
	vector<ll>pa(a.size() + 1, 0), pb(b.size() + 1, 0);
	for (int i = 0; i < n; ++i) {
		pa[i + 1] = pa[i] + a[i];
	}
	for (int i = 0; i < m; ++i) {
		pb[i + 1] = pb[i] + b[i];
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(m + 1, -INF));
	dp[0][0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i + j == 0)continue;
			dp[i][j] = max(max(i == 0 ? -INF : dp[i - 1][j], j == 0 ? -INF : dp[i][j - 1]), pa[i] + pb[j]);
		}
	}
	cout << dp[n][m] << '\n';
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