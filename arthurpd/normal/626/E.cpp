// https://codeforces.com/contest/626/problem/E

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

// int main()
// {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// }

/*
	Ternary Search:
		Finds the smallest x in range [bot, top] such that f(x) is maximum in O(lg(top - bot)).

	Constraints:
		f(x) is strictly increasing for some interval [bot, x1], constant in an interval [x1, x2]
		and strictly decreasing in a interval [x2, top]. x1 <= x2 are arbitrary values where [x1, x2] 
		is a plateau of optimal solutions.

	Usage:
		Call the function passing a lambda expression or function f.
	
	Source: modified from https://github.com/kth-competitive-programming/kactl/blob/master/content/various/TernarySearch.h
*/

template <typename F>
int ternary_search(const F &f, int bot, int top)
{
	while (top - bot >= 5)
	{
		int mid = (bot + top) / 2;
		if (f(mid) < f(mid + 1))
			bot = mid;
		else
			top = mid + 1;
	}

	for (int i = bot + 1; i <= top; i++)
		if (f(i) > f(bot))
			bot = i;

	return bot;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	vector<ll> pref(n + 1);
	for (int i = 1; i <= n; i++)
		pref[i] = pref[i-1] + a[i-1];

	pii sol = {0, 0};
	double val = -infll;
	for (int i = 0; i < n; i++)
	{
		auto f = [&a, &i, &n, &pref](int x) {
			return (pref[n] - pref[n-x] + pref[i+1] - pref[i-x] - (2ll*x + 1)*a[i]) / (2.0 * x + 1.0);
		};

		int x = ternary_search(f, 0, min(i, n - i - 1));
		if (f(x) > val)
		{
			val = f(x);
			sol = {i, x};
		}
	}

	cout << (2 * sol.second + 1) << endl;
	for (int i = sol.first; i >= sol.first - sol.second; i--)
		cout << a[i] << " ";

	for (int i = n - 1; i >= n - sol.second; i--)
		cout << a[i] << " ";

	cout << endl;
}