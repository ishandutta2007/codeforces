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
const int mod = 998244353;
const ld eps = 1e-4, pi = acos(-1);
const int maxN = 100010, maxT = 10010, A = 179;
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "NO\n";
	exit(0);
}
vector<ll>fib;
vector<set<int>>g;
vector<int>dp;
pair<int, int> dfs(int v, int n_sz, int n_sz1, int p = -1) {
	dp[v] = 1;
	pair<int, int>ans = { -1,-1 };
	for (auto x : g[v]) {
		if (x == p)continue;
		ans = max(ans, dfs(x, n_sz, n_sz1, v));
		dp[v] += dp[x];
	}
	if (dp[v] == n_sz) {
		ans = { v,p };
	}
	if (dp[v] == n_sz1) {
		ans = { p,v };
	}
	return ans;
}
bool is_it_good(int sz, int v) {
	if (sz <= 3)return true;
	int a, b;
	int y = lower_bound(fib.begin(), fib.end(), sz) - fib.begin();

	tie(a, b) = dfs(v, fib[y - 1], fib[y - 2]);
	if (a == -1)return false;
	g[a].erase(b);
	g[b].erase(a);
	return is_it_good(fib[y - 1], a) && is_it_good(fib[y - 2], b);
}
void solve() {
	fib.assign(2, 1);
	fib[1] = 2;
	int n;
	cin >> n;
	if (n <= 3) {
		cout << "YES\n";
		return;
	}
	while (fib.back() < n)fib.push_back(fib.back() + fib[fib.size() - 2]);
	if (fib.back() != n) {
		cout << "NO\n";
		return;
	}
	g.resize(n);
	dp.assign(n, 0);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].insert(b);
		g[b].insert(a);
	}
	if (is_it_good(n, 0))
		cout << "YES\n";
	else cout << "NO\n";
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