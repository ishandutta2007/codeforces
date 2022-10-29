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
#pragma comment(linker, "/STACK:1024000000")
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

int n, m;

struct aa{
	int x1, y1, x2, y2;
};

vector<aa> solve(deque<bool> a[300][300]) {
	vector<aa> ans;
	while (!a[0][0].empty()) {
		ans.push_back({ 1, 1, 2, 1 });
		a[1][0].push_front(a[0][0].back());
		a[0][0].pop_back();
	}
	while (!a[n - 1][m - 1].empty()) {
		ans.push_back({ n, m, n - 1, m });
		a[n - 2][m - 1].push_front(a[n - 1][m - 1].back());
		a[n - 1][m - 1].pop_back();
	}
	forn(i, n)
		forn(j, m) {
		if (i == j && i == 0) continue;
		if (i == n - 1 && j == m - 1) continue;
		while (!a[i][j].empty()) {
			if (a[i][j].back()) {
				if (j != m - 1) {
					ans.push_back({ i + 1, j + 1, i + 1, m }); 
					a[i][j].pop_back();
					a[i][m - 1].push_front(1);
					continue;
				}
				if (i != n - 1) {
					ans.push_back({ i + 1, m, n, m });
					a[i][j].pop_back();
					continue;
				}
			}
			else {
				if (j != 0) {
					ans.push_back({ i + 1, j + 1, i + 1, 1 });
				}
				if (i != 0) {
					ans.push_back({ i + 1, 1, 1, 1 });
				}
				a[i][j].pop_back();
				continue;
			}
			a[i][j].pop_back();
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	deque<bool> a[300][300];
	string tmp;
	forn(i, n)
		forn(j, m) {
		cin >> tmp;
		forn(k, tmp.size())
			if (tmp[k] >= '0' && tmp[k] <= '1')
			a[i][j].push_back(tmp[k] - '0');
	}
	auto ans1 = solve(a);
	deque<bool> b[300][300];
	forn(i, n)
		forn(j, m) {
		cin >> tmp;
		forn(k, tmp.size()) {
			if (tmp[k] >= '0' && tmp[k] <= '1')
			b[i][j].push_back(tmp[k] - '0');
		}
		reverse(all(b[i][j]));
	}
	auto ans2 = solve(b);
	reverse(all(ans2));
	cout << (int)(ans1.size() + ans2.size()) << '\n';
	forn(i, ans1.size())
		cout << ans1[i].x1 << ' ' << ans1[i].y1 << ' ' << ans1[i].x2 << ' ' << ans1[i].y2 << '\n';
	forn(i, ans2.size())
		cout << ans2[i].x2 << ' ' << ans2[i].y2 << ' ' << ans2[i].x1 << ' ' << ans2[i].y1 << '\n';
#ifdef _DEBUG
	system("pause");
#endif
	cin >> n;
	return 0;
}