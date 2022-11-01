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
const int mod = 1000000007;
const ld eps = 1e-12, pi = acos(-1);
const int maxN = 500100, maxT = 512;
vector<int>f;
vector<int>dp;
vector<int>br;
int find(int v) { return (f[v] == v ? v : f[v] = find(f[v])); }
bool uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b || br[a] + br[b] == 2)return false;
	dp[a] += dp[b];
	br[a] |= br[b];
	f[b] = a;
	return true;
}
void solve() {
	int n, m;
	cin >> n >> m;
	f.assign(m, 0);
	dp.assign(m, 1);
	br.assign(m, 0);
	for (int i = 0; i < m; ++i) {
		f[i] = i;
	}
	vector<int>id;
	for (int i = 0; i < n; ++i) {
		int ct;
		cin >> ct;
		if (ct == 1) {
			int k;
			cin >> k;
			--k;
			k = find(k);
			if (br[k] == 1)continue;
			br[k] = 1;
			id.push_back(i + 1);
		}
		else {
			int a, b;
			cin >> a >> b;
			--a;
			--b;
			if (uni(a, b))id.push_back(i + 1);
		}
	}
	ll ans = 1, ct = 0;
	vector<int>used(m);
	for (int i = 0; i < m; ++i) {
		int t = find(i);
		if (used[t])continue;
		used[t] = 1;
		if (br[t]) {
			ct += dp[t];
			for (int j = 0; j < dp[t]; ++j)ans = ans * 2 % mod;
		}
		else {
			ct += dp[t] - 1;
			for (int j = 0; j < dp[t] - 1; ++j)ans = ans * 2 % mod;
		}
	}
	cout << ans << " " << ct << "\n";
	for (auto x : id)cout << x << " ";
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