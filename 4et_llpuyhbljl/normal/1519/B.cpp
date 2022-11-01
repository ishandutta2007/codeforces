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
typedef double ld;
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
const ll INF = 1e18;
const int mod = 1000000007;
const ld eps = 1e-7, pi = acosl(-1);
const ll maxN = 200100, maxT = 1000000, A = 179, mid = 150;
ll bp(ll et, ll b) {
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
void solve() {
	ll n ,m , k;
	cin >> n >> m >> k;
	vector<vector<ll>>r(n, vector<ll>(m, -INF));
	vector<vector<ll>>l(n, vector<ll>(m, INF));
	l[0][0] = r[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i) {
				l[i][j] = min(l[i][j], l[i - 1][j] + j + 1);
				r[i][j] = max(r[i][j], r[i - 1][j] + j + 1);
			}
			if (j) {
				l[i][j] = min(l[i][j], l[i][j - 1] + i + 1);
				r[i][j] = max(r[i][j], r[i][j - 1] + i + 1);
			}
		}
	}
	if (l[n - 1][m - 1] <= k && k <= r[n - 1][m - 1])
		cout << "YES\n";
	else cout << "NO\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("fcolor.in", "r", stdin); freopen("fcolor.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
5 8 0

2 4 3
1 2 1
3 2 2
5 1 4
1 3
1 5
1 4
1 5
2 1 2
2 1 0
1 1
1 4
*/