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
const int maxN = 2000010, maxT = 10010, A = 179;
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
void solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	if (s == t) {
		cout << t << "\n";
		return;
	}
	if (s[0] != t[0]) {
		for (int i = 0; i < n; ++i)cout << "1"; cout << "\n";
		return;
	}
	if (t.back() == '1') {
		cout << t << "\n";
		return;
	}
	string tmp = t;
	for (int i = n - 1; i >= 0; --i) {
		if (tmp[i] == '1') {
			tmp[i] = '0';
			for (int j = i + 1; j < n; ++j)tmp[j] = '1';
			break;
		}
	}
	if (tmp != s) {
		tmp = t;
		for (int i = n - 1; i >= 0; --i) {
			if (tmp[i] == '0') {
				tmp[i] = '1';
				for (int j = i + 1; j < n; ++j)tmp[j] = '0';
				break;
			}
		}
		cout << tmp << "\n";
		return;
	}
	cout << t << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(3);
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