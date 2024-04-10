#pragma comment(linker, "/STACK:600000000")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <list>

#include <ctime>
#include <cassert>

using namespace std;

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "c";

const int NMAX = 101010;

int n, m, l[NMAX], r[NMAX], L[NMAX],R[NMAX], K[NMAX], ans[NMAX];
vector<pii> ev;
set <pii> S;
vector<pii> toremove;

int getans(int num) {
	set<pii>::iterator it = S.lower_bound(mp(r[num], -1));
	toremove.clear();
	while (it != S.end()) {
		if (K[it->sc] > 0) {
			forn(i, toremove.size())
				S.erase(toremove[i]);
			return it->sc;
		}
		toremove.pb(*it);
		++it;
	}
	cout << "NO" << endl;
	exit(0);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> m;
	forn(i, m) {
		scanf("%d%d", &l[i], &r[i]);
		ev.pb(mp(l[i], i + 1));
	}
	cin >> n;
	forn(i, n) {
		scanf("%d%d%d", &L[i], &R[i], &K[i]);
		ev.pb(mp(L[i], -(i + 1)));
	}
	sort(ev.begin(), ev.end());

	seta(ans, 255);
	forn(i, ev.size()) {
		if (ev[i].second < 0) {
			int num = (-ev[i].second) - 1;
			S.insert(mp(R[num], num));
		} else {
			int num = ev[i].second - 1;
			int idx = getans(num);
			ans[num] = idx;
			K[idx]--;
		}
	}
	cout << "YES" << endl;
	forn(i, m)
		printf("%d ", ans[i] + 1);

	return 0;
}