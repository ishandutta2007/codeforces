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
long long gcd(long long i, long long j) {
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
const long long INF = 1e18;
const int mod = 1000000007;
const ld eps = 1e-12, pi = acos(-1);
const int maxN = 20100, maxT = 100010;
void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll>h(n);
	for (auto& x : h)cin >> x;
	bool ans = true;
	ll l = h[0], r = h[0] + k;
	for (int i = 1; i < n; ++i) {
		ll l1, r1;
		if (i + 1 == n) {
			l1 = h[i];
			r1 = h[i] + k;
		}
		else {
			l1 = h[i];
			r1 = h[i] + 2 * k - 1;
		}
		if (l1 == r || l == r1 || max(l1, l) > min(r, r1)) {
			ans = false;
		}
		l1 = max(l1, l - k + 1);
		r1 = min(r1, r + k - 1);
		l = l1;
		r = r1;
	}

	if (ans)cout << "YES\n";
	else cout << "NO\n";
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