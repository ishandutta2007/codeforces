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

#define MAXN 312345
vector<int> graph[MAXN];
int ans = 0;

int dfs(int a, int p)
{
	pair<int,int> res;
	for (int i = 0; i < sz(graph[a]); i++)
		if (graph[a][i] != p)
		{
			int x = dfs(graph[a][i], a);
			if (x > res.second)
				res.second = x;
			if (res.second > res.first)
				swap(res.first, res.second);
		}
	
	ans = max(ans, res.second + res.first + max(0, sz(graph[a]) - 2) + 1);
	return max(res.first, res.second) + max(0, sz(graph[a]) - 2) + 1;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int q, n, a, b;
	cin >> q;
	while (q--)
	{
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			graph[i].clear();

		for (int i = 1; i < n; i++)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		dfs(1, 1);
		cout << ans << endl;
	}
}