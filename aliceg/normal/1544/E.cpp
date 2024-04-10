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

	string s;
	cin >> s;
	vi a(26);
	for (int i = 0; i < s.length(); ++i)
		a[s[i] - 'a']++;
	int x = -1, y = -1, z = -1;
	for (int i = 0; i < 26; ++i) {
		if (a[i] == 1 && z == -1)
			z = i;
		if (a[i] && x == -1)
			x = i;
		else if (a[i] && y == -1)
			y = i;
	}
	string ans;
	if (z != -1) {
		ans += ('a' + z);
		--a[z];
		for (int i = 0; i < 26; ++i)
			while (a[i]) {
				ans += ('a' + i);
				--a[i];
			}
	}
	else {
		ans += ('a' + x);
		--a[x];
		if (a[x] && ((int)s.length() - a[x] - 1 >= a[x] - 1)) {
			ans += ('a' + x);
			--a[x];
			for (int i = x + 1; i < 26; ++i) {
				while (a[x] && a[i]) {
					ans += ('a' + i);
					ans += ('a' + x);
					--a[x];
					--a[i];
				}
				while (!a[x] && a[i]) {
					ans += ('a' + i);
					--a[i];
				}
			}
		}
		else if (y != -1) {
			ans += ('a' + y);
			--a[y];
			for (int i = y + 1; i < 26; ++i) {
				if (a[i] && a[x]) {
					while (a[x]) {
						ans += ('a' + x);
						--a[x];
					}
					ans += ('a' + i);
					--a[i];
					break;
				}
			}
			for (int i = y; i < 26; ++i)
				while (a[i]) {
					ans += ('a' + i);
					--a[i];
				}
			while (a[x]) {
				ans += ('a' + x);
				--a[x];
			}
		}
		else
			ans = s;
	}
	cout << ans << endl;

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