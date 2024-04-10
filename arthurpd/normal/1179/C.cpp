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

// int main()
// {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	cin.exceptions(cin.failbit);
// }

/*
	Segment Tree with Lazy updates:
		Range update and range query in O(log(MAX_RANGE))
		Binary search on tree in O(log(MAX_RANGE))
		Given as an example since it is not worth it to copy a generic tree during a contest.
	
	Solves: https://codeforces.com/contest/1179/problem/C
*/

#define left(i) ((i) << 1)
#define right(i) (((i) << 1) + 1)

struct segtree
{
	vector<int> val, delta;
	int n;

	segtree(int n) : val(4 * (n + 1), 0), delta(4 * (n + 1), 0), n(n) {}

	void prop(int id, int l, int r)
	{
		if (l != r)
		{
			// Updates need to be numerically stackable (e.g. not valid to have a list of updates).
			delta[left(id)] += delta[id];
			delta[right(id)] += delta[id];
		}

		val[id] += delta[id]; // Node value needs to be obtainable without propagating all the way to root.
		delta[id] = 0;
	}

	// Sum x in all elements in range [a, b].
	void update(int id, int l, int r, int a, int b, int x)
	{
		if (a == l && b == r)
		{
			delta[id] += x;
			prop(id, l, r);
		}
		else
		{
			prop(id, l, r);
			int mid = (l + r) / 2;
			if (b <= mid)
			{
				update(left(id), l, mid, a, b, x);
				prop(right(id), mid + 1, r);
			}
			else if (a > mid)
			{
				update(right(id), mid + 1, r, a, b, x);
				prop(left(id), l, mid);
			}
			else
			{
				update(left(id), l, mid, a, mid, x);
				update(right(id), mid + 1, r, mid + 1, b, x);
			}

			val[id] = min(val[left(id)], val[right(id)]);
		}
	}

	// Get the minimum value in range [a, b].
	int get(int id, int l, int r, int a, int b)
	{
		prop(id, l, r);
		if (a == l && b == r)
			return val[id];
		else
		{
			int mid = (l + r) / 2;
			if (b <= mid)
				return get(left(id), l, mid, a, b);
			else if (a > mid)
				return get(right(id), mid + 1, r, a, b);
			else
				return min(get(left(id), l, mid, a, mid), get(right(id), mid + 1, r, mid + 1, b));
		}
	}

	// Find index of rightmost element which is less than x. (works because this is a seg of min)
	int bsearch(int id, int l, int r, int x)
	{
		prop(id, l, r);

		if (l == r)
			return (val[id] < x) ? l : -1;
		else
		{
			int mid = (l + r) / 2;
			prop(left(id), l, mid);
			prop(right(id), mid + 1, r);
			if (val[right(id)] < x)
				return bsearch(right(id), mid + 1, r, x);
			else
				return bsearch(left(id), l, mid, x);
		}
	}

	int get(int a, int b)
	{
		return get(1, 1, n - 1, a, b);
	}

	void update(int a, int b, int x)
	{
		update(1, 1, n - 1, a, b, x);
	}

	int bsearch(int x)
	{
		return bsearch(1, 1, n - 1, x);
	}
};

#define MAXN 312345

int a[MAXN];
int b[MAXN];

int main(void)
{
	int n, m, q, tp, x, y;
	scanf("%d %d", &n, &m);

	segtree seg(1000001);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		seg.update(1, a[i], -1);
	}

	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &b[i]);
		seg.update(1, b[i], 1);
	}

	scanf("%d", &q);
	while (q--)
	{
		scanf("%d %d %d", &tp, &x, &y);
		if (tp == 1)
		{
			seg.update(1, a[x], 1);
			a[x] = y;
			seg.update(1, a[x], -1);
		}
		else
		{
			seg.update(1, b[x], -1);
			b[x] = y;
			seg.update(1, b[x], 1);
		}

		int tmp = seg.bsearch(0);

		// Test of get and bsearch. Make sure all to the right are non-negative.
		if (tmp != 1000000)
			assert(seg.get(tmp == -1 ? 1 : (tmp + 1), 1000000) >= 0);
		if (tmp != -1)
			assert(seg.get(tmp, tmp) < 0);

		printf("%d\n", tmp);
	}
}