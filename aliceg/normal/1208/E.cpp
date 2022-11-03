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
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;
const int K = 20;

int ans[2 << K];
int mod[2 << K];

void push(int v) {
	ans[v * 2] += mod[v];
	ans[v * 2 + 1] += mod[v];
	mod[v * 2] += mod[v];
	mod[v * 2 + 1] += mod[v];
	mod[v] = 0;
	return;
}

void update(int v) {
	ans[v] = max(ans[v * 2], ans[v * 2 + 1]);
	return;
}

void change(int v, int L, int R, int l, int r, int x) {
	if (l <= L && R <= r) {
		ans[v] += x;
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

int find(int v, int L, int R, int i) {
	if (R - L == 1)
		return ans[v];
	push(v);
	int M = (L + R) / 2;
	if (i < M)
		return find(v * 2, L, M, i);
	return find(v * 2 + 1, M, R, i);
}

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	rn(n); rn(w);
	fv(k, n) {
		rn(m);
		vi a(m);
		fi(m) cin >> a[i];
		multiset<int> s;
		fi(m) {
			s.insert(-a[i]);
			if (i > w - m)
				s.erase(s.find(-a[i - w + m - 1]));
			if (*s.begin() <= 0 || i >= w - m)
				change(1, 0, 1 << K, i, i + 1, -*s.begin());
		}
		vi suf(m + 1);
		suf[m] = 0;
		for (int i = m - 1; i >= 0; --i)
			suf[i] = max(suf[i + 1], a[i]);
		change(1, 0, 1 << K, m, w - m, suf[0]);
		fi(m) {
			int r = i + w - m;
			if (r >= m && r < (1 << K))
				change(1, 0, 1 << K, r, r + 1, suf[i]);
		}
	}
	fi(w)
		cout << find(1, 0, 1 << K, i) << ' ';

	return 0;
}