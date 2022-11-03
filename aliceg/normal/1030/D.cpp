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

	ll n, m, k;
	cin >> n >> m >> k;
	if ((2 * n * m) % k) {
		cout << "NO";
		return 0;
	}
	if (k % 2) {
		int p = -1, q = -1;
		fie(sqrt(k) + 2) {
			if (k % i == 0 && n % i == 0 && m % (k / i) == 0) {
				p = i;
				q = k / i;
			}
			if (k % i == 0 && m % i == 0 && n % (k / i) == 0) {
				q = i;
				p = k / i;
			}
		}
		cout << "YES" << endl;
		cout << "0 0\n";
		if (p == 1) {
			cout << n / p << " 0\n";
			cout << "0 " << 2 * m / q << endl;
		}
		else {
			cout << 2 * n / p << " 0\n";
			cout << "0 " << m / q << endl;
		}
	}
	else {
		k /= 2;
		int p = -1, q = -1;
		fie(sqrt(k) + 2) {
			if (k % i == 0 && n % i == 0 && m % (k / i) == 0) {
				p = i;
				q = k / i;
			}
			if (k % i == 0 && m % i == 0 && n % (k / i) == 0) {
				q = i;
				p = k / i;
			}
		}
		cout << "YES" << endl;
		cout << "0 0" << endl;
		cout << n / p << " 0\n";
		cout << "0 " << m / q;
	}

	return 0;
}