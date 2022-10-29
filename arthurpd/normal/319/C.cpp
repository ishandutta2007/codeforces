// https://codeforces.com/contest/319/problem/C

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
typedef long double ld;

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

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


#define MAXN 112345

int a[MAXN];
int b[MAXN];

ll tab[MAXN];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);

	tab[0] = 0;
	line_container l;
	l.add(-b[0], -tab[0]);

	for (int i = 1; i < n; i++)
	{
		tab[i] = -l.query(a[i]);
		l.add(-b[i], -tab[i]);
	}

	cout << tab[n-1] << endl;
}