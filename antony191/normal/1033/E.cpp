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

map<pair<int, int>, int> aaa;

int s1(vector<int> & c, vector<int> & a) {
	int b;
	if (aaa.count({ 0, (int)c.size() - 1 }) > 0) b = aaa[{0, (int)c.size() - 1}];
	else {
		cout << "? " << (int)c.size() << endl;
		forn(i, c.size()) cout << c[i] + 1 << ' ';
		cout << endl;
		cin >> b;
		aaa[{0, (int)c.size() - 1}] = b;
	}
	int l = 0, r = (int)a.size() - 1;
	while (r != l) {
		int m = (l + r) >> 1;
		int ans1;
		if (m == l) ans1 = 0;
		else {
			cout << "? " << m - l + 1 << endl;
			for (int i = l; i <= m; ++i) cout << a[i] + 1 << ' ';
			cout << endl;
			cin >> ans1;
		}
		cout << "? " << m - l + 1 + (int)c.size() << endl;
		forn(i, c.size()) cout << c[i] + 1 << ' ';
		for (int i = l; i <= m; ++i) cout << a[i] + 1 << ' ';
		cout << endl;
		int ans2;
		cin >> ans2;
		if (ans2 - ans1 - b) r = m;
		else l = m + 1;
	}
	return l;
}

int s2(vector<int> & c, int v, bool k = 1) {
	int l = 0, r = (int)c.size() - 1;
	while (r != l) {
		int m = (l + r) >> 1;
		int ans1;
		if (m == l) ans1 = 0;
		else {
			if (k && aaa.count({ l, m }) > 0) ans1 = aaa[{l, m}];
			else {
				cout << "? " << m - l + 1 << endl;
				for (int i = l; i <= m; ++i) cout << c[i] + 1 << ' ';
				cout << endl;
				cin >> ans1;
				if (k) aaa[{l, m}] = ans1;
			}
		}
		cout << "? " << m - l + 2 << endl;
		for (int i = l; i <= m; ++i) cout << c[i] + 1 << ' ';
		cout << v + 1 << endl;
		int ans2;
		cin >> ans2;
		if (ans2 > ans1) r = m;
		else l = m + 1;
	}
	return l;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> com, p(n);
	vector<bool> cl(n), comp(n);
	comp[0] = 1; com.push_back(0);
	vector<int> ans;
	firn(i, n) {
		ans.clear();
		forn(j, n)
			if (!comp[j]) ans.push_back(j);
		int v = s1(com, ans);
		int u = s2(com, ans[v]);
		com.push_back(ans[v]);
		comp[ans[v]] = 1;
		cl[ans[v]] = 1 ^ cl[com[u]];
		p[ans[v]] = com[u];
		ans.clear();
		forn(j, com.size())
			if (cl[com[j]] != cl[com[u]])
				ans.push_back(com[j]);
		int tmp1;
		if (ans.size() == 1) continue;
		cout << "? " << (int)ans.size() << endl;
		forn(j, ans.size()) cout << ans[j] + 1 << ' ';
		cout << endl;
		cin >> tmp1;
		if (!tmp1) continue;
		ans.pop_back();
		u = s2(ans, com.back(), 0);
		vector<int> c1, c2;
		int j;
		for (j = com.back(); j != p[j]; j = p[j])
			c1.push_back(j);
		c1.push_back(j);
		for (j = ans[u]; j != p[j]; j = p[j])
			c2.push_back(j);
		c2.push_back(j);
		while (c1.back() == c2.back() && c1[(int)c1.size() - 2] == c2[(int)c2.size() - 2])
			c1.pop_back(), c2.pop_back();
		cout << "N " << (int)c1.size() + (int)c2.size() - 1 << endl;
		forn(j, c1.size()) cout << c1[j] + 1 << ' ';
		for (int j = (int)c2.size() - 2; j + 1; --j) cout << c2[j] + 1 << ' ';
		cout << endl;
		return 0;
	}
	vector<int> aa;
	forn(i, n) if (!cl[i]) aa.push_back(i);
	cout << "Y " << (int)aa.size() << endl;
	forn(i, aa.size()) cout << aa[i] + 1 << ' ';
	cout << endl;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}