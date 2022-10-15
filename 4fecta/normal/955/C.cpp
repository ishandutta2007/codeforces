#define _CRT_SECURE_NO_WARNINGS
//#pragma GCC optimize("Ofast, unroll-loops")
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
#include <random>
#include <set>
#include <cassert>
#include <functional>
#include <queue>
#include <numeric>
#include <bitset>
#include <iterator>
 
using namespace std;
 
const int N = 303, M = 18;
 
mt19937 gen(time(NULL));
#define forn(i, n) for (int i = 0; i < n; i++)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define mp make_pair
#define endl '\n'
 
typedef long long ll;
 
template<typename T = int>
inline T read() {
	T val = 0, sign = 1; char ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') sign = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		val = val * 10 + ch - '0';
	return sign * val;
}
 
vector<ll> cand;
 
ll root(ll x) {
	ll l = 0, r = 1e9 + 1;
	while (l < r - 1) {
		ll m = (l + r) / 2;
		if (m * m > x)
			r = m;
		else
			l = m;
	}
	return l;
}
 
void solve() {
	ll l = read<ll>(), r = read<ll>();
	ll ans = upper_bound(all(cand), r) - lower_bound(all(cand), l);
	ans += root(r) - root(l - 1);
	printf("%lld\n", ans);
}
 
void precalc() {
	ll U = 1e18;
	vector<ll> _cand = { 1 };
	for (ll i = 2; i <= 1e6; i++)
		for (ll curr = i * i * i; curr <= U; curr *= i) {
			_cand.push_back(curr);
			if (curr > U / i) break;
		}
 
	sort(all(_cand));
	_cand.erase(unique(all(_cand)), _cand.end());
 
	for (const ll &u : _cand) {
		ll x = root(u);
		if (x * x == u) continue;
		cand.push_back(u);
	}
 
    debug("Precalc: %.3f\n", (double)(clock()) / CLOCKS_PER_SEC);
}
 
signed main() {
    precalc();
	int t = read();
    clock_t tot = clock();
	while (t--) {
		clock_t z = clock();
		solve();
		//debug("Test: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
	}
    debug("Total Time: %.3f\n", (double)(clock() - tot) / CLOCKS_PER_SEC);
}