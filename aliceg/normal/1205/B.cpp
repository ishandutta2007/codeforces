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

int ans = INF;

void find_min_cycle(int n, vector<vector<int>>& a) {
	vector<vector<int>> dp(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)
				dp[i][j] = 0;
			else if (a[i][j])
				dp[i][j] = 1;
			else
				dp[i][j] = INF;
		}
	}
	fv(k, n) {
		fi(n) {
			fj(n) {
				if (i != j && a[i][k] && a[j][k])
					ans = min(ans, dp[i][j] + 2);
			}
		}
		fi(n) {
			fj(n) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
}

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	rn(n);
	vi b;
	fi(n) {
		rn(x);
		if (x)
			b.pb(x);
	}
	n = (int)b.size();
	if (n > 128) {
		cout << 3;
		return 0;
	}
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j && (b[i] & b[j]))
				a[i][j] = 1;
		}
	}
	find_min_cycle(n, a);
	if (ans == INF)
		cout << -1;
	else
		cout << ans;

	return 0;
}