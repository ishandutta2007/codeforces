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

#define MAXN 212345

int q, n;
ll p[MAXN];
ll x, a, y, b;
ll k;

ll eval(int m)
{
	ll nt = 0, na = 0, nb = 0;
	for (int i = 1; i <= m; i++)
	{
		if (i % a == 0 && i % b == 0)
		{
			nt++;
		}
		else if (i % a == 0)
		{
			na++;
		}
		else if (i % b == 0)
		{
			nb++;
		}
	}

	ll retv = 0;
	int j = n - 1;
	while (j >= 0 && nt > 0)
	{
		retv += (p[j] * (x + y)) / 100;
		nt--;
		j--;
	}

	while (j >= 0 && na > 0)
	{
		retv += (p[j] * (x)) / 100;
		na--;
		j--;
	}

	while (j >= 0 && nb > 0)
	{
		retv += (p[j] * (y)) / 100;
		nb--;
		j--;
	}

	return retv;
}

int main()
{
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lld", &p[i]);
		sort(p, p + n);
		
		scanf("%lld %lld %lld %lld %lld", &x, &a, &y, &b, &k);
		if (x < y)
		{
			swap(x, y);
			swap(a, b);
		}

		int bot = 0, top = n;
		while (bot < top)
		{
			int mid = (bot + top) / 2;
			if (eval(mid) >= k)
			{
				top = mid;
			}
			else
			{
				bot = mid + 1;
			}			
		}

		if (eval(bot) >= k)
		{
			printf("%d\n", bot);
		}
		else
		{
			printf("-1\n");
		}		
	}
}