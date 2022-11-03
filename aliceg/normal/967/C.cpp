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
typedef vector <ll> vll;
typedef vector <vll> vvll;

const ld EPS = 1e-8;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

signed main()
{
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	int n, m, cl, ce, v;
	cin >> n >> m >> cl >> ce >> v;
	vi l(cl), e(ce);
	fi(cl)
		cin >> l[i];
	fi(ce)
		cin >> e[i];

	rn(q);
	fi(q) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) {
			cout << abs(y1 - y2) << endl;
			continue;
		}
		int left = -1, right = ce;
		while (right - left > 1) {
			int m = (left + right) / 2;
			if (e[m] >= min(y1, y2))
				right = m;
			else
				left = m;
		}
		int er;
		if (right == ce)
			er = INF;
		else
			er = e[right];
		left = -1, right = ce;
		while (right - left > 1) {
			int m = (left + right) / 2;
			if (e[m] <= max(y1, y2))
				left = m;
			else
				right = m;
		}
		int el;
		if (left == -1)
			el = INF;
		else
			el = e[left];
		left = -1, right = cl;
		while (right - left > 1) {
			int m = (left + right) / 2;
			if (l[m] <= max(y1, y2))
				left = m;
			else
				right = m;
		}
		int ledl;
		if (left == -1)
			ledl = INF;
		else
			ledl = l[left];
		left = -1, right = cl;
		while (right - left > 1) {
			int m = (left + right) / 2;
			if (l[m] >= min(y1, y2))
				right = m;
			else
				left = m;
		}
		int ledr;
		if (right == cl)
			ledr = INF;
		else
			ledr = l[right];
		cout << min((abs(x1 - x2) + v - 1) / v + min(abs(er - y1) + abs(er - y2), \
			abs(el - y1) + abs(el - y2)), abs(x1 - x2) + min(abs(ledr - y1) + abs(ledr - y2), \
				abs(ledl - y1) + abs(ledl - y2))) << endl;
	}

	return 0;
}