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
typedef unsigned short us;
typedef unsigned long long ull;
//typedef complex<double> base;
using namespace std;
ll gcd(ll i, ll j) {
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
const ll INF = 1e18 + 100;
const int mod = 998244353;
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 250010, maxT = 4010, A = 179, mid = 150;
mt19937 mt_rand(time(0));
ll bp(ll et, ll b) {
	b %= mod - 1;
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "-1\n";
	exit(0);
}
vector<pair<int, int>>go;
pair<int, vector<vector<int>>>bld(int h, int w, int sx = 0, int sy = 0) {
	vector<vector<int>>ans(h, vector<int>(w));
	int cnt = 0;
	++cnt;
	ans[sx][sy] = 1;
	for (int i = 0; i < w; ++i) {
		bool f = 0;
		int x = 0, y = i;
		for (auto v: go) {
			int x1, y1;
			tie(x1, y1) = v;
			x1 += x;
			y1 += y;
			if (x1 < 0 || x1 >= h || y1 < 0 || y1 >= w)
				continue;
			f |= ans[x1][y1];
		}
		if (f)
			continue;
		ans[0][i] = 1;
		++cnt;
	}
	for (int i = 0; i < h; ++i) {
		bool f = 0;
		int x = i, y = w - 1;
		for (auto v : go) {
			int x1, y1;
			tie(x1, y1) = v;
			x1 += x;
			y1 += y;
			if (x1 < 0 || x1 >= h || y1 < 0 || y1 >= w)
				continue;
			f |= ans[x1][y1];
		}
		if (f)
			continue;
		ans[i][w - 1] = 1;
		++cnt;
	}

	for (int i = w - 1; i >= 0; --i) {
		bool f = 0;
		int x = h - 1, y = i;
		for (auto v : go) {
			int x1, y1;
			tie(x1, y1) = v;
			x1 += x;
			y1 += y;
			if (x1 < 0 || x1 >= h || y1 < 0 || y1 >= w)
				continue;
			f |= ans[x1][y1];
		}
		if (f)
			continue;
		ans[h - 1][i] = 1;
		++cnt;
	}

	for (int i = h - 1; i >= 0; --i) {
		bool f = 0;
		int x = i, y = 0;
		for (auto v : go) {
			int x1, y1;
			tie(x1, y1) = v;
			x1 += x;
			y1 += y;
			if (x1 < 0 || x1 >= h || y1 < 0 || y1 >= w)
				continue;
			f |= ans[x1][y1];
		}
		if (f)
			continue;
		ans[i][0] = 1;
		++cnt;
	}

	return { cnt,ans };
}
void solve() {
	int h, w;
	cin >> h >> w;
	pair<int, vector<vector<int>>>res = { -1,vector<vector<int>>() };
	res = max(res, bld(h, w, 0, 0));
	res = max(res, bld(h, w, 0, 1));
	res = max(res, bld(h, w, 1, 0));
	for (auto x : res.second) {
		for (auto y : x) {
			cout << y;
		}
		cout << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("gymnasts.in", "r", stdin); freopen("gymnasts.out", "w", stdout);
#endif
	go.push_back({ 0,0 });
	go.push_back({ 0,1 });
	go.push_back({ 1,1 });
	go.push_back({ 1,0 });
	go.push_back({ 1,-1 });
	go.push_back({ 0,-1 });
	go.push_back({ -1,-1 });
	go.push_back({ -1,0 });
	go.push_back({ -1,1 });
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}