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
const ll maxN = 32768, maxT = 10010, A = 179;
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
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>>a(n, vector<char>(m));
	for (auto& vec : a) {
		for (auto& x : vec)cin >> x;
	}
	for (int i = (n % 3 == 0 ? 1 : 0); i < n; i += 3) {
		for (int j = 0; j < m; ++j)a[i][j] = 'X';
		if (i > 1) {
			if (1 < m && a[i - 1][1] == 'X' || a[i - 2][1] == 'X')
				a[i - 1][1] = a[i - 2][1] = 'X';
			else a[i - 1][0] = a[i - 2][0] = 'X';
		}
	}
	for (auto vec : a) {
		for (auto x : vec)cout << x;
		cout << "\n";
	}
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
	cin >> t;
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