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
#include <numeric>
#include <functional>
#include <limits>
#include <ctime>
#include <random>
#include <bitset>
#include <numeric>
#include <complex>
#include <stdlib.h>
#include <cassert>

#define mp make_pair
#define endl '\n'
#define sqr(x) ((x) * (x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int ll

#ifndef _getchar_nolock
#define _getchar_nolock getchar_unlocked
#define _putchar_nolock putchar_unlocked
#endif

#pragma warning(disable : 4996)
#pragma optimize("gtsy", on)
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<char> vc;

const ld PI = 3.141592653589793;
const ld EPS = 1e-8;
const int N = (int)1e5 + 10;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;

void solve() {

	int n;
	cin >> n;
	vi a(n);
	vi used(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
		used[a[i]] = 1;
	}
	vi b(n, -1);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (used[i] == 0) {
			int x = i;
			while (true) {
				if (used[a[x]] == 1) {
					b[x] = a[x];
					used[a[x]] = 2;
					++cnt;
				}
				if (b[x] == -1)
					break;
				x = b[x];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (b[i] == -1 && used[a[i]] != 2) {
			b[i] = a[i];
			++cnt;
			used[a[i]] = 2;
		}
	}
	vi p;
	for (int i = 0; i < n; ++i) {
		if (b[i] == -1 && used[i] == 2)
			p.push_back(i);
	}
	int x = p.size();
	for (int i = 0; i < n; ++i)
		if (b[i] == -1 && used[i] != 2)
			p.push_back(i);
	for (int i = 0; i < n; ++i) {
		if (b[i] != -1 && used[i] != 2)
			p.push_back(i);
	}
	if (x) {
		for (int i = 0; i < p.size() - x; ++i)
			b[p[i]] = p[i + x];
	}
	else if (!p.empty()) {
		for (int i = 1; i < p.size(); ++i)
			b[p[i - 1]] = p[i];
		b[p.back()] = p[0];
	}
	cout << cnt << endl;
	for (int i = 0; i < n; ++i)
		cout << b[i] + 1 << ' ';
	cout << endl;

	return;
}

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;
	
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();

	return 0;
}