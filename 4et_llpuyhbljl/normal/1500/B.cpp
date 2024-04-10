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
const int INF = 181;
int mod = 1000000007;
const ld eps = 1e-4, pi = acos(-1);
const ll maxN = 5e6 + 100, maxT = 10010, A = 179;
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 16; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "NO\n";
	exit(0);
}
ll gcd(ll a, ll b, ll& x, ll& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
vector<pair<ll, ll>>v;
ll f(ll val) {
	ll res = 0;
	for (auto x : v) {
		ll tmp = val - x.first;
		if (tmp < 0)continue;
		res += 1 + tmp / x.second;
	}

	return val - res;
}
void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll>a(n);
	vector<ll>b(m);
	map<ll, ll>mp;
	ll gd = gcd(n, m);
	ll lc = (ll)n * m / gd;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mp[a[i]] = i + 1;
	}
	for (int j = 0; j < m; ++j) {
		cin >> b[j];
		if (mp.count(b[j])) {
			ll a1 = m;
			ll a2 = n;
			ll b1 = j + 1, b2 = mp[b[j]];
			ll x, y;
			if (abs(b1 - b2) % gd != 0)continue;
			gcd(a1, a2, x, y);
			ll tmp = (b1 - b2) / gd;
			x *= tmp;
			y *= tmp;
			ll st = b2 + a2 * y;
			st = ((st % lc + lc) % lc);
			if (st == 0)st += lc;
			v.push_back({ st,lc });
		}
	}
	ll l = 0, r = 1e18;
	while (l + 1 != r) {
		ll m = (l + r) / 2;
		if (f(m) >= k)r = m;
		else l = m;
	}
	cout << r << endl;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(12);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
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