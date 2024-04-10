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
//#define int ll

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
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	rn(t);
	fv(k, t) {
		rn(n);
		string s;
		cin >> s;
		vii a(10, { N, -1 });
		fi(n) {
			a[s[i] - '0'].first = min(a[s[i] - '0'].first, i);
			a[s[i] - '0'].second = i;
		}
		int r = 0, maxr = -1, mid = 0;
		while (r < 10 && maxr < a[r].first) {
			maxr = max(maxr, a[r].second);
			++r;
		}
		bool flag = 1;
		if (r != 10) {
			mid = maxr;
			a[r].second = -1;
			fi(n) {
				if (s[i] - '0' == r && i < maxr)
					a[r].second = i;
			}
			maxr = -1;
			fir(r, 9) {
				if (maxr > a[i].first)
					flag = 0;
				maxr = max(maxr, a[i].second);
			}
		}
		if (!flag)
			cout << '-' << endl;
		else {
			fi(n) {
				if (s[i] - '0' < r || (s[i] - '0' == r && i > mid))
					cout << '1';
				else
					cout << '2';
			}
			cout << endl;
		}
	}

	return 0;
}