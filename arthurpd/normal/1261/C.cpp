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
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vi> grid(n + 2, vi(m + 2, 0));
	vector<vi> sum(n + 2, vi(m + 2, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			char c;
			scanf(" %c", &c);

			grid[i][j] = (c == '.' ? 0 : 1);
		}

	for (int i = 1; i <= n + 1; i++)
		for (int j = 1; j <= m + 1; j++)
			sum[i][j] = grid[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];


	// debug(grid);
	// debug(sum);

	vector<pii> ans;
	int val;
	int bot = 0, top = min((n - 1) / 2, (m - 1) / 2);
	vector<vi> res(n + 2, vi(m + 2, 0));
	while (bot <= top)
	{
		int mid = (bot + top) / 2;
		// debug(mid);
		vector<pii> src;

		for (int i = 0; i <= n + 1; i++)
			for (int j = 0; j <= m + 1; j++)
				res[i][j] = 0;

		for (int i = 1; i + 2 * mid <= n; i++)
			for (int j = 1; j + 2 * mid <= m; j++)
			{
				if (sum[i + 2 * mid][j + 2 * mid] + sum[i - 1][j - 1] - sum[i + 2 * mid][j - 1] - sum[i - 1][j + 2 * mid] == (2 * mid + 1) * (2 * mid + 1))
				{
					src.push_back({i + mid, j + mid});

					res[i][j] += 1;
					res[i + 2 * mid + 1][j] += -1;
					res[i][j + 2 * mid + 1] += -1;
					res[i + 2 * mid + 1][j + 2 * mid + 1] += 1;
				}
			}

		for (int i = 1; i <= n + 1; i++)
			for (int j = 1; j <= m + 1; j++)
				res[i][j] = res[i][j] + res[i - 1][j] + res[i][j - 1] - res[i - 1][j - 1];

		bool ok = true;
		for (int i = 0; i <= n + 1; i++)
			for (int j = 0; j <= m + 1; j++)
				if (sign(res[i][j]) != sign(grid[i][j]))
					ok = false;

		if (ok)
		{
			ans = src;
			val = mid;
			bot = mid + 1;
		}
		else
		{
			top = mid - 1;		
		}
	}

	for (pii kvp : ans)
		grid[kvp.first][kvp.second] = 2;


	printf("%d\n", val);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%c", (grid[i][j] == 2 ? 'X' : '.'));
		printf("\n");
	}

}