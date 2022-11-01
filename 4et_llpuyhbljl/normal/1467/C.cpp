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
	if (i < j)swap(i, j);
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
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
ll f(vector<ll> a, vector<ll>b, vector<ll>c) {
	ll sum = 0;
	ll s1 = 0, s2 = 0, s3 = 0;
	for (auto x : a)s1 += x;
	for (auto x : b)s2 += x;
	for (auto x : c)s3 += x;
	sum = s1 + s2 + s3;
	ll res = max(sum - 2 * s1, max(sum - 2 * s2, sum - 2 * s3));
	return max(res, sum - 2 * (b[0] + c[0]));

}
void solve() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	vector<ll>a(n1), b(n2), c(n3);
	for (auto& x : a)cin >> x;
	for (auto& x : b)cin >> x;
	for (auto& x : c)cin >> x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	ll res = -INF;
	res = max(res, f(a, b, c));
	res = max(res, f(b, a, c));
	res = max(res, f(c, a, b));
	cout << res << "\n";
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
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}