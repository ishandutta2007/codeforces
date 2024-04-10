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
vector<ll>b(60);
void add(ll c) {
	for (int i = 0; i < 60; ++i) {
		if ((c & (1LL << i)) != 0)++b[i];
	}
}
void del(ll c) {
	for (int i = 0; i < 60; ++i) {
		if ((c & (1LL << i)) != 0)--b[i];
	}
}
void solve() {
	int n;
	cin >> n;
	b.assign(60, 0);
	vector<ll>a(n);
	for (auto& x : a) {
		cin >> x;
		add(x);
	}
	/*ll f = 0;
	for (auto z : a) {
		for (auto y : a) {
			for (auto x : a) {
				f += (z & y) * (x | y);
				cout << f << endl;
			}
		}
	}*/
	ll ans = 0;
	for (auto x : a) {
		//del(x);
		ll m1 = 0, m2 = 0;
		for (int i = 0; i < 60; ++i) {
			if ((x & (1LL << i)) != 0) {
				m2 = (m2 + (1LL << i) % mod * n) % mod;
			}
			else {
				m2 = (m2 + (1LL << i) % mod * b[i]) % mod;
			}
		}
		for (int i = 0; i < 60; ++i) {
			if ((x & (1LL << i)) != 0) {
				m1 = (m1 + (1LL << i) % mod * b[i]) % mod;
			}
		}
		ans = (ans + m1 * m2) % mod;
		//add(x);
	}
	cout << ans << "\n";
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