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
#ifndef LOCALFILE
#define _putchar_nolock putchar_unlocked
#define _getchar_nolock getchar_unlocked
#endif
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

const ld EPS = 1e-8;
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;

int dist(int a, int b) {
	return min(abs(a - b), 4 - abs(a - b));
}

bool check(vii a) {
	sort(a.begin(), a.end());
	if (a[0].first == a[1].first && a[2].first == a[3].first) {
		int d1 = dist(a[0].second, a[1].second), d2 = dist(a[2].second, a[3].second);
		return (d1 == 1 && d2 == 2) || (d1 == 2 && d2 == 1);
	}
	return 0;
}

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	rn(t);
	fv(k, t) {
		int n, m;
		cin >> n >> m;
		if (n == 4) {
			vector<pair<int, pii>> a(n * m);
			fi(n) {
				fj(m) {
					rn(x);
					a[i * m + j] = { x, { j, i } };
				}
			}
			sort(a.rbegin(), a.rend());
			vii v;
			int sum = 0;
			fi(n * m) {
				v.pb(a[i].second);
				sum += a[i].first;
				if (v.size() == 4 && check(v)) {
					v.pop_back();
					sum -= a[i].first;
				}
				if (v.size() == 4)
					break;
			}
			if (m > 1 && !check({ a[0].second, a[1].second, a[3].second, a[4].second })) {
				int sum1 = a[0].first + a[1].first + a[3].first + a[4].first;
				sum = max(sum, sum1);
			}
			cout << sum << endl;
		}
		else {
			vi a(n * m);
			fi(n) {
				fj(m)
					cin >> a[i * m + j];
			}
			sort(a.rbegin(), a.rend());
			int sum = 0;
			fi(n) sum += a[i];
			cout << sum << endl;
		}
	}

	return 0;
}