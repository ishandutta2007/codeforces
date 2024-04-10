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
const int maxN = 500100, maxT = 1601;
void solve() {
	int n, m;
	cin >> n >> m;
	vector<int>vals;
	vals.push_back(0);
	vals.push_back(n + 1);
	vector<pair<int, int>>pts(m);
	map<int, int>mp;
	mp[0] = mp[n + 1] = 3;
	for (auto& x : pts) {
		cin >> x.first >> x.second;
		vals.push_back(x.second);
		--x.first;
		mp[x.second] |= 1 << x.first;
	}
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	vector<vector<int>>dp(4, vector<int>(vals.size()));
	dp[3][0] = 1;
	for (int i = 1; i < vals.size(); ++i) {
		int nw = vals[i];
		int bf = vals[i - 1];
		if ((nw - bf) % 2 == 0) {
			dp[1][i] = dp[1][i - 1];
			dp[2][i] = dp[2][i - 1];
			dp[3][i] = max(dp[0][i - 1], dp[3][i - 1]);
			dp[0][i] = max(dp[0][i - 1], dp[3][i - 1]);
		}
		else {
			dp[1][i] = dp[2][i - 1];
			dp[2][i] = dp[1][i - 1];
			dp[3][i] = max(dp[0][i - 1], dp[3][i - 1]);
			dp[0][i] = max(dp[0][i - 1], dp[3][i - 1]);
		}
		vector<int>ch(4);
		for (int j = 0; j < 4; ++j) {
			if (dp[j][i] != 0 && ((j & mp[nw]) == 0)) {
				ch[j | mp[nw]] = 1;
			}
			dp[j][i] = 0;
		}
		for (int j = 0; j < 4; ++j) {
			dp[j][i] = ch[j];
		}
	}
	if (dp[3].back())cout << "YES\n";
	else cout << "NO\n";
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