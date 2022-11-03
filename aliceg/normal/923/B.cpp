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
const int N = 1e4 + 10;
const int INF = 1e4 + 10;
const int MOD = 1e9 + 7;

int main(){
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;
	
	rn(n);
	vll v(n), t(n), d(n), p(n + 1);
	vector<pair<ll, ll>> a;
	fi(n)
		cin >> v[i];
	fi(n)
		cin >> t[i];
	for (int i = n - 1; i >= 0; --i)
		p[n - i] = p[n - i - 1] + t[i];
	fi(n) {
		ll l = 0, r = n - i + 1;
		while (r - l > 1) {
			ll m = (l + r) / 2;
			if (v[i] - p[n - i] + p[m] < t[n - m])
				l = m;
			else
				r = m;
		}
		a.pb(mp(n - l, -1));
		a.pb(mp(i, 1));
		a.pb(mp(i, 2));
		if (l != 0)
			d[n - l] += v[i] - p[n - i] + p[l];
	}
	sort(a.begin(), a.end());
	ll b = 0;
	fi(a.size()) {
		if (a[i].second == 2)
			cout << b * t[a[i].first] + d[a[i].first] << ' ';
		else
			b += a[i].second;
	}

	return 0;
}