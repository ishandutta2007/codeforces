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
vi used(N), a(N);
vii help;
int n, k;

int dp(int x) {
	int ans = 0;
	if (a[x])
		ans = dp(a[x] - 1);
	if (help.size() > 0 && help[help.size() - 1].second >= max(0, x - k)) {
		ans += min(x + k, n - 1) - help[help.size() - 1].second;
		help[help.size() - 1].second = min(x + k, n - 1);
	}
	else {
		help.pb(mp(max(x - k, 0), min(x + k, n - 1)));
		ans += min(x + k, n - 1) - max(x - k, 0) + 1;
	}
	used[x] = ans;
	return ans;
}

__int32 main()
{
#ifdef Stalin
	freopen("file.in.txt", "r", stdin);
	freopen("file.out.txt", "w", stdout);
#endif
	IOboost;

	cin >> n >> k;
	fi(n)
		cin >> a[i];
	for (int i = n - 1; i >= 0; --i) {
		if (!used[i]) {
			help = {};
			dp(i);
		}
	}
	fi(n)
		cout << used[i] << ' ';

	return 0;
}