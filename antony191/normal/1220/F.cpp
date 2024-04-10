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

struct node {
	node *l, *r, *par;
	int x, d, max;
	node() { l = r = par = nullptr; d = 1; max = 1;  }
	node(int _x) { l = r = par = nullptr; x = _x; d = 1; max = 1;  }
};
typedef node* inode;

vector<int> done(vector<int> a) {
	int n = (int)a.size();
	vector<int> suf(n, 1);
	if (a.empty()) return suf;
	inode cur = new node(a.back());
	for (int i = n - 2; i >= 0; --i) {
		suf[i] = suf[i + 1];
		inode tmp = new node(a[i]);
		tmp->max = cur->d + 1;
		while (1) {
			if (cur->x < a[i]) {
				uax(cur->max, tmp->max);
				tmp->r = cur->l;
				cur->l = tmp;
				tmp->par = cur;
				tmp->d = cur->d + 1;
				cur = tmp;
				uax(suf[i], cur->max);
				break;
			}
			uax(tmp->max, cur->max + 1);
			if (cur->par == nullptr) {
				tmp->d = 1;
				tmp->r = cur;
				cur->par = tmp;
				cur = tmp;
				uax(suf[i], cur->max);
				break;
			}
			cur = cur->par;
		}
	}
	return suf;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	if (n == 1) return cout << "1 0", 0;
	int pos = -1;
	vector<int> a1(n), a;
	forn(i, n) {
		cin >> a1[i];
		if (!(--a1[i])) pos = i;
	}
	for (int i = pos + 1; i < n; ++i) a.push_back(a1[i]);
	forn(i, pos) a.push_back(a1[i]);
	n--;
	auto suf = done(a);
	reverse(all(a));
	auto pref = done(a);
	reverse(all(pref));
	int ans = inf, tmp = -1;
	forn(i, n - 1) {
		if (max(pref[i], suf[i + 1]) < ans) {
			tmp = i;
			ans = max(pref[i], suf[i + 1]);
		}
	}
	n++;
	cout << ans + 1 << ' ';
	cout << ((pos - (n - 2 - tmp) + n) % n) << el;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}