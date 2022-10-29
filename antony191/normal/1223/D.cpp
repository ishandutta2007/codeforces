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

const int maxn = 300'000;
vector<int> pos[maxn];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> a(n);
		forn(i, n) {
			cin >> a[i];
			a[i]--;
			pos[a[i]].push_back(i);
		}
		int mx = 1, cnt = 1, t = 1;
		int i = 0, j = 0;
		while (pos[i].empty()) i++;
		j = i + 1;
		while (j < n && pos[j].empty()) j++;
		if (j == n) {
			cout << 0 << el;
			forn(i, n) pos[i].clear();
			continue;
		}
		while (j < n) {
			t++;
			if (pos[j][0] < pos[i].back()) {
				uax(mx, cnt);
				cnt = 1;
			}
			else cnt++;
			i = j; j++;
			while (j < n && pos[j].empty()) j++;
		}
		uax(mx, cnt);
		cout << t - mx << el;
		forn(i, n) pos[i].clear();
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}