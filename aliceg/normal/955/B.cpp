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
#pragma comment(linker, "/STACK:16777216")

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

const ld EPS = 1e-10;
const int N = 1e7 + 10;
const int INF = 1e9 + 10;
const int MOD = 1e9;

int main()
{
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	string s;
	cin >> s;

	vi cnt(26);
	fi(s.length()) {
		cnt[s[i] - 'a'] += 1;
	}
	int k = 0;
	vi a(4);
	fi(26) {
		if (cnt[i]) {
			if (k == 4) {
				cout << "No";
				return 0;
			}
			a[k] = cnt[i];
			++k;
		}
	}
	if (k == 2 && a[0] > 1 && a[1] > 1)
		cout << "Yes";
	else if (k == 3 && (a[0] > 1 || a[1] > 1 || a[2] > 1))
		cout << "Yes";
	else if (k == 4)
		cout << "Yes";
	else
		cout << "No";

	return 0; 
}