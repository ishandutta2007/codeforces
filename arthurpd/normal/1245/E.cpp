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

int n = 10;

int h[10][10];

pii move(pii cur)
{
	if (cur.first % 2 == 1)
	{
		if (cur.second == n - 1)
			return {cur.first - 1, cur.second};
		else
			return {cur.first, cur.second + 1};
	}
	else
	{
		if (cur.second == 0)
			return {cur.first - 1, cur.second};
		else
			return {cur.first, cur.second - 1};
	}
}

pii move(int i, int j, int k)
{
	if (i == 0 && j < k)
		return {i, j};

	pii res = {i, j};
	while (k--)
		res = move(res);
	return res;
}

double tab[10][10];
bool been[10][10];

double pd(int i, int j)
{
	if (i == 0 && j == 0)
		return 0;

	if (been[i][j])
		return tab[i][j];

	double retv = 0;
	double pstay = 0;
	for (int k = 1; k <= 6; k++)
	{
		pii prox = move(i, j, k);
		if (prox != pii(i, j))
			retv += min(pd(prox.first, prox.second), pd(prox.first - h[prox.first][prox.second], prox.second)) / 6;
		else
			pstay += 1 / 6.0;
	}

	retv = (retv + 1) / (1 - pstay);

	been[i][j] = true;
	return tab[i][j] = retv;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> h[i][j];

	printf("%.20lf\n", pd(9, 0));
}