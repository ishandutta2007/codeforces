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

#define pb push_back
#define mp make_pair
#define rn(n) int n; cin >> n;
#define fi(n) for (int i = 0; i < n; ++i)
#define fie(n) for (int i = 1; i <= n; ++i)
#define fir(l, r) for (int i = (l); i <= (r); ++i)
#define fj(n) for (int j = 0; j < n; ++j)
#define fje(n) for (int j = 1; j <= n; ++j)
#define fjr(l, r) for (int j = (l); j <= (r); ++j)
#define fv(i, n) for (int i = 0; i < n; ++i)
#define fve(i, n) for (int i = 1; i <= n; ++i)
#define fvr(j, l, r) for (int j = (l); j <= (r); ++j)
#define sc(n) scanf("%d", &n)
#define scc(n) scanf("%c", &n)
#define scs(n) scanf("%s", &n)
#define scl(n) scanf("%lld", &n)
#define endl '\n'
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define fll(x, a) memset(x, a, sizeof(x))
#define clr(x) memset(x, 0, sizeof(x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
//#ifndef LOCALFILE
//#define _putchar_nolock putchar_unlocked
//#define _getchar_nolock getchar_unlocked
//#endif
#define int ll

#pragma warning (disable : 4996)
#pragma optimize ("gtsy", on)
//#pragma comment(linker, "/STACK:134217728")

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
const int INF = (int)1e9 + 10;
const int MOD = 998244353;
const int N = (int)2e5 + 10;

int poww(int x, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res *= x;
			res %= MOD;
			--n;
		}
		else {
			x *= x;
			x %= MOD;
			n >>= 1;
		}
	}
	return res;
}

vvi prod(vvi& a, vvi& b) {
	int n = a.size(), p = a[0].size(), m = b[0].size();
	vvi c(n, vi(m));
	fi(n) {
		fj(m) {
			fv(k, p) {
				c[i][j] += a[i][k] * b[k][j] % MOD;
				c[i][j] %= MOD;
			}
		}
	}
	return c;
}

vvi pow1(vvi a, int n) {
	vvi res(a.size(), vi(a.size()));
	fi(a.size()) res[i][i] = 1;
	while (n) {
		while (n) {
			if (n & 1) {
				res = prod(res, a);
				--n;
			}
			else {
				a = prod(a, a);
				n >>= 1;
			}
		}
	}
	return res;
}

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	int n, m, l, r;
	cin >> n >> m >> l >> r;
	if (n * m % 2)
		cout << poww(r - l + 1, n * m);
	else if ((r - l + 1) % 2 == 0)
		cout << poww(r - l + 1, n * m - 1) * (r - l + 1) / 2 % MOD;
	else {
		int k = (r - l + 1) / 2;
		vvi a = { {k, k + 1}, {k + 1, k} };
		a = pow1(a, n * m);
		vvi dp = { { 1, 0 } };
		dp = prod(dp, a);
		cout << dp[0][0];
	}

	return 0;
}