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

#define MAXN 512345

struct edge
{
	int u, v, w;
} e[MAXN];

vector<int> graph[MAXN];
int k;

ll dfs(int a, int p)
{
	ll retv = 0;
	for (int i = 0; i < graph[a].size(); i++)
	{
		int b = e[graph[a][i]].u + e[graph[a][i]].v - a;
		if (b != p)
			retv += dfs(b, a);
	}

	multiset<int> s;
	for (int i = 0; i < graph[a].size(); i++)
	{
		int b = e[graph[a][i]].u + e[graph[a][i]].v - a;
		if (b != p)
			s.insert(-e[graph[a][i]].w);
	}

	int x = 0;
	int mn = inf;
	while (x < k && !s.empty())
	{
		int y = -(*s.begin());
		s.erase(s.begin());
		if (y > 0)
		{
			x++;
			mn = min(y, mn);
			retv += y;
		}
	}

	if (x == k)
	{
		for (int i = 0; i < graph[a].size(); i++)
		{
			int b = e[graph[a][i]].u + e[graph[a][i]].v - a;
			if (b == p)
			{
				// debug(e[graph[a][i]].w, mn);
				e[graph[a][i]].w -= mn;
			}
		}
	}

	// debug(a, retv);
	return retv;
}

int main()
{
	int n, q;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++)
			graph[i].clear();

		for (int i = 0; i < n-1; i++)
		{
			scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
			graph[e[i].u].push_back(i);
			graph[e[i].v].push_back(i);
		}

		printf("%lld\n", dfs(1, 1));
	}
}