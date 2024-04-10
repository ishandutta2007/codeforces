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
const ll llinf = 1e18, mod = 998244353, md = 998244352;
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

const int mx = 1000'001;
vector<int> cnt[mx];
map<pair<int, char>, vector<int>> a;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, char>> b(n);
	vector<string> k(n);
	forn(i, n) {
		string s;
		cin >> s;
		k[i] = s;
		int cnt = 0;
		char c = '0';
		forn(i, s.size()) {
			if (s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u') {
				cnt++;
				c = s[i];
			}
		}
		b[i] = { cnt, c };
		a[{cnt, c}].push_back(i);
	}
	vector<pair<int, int>> good, bad;
	for (auto j = a.begin(); j != a.end(); ++j) {
		for (int i = 0; i + 1 < (int)(j->y.size()); i += 2)
			good.emplace_back(j->y[i], j->y[i + 1]);
		if (((int)j->y.size()) & 1) cnt[(*j).x.x].push_back(j->y.back());
	}
	firn(i, mx) {
		for (int j = 0; j + 1 < (int)cnt[i].size(); j += 2)
			bad.emplace_back(cnt[i][j], cnt[i][j + 1]);
	}
	while (bad.size() < good.size()) {
		bad.push_back(good.back());
		good.pop_back();
	}
	cout << (int)good.size() << el;
	forn(i, good.size()) {
		cout << k[bad[i].x] << ' ' << k[good[i].x] << el;
		cout << k[bad[i].y] << ' ' << k[good[i].y] << el;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}