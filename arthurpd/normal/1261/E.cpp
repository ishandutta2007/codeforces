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

int main()
{
	int n;
	cin >> n;
	vi a(n);
	vi pi(n + 1);
	iota(all(pi), 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<vi> ans(n + 1, vi(n, -1));
	vector<vi> v = {pi};
	for (int i = 0; i < n; i++)
	{
		sort(all(v), [](const vi &lhs, const vi &rhs) { return sz(lhs) > sz(rhs); });
		vector<vi> prox;
		int remain = n + 1;
		for (int j = 0; j < sz(v); j++)
		{
			int x = min(sz(v[j]) - 1, a[i]);
			if (remain - sz(v[j]) < a[i] - x)
			{
				x = a[i] + sz(v[j]) - remain;
			}

			// debug(x);

			if (x > 0)
			{
				prox.emplace_back();
				for (int k = 0; k < x; k++)
				{
					prox.back().push_back(v[j][k]);
					ans[v[j][k]][i] = 1;
				}
			}

			if (sz(v[j]) - x > 0)
			{
				prox.emplace_back();
				for (int k = x; k < sz(v[j]); k++)
				{
					prox.back().push_back(v[j][k]);
					ans[v[j][k]][i] = 0;
				}
			}

			remain -= sz(v[j]);
			a[i] -= x;	
		}

		v = prox;
	}

	printf("%d\n", n + 1);
	for (int i = 0; i < n + 1; i++, printf("\n"))
		for (int j = 0; j < n; j++)
			printf("%c", '0' + ans[i][j]); 
}