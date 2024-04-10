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

ll solve(vector<int> a, int n, int m)
{
	vector<int> tab(n + m + 3, 0);
	ll retv = 0;
	vector<vector<int>> x(n);
	for (int i = 0; i < m; i++)
		x[a[i]].push_back(a[i] + i + 1);

	for (int i = 0; i < n; i++)
		sort(x[i].rbegin(), x[i].rend());
	
	for (int i = 0; i < n; i++)
	{
		retv += min(i, m + 1 - tab[i]);

		for (auto v : x[i])
			tab[v] = max(tab[v], tab[v+1] + 1);
	}

	return retv;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	if (n == 1)
	{
		cout << (m > 0 ? 0 : 1) << endl;
		return 0;
	}

	vector<int> a(m);
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		a[i]--;
	}

	ll ans = solve(a, n, m);

	for (int i = 0; i < m; i++)
		a[i] = n - a[i] - 1;
	ans += solve(a, n, m);

	ans += n;

	cout << ans << endl;
}