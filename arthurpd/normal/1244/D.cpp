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

#define MAXN 112345

vector<int> graph[MAXN];
int c[MAXN][4];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n;
	for (int k = 1; k <= 3; k++)
		for (int i = 1; i <= n; i++)
			cin >> c[i][k];

	for (int i = 0; i + 1 < n; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int start;
	for (int i = 1; i <= n; i++)
	{
		if (graph[i].size() > 2)
		{
			cout << -1 << endl;
			return 0;
		}

		if (graph[i].size() == 1)
			start = i;
	}

	vector<int> pi = {1, 2, 3};
	ll ans = infll;
	vector<int> best_color;

	vector<int> color(n + 1);
	do
	{
		ll tmp = 0;
		int cur = start;
		int prev = start;
		for (int i = 0; i < n; i++)
		{
			color[cur] = pi[i % 3];
			tmp += c[cur][pi[i % 3]];
			for (int j = 0; j < graph[cur].size(); j++)
				if (graph[cur][j] != prev)
				{
					prev = cur;
					cur = graph[cur][j];
					break;
				}
		}

		if (tmp < ans)
		{
			ans = min(ans, tmp);
			best_color = color;
		}

	} while (next_permutation(pi.begin(), pi.end()));

	cout << ans << endl;
	for (int i = 1; i <= n; i++)
		cout << best_color[i] << " ";
	cout << endl;
}