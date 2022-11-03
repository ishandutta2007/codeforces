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
//#define endl '\n'
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

int n, x, y;
vvi a(N);
vc used(N), path(N), used1(N);

int dfs(int root) {
	used[root] = 1;
	if (root == y)
		return 1;
	fi(a[root].size()) {
		if (!used[a[root][i]]) {
			if (dfs(a[root][i])) {
				path[a[root][i]] = 1;
				return 1;
			}
		}
	}
	return 0;
}

int dfs1(int root) {
	used1[root] = 1;
	int k = 1;
	fi(a[root].size()) {
		if (!path[a[root][i]] && !used1[a[root][i]])
			k += dfs1(a[root][i]);
	}
	return k;
}

signed main()
{
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	cin >> n >> x >> y;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	--x; --y;
	fi(n - 1) {
		int v, u;
		cin >> v >> u;
		--v; --u;
		a[v].pb(u);
		a[u].pb(v);
	}
	dfs(x);
	path[x] = 1;

	int a1 = dfs1(x), a2 = dfs1(y);
	cout << n * (n - 1) - a1 * a2;

	return 0;
}