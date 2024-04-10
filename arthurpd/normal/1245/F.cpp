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
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()

// Return 1 if x > 0, 0 if x == 0 and -1 if x < 0.
template <class T>
int sign(T x) { return (x > 0) - (x < 0); }

template <class T>
T abs(const T &x) { return (x < T(0)) ? -x : x; }

// Pretty good compilation command:
// g++ -g a.cpp --std=c++14 -Wall -Wextra -Wno-unused-result -Wconversion -Wfatal-errors -fsanitize=undefined,address -o a.out

int da[60];
int db[60];

ll tab[60][2][2];
bool been[60][2][2];

ll pd(int i, bool eqa, bool eqb)
{
	if (i < 0)
		return 1;

	if (been[i][eqa][eqb])
		return tab[i][eqa][eqb];

	ll retv = 0;
	for (int a = 0; a <= 1 - (eqa && (da[i] == 0)); a++)
		for (int b = 0; b <= 1 - (eqb && (db[i] == 0)); b++)
			if (!(a && b))
				retv += pd(i - 1, eqa && (da[i] == a), eqb && (db[i] == b));

	been[i][eqa][eqb] = true;
	return tab[i][eqa][eqb] = retv;
}

ll solve(ll a, ll b)
{
	if (a < 0 || b < 0)
		return 0;

	for (int i = 0; i < 32; i++)
		da[i] = ((a & (1ll << i)) ? 1 : 0);

	for (int i = 0; i < 32; i++)
		db[i] = ((b & (1ll << i)) ? 1 : 0);

	memset(been, 0, sizeof(been));
	return pd(31, true, true);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll a, b;
		cin >> a >> b;
		cout << (solve(b, b) - solve(b, a - 1) - solve(a - 1, b) + solve(a - 1, a - 1)) << endl;
	}
}