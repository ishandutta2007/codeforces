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

	int n, m, k, x, y;
	cin >> n >> m >> k;

	vector<vector<int>> lobs(n+1), cobs(m + 1);
	for (int i = 1; i <= n; i++)
	{
		lobs[i].push_back(0);
		lobs[i].push_back(m + 1);
	}

	for (int i = 1; i <= m; i++)
	{
		cobs[i].push_back(0);
		cobs[i].push_back(n + 1);
	}

	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		lobs[x].push_back(y);
		cobs[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)
		sort(lobs[i].begin(), lobs[i].end());
	for (int i = 1; i <= m; i++)
		sort(cobs[i].begin(), cobs[i].end());

	ll cnt = 0;	
	x = 1, y = 0;
	int dir = 1;
	int minx = -inf;
	int maxx = inf;
	int miny = -inf;
	int maxy = inf;
	while (true)
	{
		if (dir == 1)
		{
			int proxy = *upper_bound(lobs[x].begin(), lobs[x].end(), y) - 1;

			proxy = min(proxy, maxy);
			if (proxy == y)
				break;

			minx = max(minx, x + 1);
			cnt += proxy - y;
			y = proxy;
			dir = 2;
		}
		else if (dir == 2)
		{
			int proxx = *upper_bound(cobs[y].begin(), cobs[y].end(), x) - 1;

			proxx = min(proxx, maxx);
			if (proxx == x)
				break;

			maxy = min(maxy, y - 1);

			cnt += proxx - x;
			x = proxx;
			dir = 3;
		}
		else if (dir == 3)
		{
			int proxy = *(upper_bound(lobs[x].begin(), lobs[x].end(), y) - 1) + 1;

			proxy = max(proxy, miny);
			if (proxy == y)
				break;

			maxx = min(maxx, x - 1);

			cnt += y - proxy;
			y = proxy;
			dir = 4;
		}
		else
		{
			int proxx = *(upper_bound(cobs[y].begin(), cobs[y].end(), x) - 1) + 1;

			proxx = max(proxx, minx);
			if (proxx == x)
				break;

			miny = max(miny, y + 1);

			cnt += x - proxx;
			x = proxx;
			dir = 1;
		}		
	}

	if (cnt == (n*1ll*m - k))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}	

}