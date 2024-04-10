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
const int N = (int)1e3 + 10;
const int INF = (int)2e9;
const int MOD = 998244353;

bool merge_sort(vi& a, vi& b, int l, int r, string& s, int& p) {
    if (r - l <= 1)
        return 1;
    int m = (l + r) >> 1;
    if (!merge_sort(a, b, l, m, s, p))
        return 0;
    if (!merge_sort(a, b, m, r, s, p))
        return 0;
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (p > s.length())
            return 0;
        if (s[p] == '0') {
            b[k] = a[i];
            ++i;
            ++p;
        }
        else {
            b[k] = a[j];
            ++j;
            ++p;
        }
        ++k;
    }
    while (i < m) {
        b[k] = a[i];
        ++i;
        ++k;
    }
    while (j < r) {
        b[k] = a[j];
        ++j;
        ++k;
    }
    for (int x = l; x < r; ++x)
        a[x] = b[x];
    return 1;
}

void solve() {
	
	string s;
	cin >> s;
	for (int n = 1; n < N; ++n) {
		vi a(n);
		for (int i = 0; i < n; ++i)
			a[i] = i;
		vi b(n);
        int p = 0;
        if (merge_sort(a, b, 0, n, s, p) && p == s.length()) {
            vi ans(n);
            for (int i = 0; i < n; ++i)
                ans[a[i]] = i + 1;
            cout << n << endl;
            for (int i = 0; i < n; ++i)
                cout << ans[i] << ' ';
            return;
        }
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