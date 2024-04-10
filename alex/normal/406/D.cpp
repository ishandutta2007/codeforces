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
const string name = "d";

const int NMAX = 100110;

int n, edge[NMAX], q;
int64 x[NMAX], y[NMAX];
vector<int> st;

int t[4 * NMAX];

void build(int v, int l, int r) {
	if (l == r) {
		t[v] = edge[l];
		return;
	}
	build(2 * v, l, (l + r) >> 1);
	build(2 * v + 1, (2 + l + r) >> 1, r);
	t[v] = max(t[2 * v], t[2 * v + 1]);
}

int get(int v, int l, int r, int ll, int rr) {
	if (ll > r || rr < l) return -1;
	if (ll <= l && r <= rr) return t[v];
	int t1 = get(2 * v, l, (l + r) >> 1, ll, rr);
	int t2 = get(2 * v + 1, (2 + l + r) >> 1, r, ll, rr);
	return max(t1, t2);
}

int hidden(int a, int b, int c, int zn) {
	int64 now = (x[c] - x[a]) * (y[b] - y[a]) - (y[c] - y[a]) * (x[b] - x[a]);
	now *= zn;
	return now <= 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	forn(i, n)
		scanf("%I64d%I64d", &x[i], &y[i]);

	forn(i, n)
		edge[i] = i;

	st.clear();
	st.pb(0);
	for (int i = 1; i < n; ++i) {
		while (st.size() >= 2 && !hidden(i, st[st.size() - 1], st[st.size() - 2], 1)) st.pop_back();
		edge[st[st.size() - 1]] = max(edge[st[st.size() - 1]], i);
		st.pb(i);
	}

	st.clear();
	st.pb(n - 1);
	for (int i = n - 2; i >= 0; --i) {
		while (st.size() >= 2 && !hidden(i, st[st.size() - 1], st[st.size() - 2], -1)) st.pop_back();
		edge[i] = max(edge[i], st[st.size() - 1]);
		st.pb(i);
	}

	build(1, 0, n - 1);

	cin >> q;
	forn(i, q) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (l > r) swap(l, r);
		if (l == r) {
			printf("%d ", l);
			continue;
		}
		l--, r -= 2;
		printf("%d ", get(1, 0, n - 1, l, r) + 1);
	}

	return 0;
}