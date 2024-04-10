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

const int inf = 1e9;
const ll llinf = 1e18, mod = 1000'000'007ll;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << '\n'; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	forn(i, n) cin >> a[i];
	vector<int> t(n + 1, 0);
	map<int, int> q;
	q[0]++;
	int tmp = (1 << k) - 1, tmp1 = (1 << (k - 1)) - 1;
	forn(i, n) {
		t[i + 1] = t[i] ^ a[i];
		q[t[i + 1]]++;
	}
	ll cnt1 = 0ll;
	map<int, bool> used;
	for (auto i = q.begin(); i != q.end(); ++i) {
		if (used[i->first]) continue;
		used[i->first] = used[tmp ^ i->first] = 1;
		int c1 = i->second, c2 = q[tmp ^ i->first];
		int d1 = (c1 + c2) / 2, d2 = (c1 + c2 + 1) / 2;
		if (i->first > tmp) break;
		cnt1 += d1 * 1ll * (d1 - 1) / 2ll + d2 * 1ll * (d2 - 1) / 2ll;
	}
	cout << n * 1ll * (n + 1) / 2ll - cnt1;
	
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}