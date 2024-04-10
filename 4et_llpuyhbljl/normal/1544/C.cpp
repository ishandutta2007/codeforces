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
bool f(const vector<int>&a, const vector<int>&b, int cnt) {
	long long s1 = 0, s2 = 0;
	int cc = cnt + a.size();
	int all_c = cc - cc / 4;
	int all_c1 = all_c;
	while (all_c && cnt) {
		--all_c;
		--cnt;
		s1 += 100;
	}
	int y = a.size();
	while (all_c) {
		--all_c;
		s1 += a[--y];
	}
	cnt = cc - a.size();
	y = b.size();
	while (y && all_c1) {
		--all_c1;
		s2 += b[--y];
	}
	return s1 >= s2;
}
void solve() {
	int n;
	cin >> n;
	vector<int>a(n), b(n);
	for (auto& x : a) {
		cin >> x;
	}
	for (auto& x : b) {
		cin >> x;
	}
	int l = -1, r = 4 * n;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	while (l + 1 != r) {
		int m = (l + r) / 2;
		if (f(a, b, m))r = m;
		else l = m;
	}
	cout << r << "\n";
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
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}