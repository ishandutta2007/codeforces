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

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, x, y, z;

	cin >> n;
	vector<tuple<int,int,int,int>> p(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> z;
		p[i] = {x, y, z, i + 1};
	}

	vector<tuple<int,int,int,int>> tmp;
	sort(p.begin(), p.end());
	for (int i = 0; i <  sz(p); i++)
	{
		if (i + 1 < sz(p) && get<0>(p[i]) == get<0>(p[i + 1]) && get<1>(p[i]) == get<1>(p[i + 1]))
		{
			cout << get<3>(p[i]) << " " << get<3>(p[i + 1]) << endl;
			i++;
		}
		else
		{
			tmp.push_back(p[i]);
		}
	}

	p = tmp;
	tmp.clear();
	for (int i = 0; i < sz(p); i++)
	{
		if (i + 1 < sz(p) && get<0>(p[i]) == get<0>(p[i + 1]))
		{
			cout << get<3>(p[i]) << " " << get<3>(p[i + 1]) << endl;
			i++;
		}
		else
		{
			tmp.push_back(p[i]);
		}
	}

	p = tmp;
	tmp.clear();

	for (int i = 0; i + 1 < sz(p); i++)
	{
		cout << get<3>(p[i]) << " " << get<3>(p[i + 1]) << endl;
		i++;
	}
}