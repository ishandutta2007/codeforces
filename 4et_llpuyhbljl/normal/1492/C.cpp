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
const ll INF = 1e9;
const int mod = 1000000007;
const ld eps = 1e-4, pi = acos(-1);
const int maxN = 100010, maxT = 50010, A = 179;
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "impossible";
	exit(0);
}
int n, m;
string s, t;
vector<vector<int>>ps;
bool f(int len) {
	vector<vector<int>>dp(2, vector<int>(m + 1, INF));
	dp[0][0] = 0;
	for (int i = 0; i < m; ++i) {
		int b = t[i] - 'a';
		if (dp[0][i] != INF) {
			int y = upper_bound(ps[b].begin(), ps[b].end(), dp[0][i]) - ps[b].begin();
			if (y != ps[b].size()) {
				dp[0][i + 1] = min(dp[0][i + 1], ps[b][y]);
			}
			y = lower_bound(ps[b].begin(), ps[b].end(), dp[0][i] + len) - ps[b].begin();
			if (y != ps[b].size() && i > 0) {
				dp[1][i + 1] = min(dp[1][i + 1], ps[b][y]);
			}
		}
		if (dp[1][i] != INF) {
			int y = upper_bound(ps[b].begin(), ps[b].end(), dp[1][i]) - ps[b].begin();
			if (y != ps[b].size()) {
				dp[1][i + 1] = min(dp[1][i + 1], ps[b][y]);
			}
		}
	}
	return dp[1][m] <= n;
}
void solve() {
	cin >> n >> m >> s >> t;
	ps.resize(26);
	for (int i = 0; i < n; ++i) {
		ps[s[i] - 'a'].push_back(i + 1);
	}
	int b = 0, e = n + 10;
	while (b + 1 != e) {
		int m = (b + e) / 2;
		if (f(m))b = m;
		else e = m;
	}
	cout << b << endl;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(3);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("labyrinth.in", "r", stdin); freopen("labyrinth.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}