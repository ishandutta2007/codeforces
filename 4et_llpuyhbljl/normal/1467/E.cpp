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
const ld eps = 1e-9, pi = acos(-1);
const int maxN = 500100, maxT = 512;
void panic() {
	cout << "0\n";
	exit(0);
}
vector<int>compress(vector<int>v) {
	vector<int>vals;
	for (auto x : v) {
		vals.push_back(x);
	}
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	for (auto& x : v)x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
	return v;
}
vector<int>tin, tout, v, ct, del;
vector<vector<int>>G, GG, inf;
int tm = 0;
void dfs_build_inf(int ve, int p) {
	inf[v[ve]].push_back(tm);
	tin[ve] = tm++;
	int cnt = 1;
	for (auto x : G[ve]) {
		if (x == p)continue;
		dfs_build_inf(x, ve);
		int tmp = lower_bound(inf[v[ve]].begin(), inf[v[ve]].end(), tout[x]) - lower_bound(inf[v[ve]].begin(), inf[v[ve]].end(), tin[x]);
		if (tmp) {
			GG[ve].push_back(x);
			cnt += tmp;
		}
	}
	if (cnt != ct[v[ve]])
		GG[ve].push_back(p);
	tout[ve] = tm++;
}
void dfs(int ve, int p) {
	del[ve] = 1;
	if (GG[ve].size() > 1 || (GG[ve].size() == 1 && GG[ve][0] != p)) panic();
	for (auto x : G[ve]) {
		if (x == p || del[x]) continue;
		dfs(x, ve);
	}
}
void solve() {
	int n;
	cin >> n;
	tin.assign(n, 0);
	tout.assign(n, 0);
	G.resize(n);
	GG.resize(n);
	v.assign(n, 0);
	for (auto& x : v)cin >> x;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	v = compress(v);
	inf.resize(n);
	ct.assign(n, 0);
	for (auto x : v)++ct[x];
	dfs_build_inf(0, -1);
	del.assign(n, 0);
	for (int i = 0; i < n; ++i) {
		for (auto x : GG[i]) {
			dfs(i, x);
		}
	}
	int ans = 0;
	for (auto x : del)ans += x;
	cout << n - ans << "\n";
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