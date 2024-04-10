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
typedef double ld;
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
const ll INF = 1e18;
const int mod = 1000000007, mod1 = 1000000009;
const ld eps = 1e-9, pi = acos(-1);
const int maxN = 1000100, maxT = 1601;
ll qw(int id) {
	cout << "? " << id << endl;
	ll v;
	cin >> v;
	return v;
}
void solve() {
	ll n, k;
	cin >> n >> k;
	
	ll len = 320;
	if (n % 2 == 0)len = min(len, (n - 2) / 2);
	else len = min(len, (n - 3) / 2);
	for (int i = 0; i < len; ++i)qw(1);
	int b = 0, e = 0;
	for (int i = 1; i <= n; i += len) {
		if (qw(i) > k) {
			e = i;
			break;
		}
	}
	b = e - len;
	while (b + 1 != e) {
		int m = (b + e) / 2;
		int m1 = m;
		if (m1 <= 0)m1 += n;
		if (qw(m1) > k)e = m;
		else b = m;
	}
	if (b <= 0)b += n;
	cout << "! " << b << endl;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("epic.in", "r", stdin); freopen("epic.out", "w", stdout);
#endif
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}