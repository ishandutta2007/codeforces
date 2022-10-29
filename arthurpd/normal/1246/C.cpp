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

const int mod = 1000000007;

inline int join(int a, int b)
{
	return (a + b) % mod;
}

#define left(i) ((i) << 1)
#define right(i) (((i) << 1) + 1)
#define MAXN 2023

struct segtree
{
	int val[4 * MAXN];
	int n;

	segtree(int n) : n(n) {}

	void update(int id, int l, int r, int a, int x)
	{
		if (l == r)
			val[id] = x;
		else
		{
			int mid = (l + r) / 2;
			if (a <= mid)
				update(left(id), l, mid, a, x);
			else
				update(right(id), mid + 1, r, a, x);

			val[id] = join(val[left(id)], val[right(id)]);
		}
	}

	int get(int id, int l, int r, int a, int b)
	{
		if (l == a && r == b)
			return val[id];
		else
		{
			int mid = (l + r) / 2;
			if (b <= mid)
				return get(left(id), l, mid, a, b);
			else if (a > mid)
				return get(right(id), mid + 1, r, a, b);
			else
				return join(get(left(id), l, mid, a, mid), get(right(id), mid + 1, r, mid + 1, b));
		}
	}

	int get(int a, int b)
	{
		if (a > b)
			return 0;
		return get(1, 0, n - 1, a, b);
	}

	void update(int a, int x)
	{
		update(1, 0, n - 1, a, x);
	}
};

int n, m;
int grid[MAXN][MAXN];
int gsum[MAXN][MAXN];

int get_sum(int a, int b, int c, int d)
{
	if (a > b || c > d)
		return 0;
	return gsum[b][d] - gsum[b][c - 1] - gsum[a - 1][d] + gsum[a - 1][c - 1];
}

int tab[MAXN][MAXN][2];

int main()
{
	// n = 2000, m = 2000;
	cin >> n >> m;

	vector<queue<int>> seg[2];
	vector<int> segsum[2];
	for (int i = 1; i <= m + 1; i++)
	{
		seg[0].emplace_back();
		segsum[0].emplace_back(0);
	}

	for (int i = 1; i <= n + 1; i++)
	{
		seg[1].emplace_back();
		segsum[1].emplace_back(0);
	}

	char c;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			// c = '.';
			scanf(" %c", &c);
			grid[i][j] = (c == 'R');
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			gsum[i][j] = gsum[i - 1][j] + gsum[i][j - 1] - gsum[i - 1][j - 1] + grid[i][j];

	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
		{
			for (int dir = 0; dir <= 1; dir++)
			{
				if (i == n && j == m)
				{
					tab[i][j][dir] = 1;
				}
				else
				{
					int retv = 0;
					if (dir == 0)
					{
						while (!seg[1][i].empty() && sz(seg[1][i]) > m - j - get_sum(i, i, j + 1, m))
						{
							segsum[1][i] = (segsum[1][i] - seg[1][i].front() + mod) % mod;
							seg[1][i].pop();
						}
						// debug(i, j, sz(seg[1][i]), segsum[1][i]);

						retv = segsum[1][i];
						// for (int k = 1; k <= m - j - get_sum(i, i, j + 1, m); k++)
						// 	retv = (retv + tab[i][j + k][1]) % mod;
					}
					else
					{
						while (!seg[0][j].empty() && sz(seg[0][j]) > n - i - get_sum(i + 1, n, j, j))
						{
							segsum[0][j] = (segsum[0][j] - seg[0][j].front() + mod) % mod;
							seg[0][j].pop();
						}

						// debug(i, j, sz(seg[0][j]), segsum[0][j]);

						// queue<int> tmp;
						// while (!seg[0][j].empty())
						// {
						// 	int x = seg[0][j].front();
						// 	seg[0][j].pop();
						// 	debug(x);
						// 	tmp.push(x);
						// }
						// seg[0][j] = tmp;

						retv = segsum[0][j];

						// for (int k = 1; k <= n - i - get_sum(i + 1, n, j, j); k++)
						// 	retv = (retv + tab[i + k][j][0]) % mod;
					}

					tab[i][j][dir] = retv;
				}
			}

			for (int dir = 0; dir <= 1; dir++)
				if (dir == 0)
				{
					// debug(j, tab[i][j][dir]);
					seg[0][j].push(tab[i][j][dir]);
					segsum[0][j] = (segsum[0][j] + tab[i][j][dir]) % mod;
				}
				else
				{
					seg[1][i].push(tab[i][j][dir]);
					segsum[1][i] = (segsum[1][i] + tab[i][j][dir]) % mod;
				}
		}

	if (n == 1 && m == 1)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << ((tab[1][1][0] + tab[1][1][1]) % mod) << endl;
	}
}