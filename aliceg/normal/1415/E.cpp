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
#ifndef LOCALFILE
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
const int INF = (int)1e18 + 10;
const int MOD = 998244353;
const int N = (int)2e5 + 10;

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	rn(n); rn(k);
	vi c(n);
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	if (k == 0) {
		sort(c.rbegin(), c.rend());
		int sum = 0;
		for (int i = 0; i < n; ++i)
			sum += c[i] * (n - i - 1);
		cout << sum;
		return 0;
	}
	vi c1, c2;
	for (int i = 0; i < n; ++i) {
		if (c[i] < 0)
			c1.push_back(c[i]);
		else
			c2.push_back(c[i]);
	}
	int x = c1.size(), y = c2.size();
	sort(c1.begin(), c1.end());
	sort(c2.rbegin(), c2.rend());
	int sum2 = 0, sum = 0;
	for (int i = 0; i < y; ++i) {
		sum2 += c2[i] * (y - i - 1);
		sum += c2[i];
	}
	vi p(x / (k + 1) + 1), suf(x + 1), sum1(x + 1);
	for (int i = 0; i < x / (k + 1); ++i) {
		int s = 0;
		for (int j = i * (k + 1); j < (i + 1) * (k + 1); ++j)
			s += c1[j] * i;
		p[i + 1] = p[i] + s;
	}
	for (int i = x - 1; i >= 0; --i)
		suf[i] = suf[i + 1] + c1[i];
	for (int i = x - 1; i >= 0; --i)
		sum1[i] = sum1[i + 1] + c1[i] * i;
	int ans = -INF;
	for (int l = x; l >= (x + k) / (k + 1); --l) {
		int a = (x - l) / k, r = (x - l) % k;
		int res = p[a] + sum1[a * (k + 1) + r] - suf[a * (k + 1) + r] * (x - l);
		res += (suf[a * (k + 1)] - suf[a * (k + 1) + r]) * a;
		res += sum2 + sum * l;
		ans = max(ans, res);
	}
	cout << ans;

	return 0;
}