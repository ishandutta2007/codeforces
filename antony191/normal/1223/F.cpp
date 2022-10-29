#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>
#include <fstream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;


const char el = '\n';
const int inf = 1e9;
const ll llinf = 1e18, mod = 1000'000'007ll;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

const ll p = 990389, p2 = 516233;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> a(n);
		forn(i, n) cin >> a[i];
		vector<ll> d(n, 1), d2(n, 1);
		firn(i, n) d[i] = d[i - 1] * 1ll * p % mod, d2[i] = d2[i - 1] * 1ll * p2 % mod;
		vector<int> stack;
		map<pair<int, int>, int> k;
		k[{ 0, 0 }]++;
		ll cur = 0, cur2 = 0;
		forn(i, n) {
			if (!stack.empty() && stack.back() == a[i]) {
				cur -= d[(int)stack.size() - 1] * 1ll * a[i] % mod;
				cur = (cur % mod + mod) % mod;
				cur2 -= d2[(int)stack.size() - 1] * 1ll * a[i] % mod;
				cur2 = (cur2 % mod + mod) % mod;
				k[{ cur, cur2 }]++;
				stack.pop_back();
			}
			else {
				cur += d[(int)stack.size()] * 1ll * a[i] % mod;
				cur = (cur % mod + mod) % mod;
				cur2 += d2[(int)stack.size()] * 1ll * a[i] % mod;
				cur2 = (cur2 % mod + mod) % mod;
				k[{ cur, cur2 }]++;
				stack.push_back(a[i]);
			}
		}
		ll ans = 0;
		for (auto to : k)
			ans += (to.y) * 1ll * (to.y - 1) / 2ll;
		cout << ans << el;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}