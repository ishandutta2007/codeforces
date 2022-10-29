// https://codeforces.com/contest/1179/problem/D

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

/*
	Line Container (most common for convex hull trick). Amortized O(log N) per operation.
		Container where you can add lines of the form kx+m, and query maximum values at points x.
		Useful for dynamic programming.
	
	Source: https://github.com/kth-competitive-programming/kactl/blob/master/content/contest/template.cpp
*/

struct line
{
	mutable ll k, m, p;
	bool operator<(const line &o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct line_container : multiset<line, less<>>
{
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;

	ll div(ll a, ll b)
	{ // floored division
		return a / b - ((a ^ b) < 0 && a % b);
	}

	bool isect(iterator x, iterator y)
	{
		if (y == end())
		{
			x->p = inf;
			return false;
		}
		if (x->k == y->k)
			x->p = x->m > y->m ? inf : -inf;
		else
			x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}

	void add(ll k, ll m)
	{
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z))
			z = erase(z);
		if (x != begin() && isect(--x, y))
			isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}

	ll query(ll x)
	{
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};


#define MAXN 512345

vector<int> graph[MAXN];
int n;

void put_edge(int a, int b)
{
	graph[a].push_back(b);
	graph[b].push_back(a);
}

ll sub_size[MAXN];
ll ans;
ll tab[MAXN];

void dfs(int a, int p)
{
	sub_size[a] = 1;
	for (int i = 0; i < graph[a].size(); i++)
	{
		if (graph[a][i] != p)
		{
			dfs(graph[a][i], a);
			sub_size[a] += sub_size[graph[a][i]];
		}
	}
	
	tab[a] = sub_size[a] * (n - sub_size[a]);
	for (int i = 0; i < graph[a].size(); i++)
	{
		if (graph[a][i] != p)
		{
			tab[a] = max(tab[a], tab[graph[a][i]] + (sub_size[a] - sub_size[graph[a][i]]) * (n - sub_size[a]));
		}
	}
	
	line_container l;
	l.add(0, 0);
	for (int i = 0; i < graph[a].size(); i++)
	{
		// ans = max(ans , tab[graph[a][i]]);
		// for (int j = i - 1; j >= 0; j--)
		// {
		// 	ans = max(ans , tab[graph[a][i]] + tab[graph[a][j]] - sub_size[graph[a][i]] * sub_size[graph[a][j]]);
		// }

		ans = max(ans, l.query(sub_size[graph[a][i]]) + tab[graph[a][i]]);
		l.add(-sub_size[graph[a][i]], tab[graph[a][i]]);
	}
}

int main(void)
{
	int a, b;

	scanf("%d", &n);

	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		put_edge(a, b);
	}

	if (n == 2)
	{
		printf("2\n");
		return 0;
	}

	int root;
	for (int i = 1; i < n; i++)
		if (graph[i].size() > 1)
			root = i;

	dfs(root, root);

	cout << (ans) + (n) * 1ll * (n-1) / 2 << endl;
}