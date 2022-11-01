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
const int mod = 998244353;
const ld eps = 1e-12, pi = acos(-1);
const int maxN = 500100, maxT = 512;
ll bin_pow(ll et, int pw) {
	if (pw == 0)return 1;
	ll tmp = bin_pow(et, pw / 2);
	tmp = (tmp * tmp) % mod;
	if (pw % 2 == 1)tmp = (tmp * et) % mod;
	return tmp;
}
vector<vector<int>>G;
vector<int>mex, cnt, used;
void dfs_mex(int v) {
	used[v] = 1;
	set<int>s;
	for (auto x : G[v]) {
		if (!used[x])dfs_mex(x);
		s.insert(mex[x]);
	}
	for (int i = 0;; ++i) {
		if (!s.count(i)) {
			mex[v] = i;
			break;
		}
	}
	++cnt[mex[v]];
}
void solve() {
	int n, m;
	cin >> n >> m;
	G.resize(n);
	mex.assign(n, 0);
	cnt.assign(maxT, 0);
	used.assign(n, 0);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		G[a].push_back(b);
	}
	for (int i = 0; i < n; ++i) {
		if (used[i])continue;
		dfs_mex(i);
	}
	vector<vector<ll>>g_means_gayss(maxT, vector<ll>(maxT + 1));
	ll inv = bin_pow(n + 1, mod - 2);
	for (int i = 1; i < maxT; ++i) {
		g_means_gayss[i].back() = 1;
	}
	for (int i = 0; i < maxT; ++i) {
		for (int j = 0; j < maxT; ++j) {
			if (i == j)g_means_gayss[i][j] = (mod + n + 1 - cnt[i ^ j]) % mod;
			else {
				g_means_gayss[i][j] = (mod - cnt[i ^ j] % mod) % mod;
			}
		}
	}
	for (int i = 0; i < maxT; ++i) {
		for (int j = i; j < maxT; ++j) {
			if (g_means_gayss[j][i] != 0) {
				swap(g_means_gayss[j], g_means_gayss[i]);
				break;
			}
		}
		for (int j = 0; j < maxT; ++j) {
			if (j == i)continue;
			ll mn = g_means_gayss[j][i] * bin_pow(g_means_gayss[i][i], mod - 2) % mod;
			for (int k = 0; k < maxT + 1; ++k) {
				g_means_gayss[j][k] = (g_means_gayss[j][k] - g_means_gayss[i][k] * mn % mod + mod) % mod;
			}
		}
	}

	cout << g_means_gayss[0].back() * bin_pow(g_means_gayss[0][0], mod - 2) % mod << "\n";
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
	//ll c = 332748118;cout << c * 3 % mod << endl;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}