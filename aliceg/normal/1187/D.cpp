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
//#define int ll

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

void change(int v, int L, int R, int i, int x, vi& a) {
	if (R - L == 1) {
		a[v] = x;
		return;
	}
	int M = (L + R) / 2;
	if (i < M)
		change(v * 2, L, M, i, x, a);
	else
		change(v * 2 + 1, M, R, i, x, a);
	a[v] = max(a[v * 2], a[v * 2 + 1]);
	return;
}

int find_max(int v, int L, int R, int r, vi& a) {
	if (R <= r)
		return a[v];
	if (L >= r)
		return 0;
	int M = (L + R) / 2;
	return max(find_max(v * 2, L, M, r, a), find_max(v * 2 + 1, M, R, r, a));
}

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	rn(t);
	fv(k, t) {
		rn(n);
		int K = 0;
		while ((1 << K) < n)
			++K;
		vii a(n), b(n);
		fi(n) {
			cin >> a[i].first;
			a[i].second = b[i].second = i;
		}
		fi(n) cin >> b[i].first;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		vi num(n);
		fi(n)
			num[a[i].second] = i;
		vi maxx(2 << K);
		bool flag = 1;
		fj(n) {
			int i = num[j];
			if (a[i].first != b[i].first) {
				flag = 0;
				break;
			}
			change(1, 0, 1 << K, i, b[i].second, maxx);
			int x = find_max(1, 0, 1 << K, i, maxx);
			if (x > b[i].second) {
				flag = 0;
				break;
			}
		}
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}