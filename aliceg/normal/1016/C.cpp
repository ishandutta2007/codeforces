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
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int N = 3e5 + 10;

signed main()
{
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	rn(n);
	vi a(n), b(n);
	fi(n) cin >> a[i];
	fi(n) cin >> b[i];

	vi suf(n + 1);
	suf[n] = 0;
	fie(n) {
		suf[n - i] = suf[n - i + 1] + a[n - i] + b[n - i];
	}
	vi sum(n + 1);
	fi(n) {
		sum[0] += a[i] * i;
		sum[1] += b[i] * (i + 1);
	}
	fi(n) {
		sum[0] += b[n - i - 1] * (i + n);
		if (i != n - 1)
			sum[1] += a[n - i - 1] * (i + n + 1);
	}
	fie(n - 1) {
		if (i % 2)
			sum[i + 1] = sum[i - 1] + suf[i + 1] * 2 - b[i - 1] * (2 * n - 1) - b[i] * (2 * n - 2) + \
			b[i - 1] * (2 * i - 1) + b[i] * 2 * i + a[i] * 2;
		else
			sum[i + 1] = sum[i - 1] + suf[i + 1] * 2 - a[i - 1] * (2 * n - 1) - a[i] * (2 * n - 2) + \
			a[i - 1] * (2 * i - 1) + a[i] * 2 * i + b[i] * 2;
	}
	int ans = 0;
	fi(n + 1)
		ans = max(ans, sum[i]);
	cout << ans;

	return 0;
}