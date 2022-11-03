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
#define int ll

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

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	int n;
	cin >> n;
	vi cnt(n + 1);
	cnt[1] = 1;
	for (int i = 2; i <= n; ++i) {
		cnt[i] = 2;
		for (int j = 2; j * j <= i; ++j) {
			if (i % j)
				continue;
			int c = 1, k = i;
			while (k % j == 0) {
				k /= j;
				++c;
			}
			cnt[i] = cnt[k] * c % MOD;
			break;
		}
	}
	vi dp(n + 1);
	dp[1] = 1;
	vi pref(n + 1);
	pref[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = (cnt[i] + pref[i - 1]) % MOD;
		pref[i] = (pref[i - 1] + dp[i]) % MOD;
	}
	cout << dp[n];

	return 0;
}