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
const int MOD = 998244353;
const int N = 3e5 + 10;

signed main()
{
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	rn(n);
	rn(k);
	vector<vvi> dp(n + 1, vvi(k + 1, vi(4)));
	dp[1][1][2] = dp[1][1][3] = 1;
	if (k > 1)
		dp[1][2][0] = dp[1][2][1] = 1;
	fir(2, n) {
		fje(k) {
			dp[i][j][0] = dp[i - 1][j - 1][2] + dp[i - 1][j - 1][3]\
				 + dp[i - 1][j][0];
			dp[i][j][1] = dp[i - 1][j - 1][2] + dp[i - 1][j - 1][3]\
				+ dp[i - 1][j][1];
			if (j >= 2) {
				dp[i][j][0] += dp[i - 1][j - 2][1];
				dp[i][j][1] += dp[i - 1][j - 2][0];
			}
			dp[i][j][2] = dp[i - 1][j][2] + dp[i - 1][j][0]\
				+ dp[i - 1][j][1] + dp[i - 1][j - 1][3];
			dp[i][j][3] = dp[i - 1][j][3] + dp[i - 1][j][0]\
				+ dp[i - 1][j][1] + dp[i - 1][j - 1][2];
			dp[i][j][0] %= MOD;
			dp[i][j][1] %= MOD;
			dp[i][j][2] %= MOD;
			dp[i][j][3] %= MOD;
		}
	}
	cout << (dp[n][k][0] + dp[n][k][1] + dp[n][k][2] + dp[n][k][3]) % MOD;

	return 0;
}