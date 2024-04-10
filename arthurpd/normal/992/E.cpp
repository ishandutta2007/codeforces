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
	BIT: element update, range sum query and sum lower_bound in O(log(N)).
*/

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

int main(void)
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	bit<long long> bit(n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		bit.update(i, a[i]);
	}

	int p, x;
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d", &p, &x);
		bit.update(p, x - a[p]);
		a[p] = x;

		long long sum = 0;
		while (true)
		{
			p = bit.lower_bound(sum);
			if (p > n)
				break;

			if (bit.query(p) == 2 * bit.query(p - 1))
				break;
			
			sum = 2 * bit.query(p);
		}

		printf("%d\n", p > n ? -1 : p);
	}
}