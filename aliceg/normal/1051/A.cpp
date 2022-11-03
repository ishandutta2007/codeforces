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
//#define int ll

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

	rn(t);
	fj(t) {
		string s;
		cin >> s;
		int a = 0, b = 0, c = 0, a1 = 0, b1 = 0, c1 = 0;
		fi(s.length()) {
			if (isdigit(s[i])) {
				++a;
				a1 = i;
			}
			else if (s[i] - 'a' >= 0) {
				++b;
				b1 = i;
			}
			else {
				++c;
				c1 = i;
			}
		}
		if ((!a) + (!b) + (!c) == 2) {
			if (a) {
				s[0] = 'a';
				s[1] = 'A';
			}
			if (b) {
				s[0] = '1';
				s[1] = 'A';
			}
			if (c) {
				s[0] = '1';
				s[1] = 'a';
			}
		}
		else if (!a) {
			s[b > 1 ? b1 : c1] = '1';
		}
		else if (!b) {
			s[a > 1 ? a1 : c1] = 'a';
		}
		else if (!c) {
			s[b > 1 ? b1 : a1] = 'A';
		}
		cout << s << endl;
	}


	return 0;
}