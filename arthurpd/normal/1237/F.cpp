#pragma once

#include <bits/stdc++.h>
using namespace std;

template <class TH>
void _dbg(const char *sdbg, TH h) { cerr << sdbg << '=' << h << endl; }

template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a)
{
	while (*sdbg != ',')
		cerr << *sdbg++;
	cerr << '=' << h << ',';
	_dbg(sdbg + 1, a...);
}

template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> p)
{
	return os << "(" << p.first << ", " << p.second << ")";
}

template <class Iterable, class = typename enable_if<!is_same<string, Iterable>::value>::type>
auto operator<<(ostream &os, Iterable v) -> decltype(os << *begin(v))
{
	os << "[";
	for (auto vv : v)
		os << vv << ", ";
	return os << "]";
}

#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) ((int)(x).size())

// Return 1 if x > 0, 0 if x == 0 and -1 if x < 0.
template <class T>
int sign(T x) { return (x > 0) - (x < 0); }

template <class T>
T abs(const T &x) { return (x < T(0)) ? -x : x; }

// Pretty good compilation command:
// g++ -g a.cpp --std=c++14 -Wall -Wextra -Wno-unused-result -Wconversion -Wfatal-errors -fsanitize=undefined,address -o a.out

#define MAXN 3612

int rows[MAXN];
int cols[MAXN];
const ll mod = 998244353;

ll f[MAXN];
ll comb[MAXN][MAXN];

ll fat(int n)
{
	return f[n];
}

ll choose(int n, int k)
{
	if (n < k)
		return 0;
	return comb[n][k];
}

int h, w;

bool been_rows[MAXN][MAXN];
ll tab_rows[MAXN][MAXN];

ll pd_rows(int i, int k)
{
	if (k == 0)
		return 1;
	if (i + 1 >= h)
		return 0;

	if (been_rows[i][k])
		return tab_rows[i][k];

	ll retv = pd_rows(i + 1, k);
	if (rows[i] == 0 && rows[i + 1] == 0)
		retv = (retv + pd_rows(i + 2, k - 1)) % mod;

	been_rows[i][k] = true;
	return tab_rows[i][k] = retv;
}

bool been_cols[MAXN][MAXN];
ll tab_cols[MAXN][MAXN];

ll pd_cols(int i, int k)
{
	if (k == 0)
		return 1;
	if (i + 1 >= w)
		return 0;

	if (been_cols[i][k])
		return tab_cols[i][k];

	ll retv = pd_cols(i + 1, k);
	if (cols[i] == 0 && cols[i + 1] == 0)
		retv = (retv + pd_cols(i + 2, k - 1)) % mod;

	been_cols[i][k] = true;
	return tab_cols[i][k] = retv;
}

int main()
{
	f[0] = 1;
	for (int i = 1; i < MAXN; i++)
		f[i] = (i * f[i - 1]) % mod;

	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				comb[i][j] = 1;
			else
				comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
		}

	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, b, c, d;
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c >> d;
		rows[a - 1] = 1;
		rows[c - 1] = 1;
		cols[b - 1] = 1;
		cols[d - 1] = 1;
	}

	int ew = 0, eh = 0;
	for (int i = 0; i < h; i++)
		if (!rows[i]) eh++;
	for (int i = 0; i < w; i++)
		if (!cols[i]) ew++;

	ll ans = 0;
	for (int i = 0; i <= h; i++)
		for (int j = 0; j <= w; j++)
		{
			ll R = (pd_cols(0, i) * choose(ew - 2 * i, j)) % mod;
			ll C = (pd_rows(0, j) * choose(eh - 2 * j, i)) % mod;
			// debug(i, j, R * C, R, C);
			ans = (ans + ((((((R * C) % mod) * fat(i)) % mod) * fat(j)) % mod)) % mod;
		}

	cout << ans << endl;
}