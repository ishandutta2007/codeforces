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
 
 
struct rect {
	ll x, y, c;
 
	bool operator < (rect rhs) const { return x < rhs.x; }
};
 
#define MAXN 1123456
 
ll tab[MAXN];
rect r[MAXN];
int n;
 
int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld %lld %lld", &r[i].x, &r[i].y, &r[i].c);
 
	sort(r + 1, r + n + 1);
 
	line_container l;
	l.add(0, 0);
	
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		// tab[i] = -0x3f3f3f3f3f3f3f3fll;
		// for (int j = 0; j < i; j++)
		// tab[i] = max(tab[i], tab[j] - r[j].x * r[i].y + r[i].x * r[i].y - r[i].c);
		//
		// With convex hull trick:
		// max k * x + m
		// k = - r[j].x
		// m = tab[j]
 
		tab[i] = l.query(r[i].y) + r[i].x * r[i].y - r[i].c;
		ans = max(ans, tab[i]);
		l.add(-r[i].x, tab[i]);
	}
 
	printf("%lld\n", ans);
}