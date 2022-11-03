#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <limits>
#include <ctime>
#include <cassert>

#define pb push_back
#define mp make_pair
#define endl '\n'
#define sqr(x) ((x) * (x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
#ifndef _getchar_nolock
#define _putchar_nolock putchar_unlocked
#define _getchar_nolock getchar_unlocked
#endif
//#define int ll

#pragma warning (disable : 4996)
#pragma optimize ("gtsy", on)
//#pragma comment(linker, "/STACK:536870912")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef vector <char> vc;

const ld EPS = 1e-8;
const int N = (int)5e5 + 10;
const int INF = (int)2e9;
const int MOD = 998244353;
const int K = 17;

int a[2 << K];
int mod[2 << K];

void push(int v) {
	if (!mod[v])
		return;
	mod[v * 2] = mod[v * 2 + 1] = 1;
	a[v * 2] = a[v * 2 + 1] = a[v];
	mod[v] = 0;
	return;
}

void change(int v, int L, int R, int l, int r, int x) {
	if (l <= L && R <= r) {
		a[v] = x;
		mod[v] = 1;
		return;
	}
	if (l >= R || L >= r)
		return;
	int M = (L + R) / 2;
	push(v);
	change(v * 2, L, M, l, r, x);
	change(v * 2 + 1, M, R, l, r, x);
	a[v] = max(a[v * 2], a[v * 2 + 1]);
	return;
}

int find(int v, int L, int R) {
	if (R - L == 1)
		return L;
	int M = (L + R) / 2;
	push(v);
	if (a[v * 2 + 1])
		return find(v * 2 + 1, M, R);
	return find(v * 2, L, M);
}

void solve() {
	int n;
	cin >> n;
	set<pii> lu;
	set<int> l, u;
	change(1, 0, 1 << K, 0, 1, 1);
	bool is_locked = 0;
	vector<string> c(n + 1);
	c[0] = "blue";
	int last = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		if (c[i] == "lock")
			l.insert(i);
		else if (c[i] == "unlock")
			u.insert(i);
		else if (!is_locked)
			change(1, 0, 1 << K, i, i + 1, 1);
		if (c[i] == "lock" && !is_locked) {
			is_locked = 1;
			last = i;
		}
		if (c[i] == "unlock" && is_locked) {
			lu.insert({ last, i });
			is_locked = 0;
		}
	}
	u.insert(n + 1);
	if (is_locked)
		lu.insert({ last, n + 1 });
	cout << c[find(1, 0, 1 << K)] << endl;
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int j;
		string q;
		cin >> j >> q;
		if (q == c[j]) {
			cout << c[find(1, 0, 1 << K)] << endl;
			continue;
		}
		if (c[j] == "lock") {
			auto it = lu.lower_bound({ j, 0 });
			if (it != lu.end() && it->first == j) {
				auto it1 = l.upper_bound(j);
				int r = it->second;
				lu.erase(it);
				if (it1 != l.end() && *it1 < r) {
					lu.insert({ *it1, r });
					r = *it1;
				}
				change(1, 0, 1 << K, j + 1, r, 1);
			}
			l.erase(j);
		}
		else if (c[j] == "unlock") {
			auto it = lu.lower_bound({ j, 0 });
			if (it != lu.begin() && (--it)->second == j) {
				int left = it->first, r = *u.upper_bound(j);
				auto it1 = lu.upper_bound({ j, 0 });
				if (it1 != lu.end() && it1->second == r)
					lu.erase(it1);
				lu.erase(it);
				lu.insert({ left, r });
				change(1, 0, 1 << K, j + 1, r, 0);
			}
			u.erase(j);
		}
		else
			change(1, 0, 1 << K, j, j + 1, 0);

		c[j] = q;

		if (c[j] == "lock") {
			auto it = lu.lower_bound({ j, 0 });
			if (it == lu.begin() || (--it)->second < j) {
				it = lu.lower_bound({ j, 0 });
				int r = *u.upper_bound(j);
				if (it != lu.end() && it->second == r)
					lu.erase(it);
				lu.insert({ j, r });
				change(1, 0, 1 << K, j, r, 0);
			}
			l.insert(j);
		}
		else if (c[j] == "unlock") {
			auto it = lu.lower_bound({ j, 0 });
			if (it != lu.begin() && (--it)->second > j) {
				int l1 = it->first, r = it->second;
				lu.erase(it);
				auto it1 = l.upper_bound(j);
				if (it1 != l.end() && *it1 < r) {
					lu.insert({ *it1, r });
					r = *it1;
				}
				lu.insert({ l1, j });
				change(1, 0, 1 << K, j + 1, r, 1);
			}
			u.insert(j);
		}
		else {
			auto it = lu.upper_bound({ j, 0 });
			if (it == lu.begin() || (--it)->second < j)
				change(1, 0, 1 << K, j, j + 1, 1);
		}

		cout << c[find(1, 0, 1 << K)] << endl;
	}

	return;
}

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	solve();

	return 0;
}