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


int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {-1, 0, 1, -1, 0, 1, 1, -1};

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n + 4, vector<char>(m + 4, '*'));
	for (int i = 2; i <= n + 1; i++)
		for (int j = 2; j <= m + 1; j++)
			cin >> grid[i][j];

	auto check = [&](int x, int y) {
		if (grid[x][y] != '*')
			return false;

		for (int k = -1; k <= 0; k++)
			for (int l = -1; l <= 0; l++)
			{
				int cnt = 0;
				for (int i = 0; i <= 1; i++)
					for (int j = 0; j <= 1; j++)
						cnt += (grid[x + k + i][y + l + j] == '*');

				if (cnt == 1)
					return true;
			}
		
		return false;
	};

	queue<pair<int,int>> q;

	for (int i = 2; i <= n + 1; i++)
		for (int j = 2; j <= m + 1; j++)
			if (check(i, j))
			{
				grid[i][j] = '.';
				q.push({i, j});
			}

	while (!q.empty())
	{
		pii cur = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
			if (check(cur.first + dx[i], cur.second + dy[i]))
			{
				grid[cur.first + dx[i]][cur.second + dy[i]] = '.';
				q.push({cur.first + dx[i], cur.second + dy[i]});
			}
	}

	for (int i = 2; i <= n + 1; i++)
	{
		for (int j = 2; j <= m + 1; j++)
			cout << grid[i][j];
		cout << endl;
	}
}