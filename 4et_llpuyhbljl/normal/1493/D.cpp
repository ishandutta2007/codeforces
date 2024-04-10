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
multiset<int>mp[maxN];
ll ans = 1;
vector<int>pr;
map<int, int>dels[maxN];
void build() {
	vector<int>bla(maxN);
	for (int i = 2; i * i <= maxN; ++i) {
		if (bla[i] == 0) {
			pr.push_back(i);
			for (int j = i + i; j < maxN; j += i)bla[j] = 1;
		}
	}
}
int n;
void add(int v, int i) {
	vector<pair<ll, ll>>vi;
	for (auto x : pr) {
		if (v % x == 0) {
			vi.push_back({ x,0 });
			while (v % x == 0) {
				v /= x;
				++vi.back().second;
			}
		}
	}
	if (v != 1) {
		vi.push_back({ v,1 });
	}
	for (auto x : vi) {
		if (mp[x.first].size() == n) {
			ans = (ans * bp(bp(x.first, *mp[x.first].begin()), mod - 2)) % mod;
		}
		if (dels[i].count(x.first)) mp[x.first].erase(mp[x.first].find(dels[i][x.first]));

		dels[i][x.first] += x.second;
		mp[x.first].insert(dels[i][x.first]);
		if (mp[x.first].size() == n) 
			ans = (ans * bp(x.first, *mp[x.first].begin())) % mod;
	}
}
void solve() {
	int q;
	n = getint<int>();
	q = getint<int>();
	vector<int>a(n);
	int nm = 0;
	for (auto& x : a) {
		x = getint<int>();
		add(x, nm++);
	}
	while (q--) {
		int t = getint<int>(), b = getint<int>();
		--t;
		add(b, t);
		cout << ans << "\n";
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
	build();
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