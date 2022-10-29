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

template <class T>
struct bit
{
	int n, LOGN;
	vector<T> val;
	bit(int _n) : n(_n), LOGN(log2(n + 1)), val(_n + 1, 0) {}

	// val[pos] += x
	void update(int pos, T x)
	{
		for (int i = pos; i <= n; i += -i & i)
			val[i] += x;
	}

	// sum of range [1, pos]
	T query(int pos)
	{
		T retv = 0;
		for (int i = pos; i > 0; i -= -i & i)
			retv += val[i];
		return retv;
	}

	// min pos such that sum of [1, pos] >= sum, or n + 1 if none exists.
	int lower_bound(T x)
	{
		T sum = 0;
		int pos = 0;

		for (int i = LOGN; i >= 0; i--)
			if (pos + (1 << i) <= n && sum + val[pos + (1 << i)] < x)
				sum += val[pos += (1 << i)];

		return pos + 1; // pos will have position of largest value less than x.
	}
};


#define MAXN 212345

int main()
{
	int n, q;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d", &n);
		n += 2;
		vector<int> a(n);
		map<int,int> rdm;
		for (int i = 1; i + 1 < n; i++)
		{
			scanf("%d", &a[i]);
			rdm[a[i]] = 1;
		}

		int id = 0;
		for (auto &kvp : rdm)
			kvp.second = id++;

		a[0] = 0;
		a[n-1] = id - 1;
		for (int i = 1; i + 1 < n; i++)
			a[i] = rdm[a[i]];

		// debug(a);
		vector<int> l(id, inf);
		vector<int> r(id, -inf);

		for (int i = 0; i < n; i++)
			l[a[i]] = min(l[a[i]], i + 1);

		for (int i = 0; i < n; i++)
			r[a[i]] = max(r[a[i]], i + 1);

		bit<int> bt(n + 1);
		int ans = inf;
		int j = -1;
		for (int i = 0; i < id; i++)
		{
			// debug(l[i], r[i]);
			while (j + 1 < id && bt.query(l[j + 1]) == j + 1 - i)
			{
				j++;
				// debug(i, j);
				bt.update(r[j], 1);
				// bt.update(l[j], 1);
				ans = min(ans, i + (id - j - 1));
			}

			bt.update(r[i], -1);
			// bt.update(l[i], -1);
		}

		printf("%d\n", ans);
	}
}