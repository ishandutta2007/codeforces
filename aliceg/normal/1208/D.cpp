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
#include <random>

#define pb push_back
#define mp make_pair
#define rn(n) int n; cin >> n
#define fi(n) for (int i = 0; i < (int)n; ++i)
#define fie(n) for (int i = 1; i <= (int)n; ++i)
#define fir(l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define fj(n) for (int j = 0; j < (int)n; ++j)
#define fje(n) for (int j = 1; j <= (int)n; ++j)
#define fjr(l, r) for (int j = (int)(l); j <= (int)(r); ++j)
#define fv(i, n) for (int i = 0; i < (int)n; ++i)
#define fve(i, n) for (int i = 1; i <= (int)n; ++i)
#define fvr(j, l, r) for (int j = (int)(l); j <= (int)(r); ++j)
#define sc(n) scanf("%d", &n)
#define scc(n) scanf("%c", &n)
#define scs(n) scanf("%s", &n)
#define scl(n) scanf("%l64d", &n)
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
//#pragma comment(linker, "/STACK:16777216")

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

const ld EPS = 1e-9;
const int N = (int)1e5 + 10;
const int INF = (int)1e18 + 10;
const int MOD = (int)1e9 + 7;
const int K = 18;

vi a(2 << K, INF);
vi mod(2 << K);

void push(int v) {
	a[v * 2] -= mod[v];
	a[v * 2 + 1] -= mod[v];
	mod[v * 2] += mod[v];
	mod[v * 2 + 1] += mod[v];
	mod[v] = 0;
	return;
}

void update(int v) {
	a[v] = min(a[v * 2], a[v * 2 + 1]);
	return;
}

void change(int v, int L, int R, int l, int r, int x) {
	if (l <= L && R <= r) {
		a[v] -= x;
		mod[v] += x;
		return;
	}
	if (l >= R || L >= r)
		return;
	push(v);
	int M = (L + R) / 2;
	change(v * 2, L, M, l, r, x);
	change(v * 2 + 1, M, R, l, r, x);
	update(v);
	return;
}

int find(int v, int L, int R, int x) {
	if (R - L == 1)
		return L;
	int M = (L + R) / 2;
	push(v);
	if (a[v * 2 + 1] <= x)
		return find(v * 2 + 1, M, R, x);
	return find(v * 2, L, M, x);
}

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	rn(n);
	vi s(n);
	fi(n) cin >> s[i];
	a[(1 << K)] = 0;
	fie(n - 1) {
		a[i + (1 << K)] = a[i + (1 << K) - 1] + i;
	}
	for (int i = (1 << K) - 1; i > 0; --i)
		a[i] = min(a[i * 2], a[i * 2 + 1]);
	vi ans(n);
	for (int i = n - 1; i >= 0; --i) {
		ans[i] = find(1, 0, 1 << K, s[i]) + 1;
		change(1, 0, 1 << K, ans[i], n, ans[i]);
	}
	fi(n) cout << ans[i] << ' ';

	return 0;
}