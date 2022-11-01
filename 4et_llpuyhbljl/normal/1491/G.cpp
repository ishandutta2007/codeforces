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
const int maxN = 200010, maxT = 10010, A = 179;
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
int a[maxN];
int r[maxN];
int cnt[maxN];
vector<vector<int>>cycles;
vector<int>used;
void dfs(int v) {
	used[v] = 1;
	cycles.back().push_back(v);
	if (!used[a[v]]) dfs(a[v]);
}
vector<pair<int, int>>res;
void m_s(int p1, int p2) {
	cnt[a[p1]] ^= 1;
	cnt[a[p2]] ^= 1;
	swap(a[p1], a[p2]);
	r[a[p1]] = p1;
	r[a[p2]] = p2;
	res.push_back({ p1,p2 });
}
void build_res_1(int n) {
	set<int>s;
	for (int i = 1; i <= n; ++i)s.insert(i);
	int ps = r[1];
	m_s(1, ps);
	while (s.size() > 3) {
		s.erase(a[ps]);
		m_s(ps, a[ps]);
	}
	vector<int>v;
	for (auto x : s)v.push_back(x);
	sort(v.begin(), v.end());
	if (cnt[v[1]]) {
		swap(v[1], v[2]);
	}
	m_s(r[v[0]], r[v[1]]);
	m_s(r[v[0]], r[v[2]]);
	m_s(r[v[0]], r[v[1]]);
}
void merge(vector<int>c, vector<int>b) {
	set<int>s;
	for (auto x : c)s.insert(x);
	for (auto x : b)s.insert(x);
	int c1 = r[c.back()], c2 = r[b.back()];
	m_s(c1, c2);
	while (s.size() > 2) {
		if (a[c1] != c2) {
			s.erase(a[c1]);
			m_s(c1, a[c1]);
		}
		else {
			s.erase(a[c2]);
			m_s(c2, a[c2]);
		}
	}
	m_s(r[c1], r[c2]);
}
void build_res(int n) {
	for (int i = 0; i + 1 < cycles.size(); i += 2)merge(cycles[i], cycles[i + 1]);
	if (cycles.size() % 2 == 1) {
		merge(cycles.back(), { 1 });
	}
}
void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		r[a[i]] = i;
	}
	used.assign(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			cycles.push_back({});
			dfs(i);
		}
	}
	if (cycles.size() == 1) build_res_1(n);
	else build_res(n);
	cout << res.size() << "\n";
	for (auto x : res) {
		cout << x.first << " " << x.second << "\n";
	}
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
/*
abbbbbbd
3
1 2
7 8
2 7
*/