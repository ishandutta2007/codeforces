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
	cin.sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k, totalr = 0;
		cin >> n >> m >> k;
		vector<vector<char>> grid(n, vector<char>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> grid[i][j];
				totalr += grid[i][j] == 'R';
			}
		
		auto prox = [&m](pii a) {
			if (a.first % 2 == 0)
			{
				if (a.second == m - 1)
					return pii(a.first + 1, a.second);
				else
					return pii(a.first, a.second + 1);
			}
			else
			{
				if (a.second == 0)
					return pii(a.first + 1, a.second);
				else
					return pii(a.first, a.second - 1);
			}
		};

		pii cur = {0, 0};
		for (int i = 0; i < k; i++)
		{
			int nr = 0;
			while (nr < totalr / (k - i) || (i + 1 == k && cur.first != n))
			{
				nr += grid[cur.first][cur.second] == 'R';
				grid[cur.first][cur.second] = (i < 26 ? ('A' + i) : (i < 52 ? 'a' + (i - 26) : '0' + (i - 52)));
				cur = prox(cur);
			}

			totalr -= nr;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cout << grid[i][j];
			cout << endl;
		}
	}
}