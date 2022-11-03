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

const ld EPS = 1e-8;
const int N = (int)1e5 + 10;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;

int gcd(int a, int b) {
	if (!b)
		return a;
	return gcd(b, a % b);
}

signed main() {
#ifdef LOCALFILE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    IOboost;

	rn(q);
	fj(q) {
		rn(n);
		vi p(n);
		fi(n) {
			cin >> p[i];
			p[i] /= 100;
		}
		sort(p.begin(), p.end());
		reverse(p.begin(), p.end());
		int x, a, y, b;
		cin >> x >> a >> y >> b;
		if (y > x) {
			swap(x, y);
			swap(a, b);
		}
		int c = a * b / gcd(a, b);
		int k;
		cin >> k;
		int l = 0, r = n + 1;
		while (r - l > 1) {
			int m = (l + r) / 2;
			int r1 = 0;
			int sum = 0;
			fi(m / c) {
				sum += (x + y) * p[r1];
				++r1;
			}
			fi(m / a - m / c) {
				sum += x * p[r1];
				++r1;
			}
			fi(m / b - m / c) {
				sum += y * p[r1];
				++r1;
			}
			if (sum >= k)
				r = m;
			else
				l = m;
		}
		if (r == n + 1)
			cout << -1 << endl;
		else
			cout << r << endl;
	}
	
    return 0;
}