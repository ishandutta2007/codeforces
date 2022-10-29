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
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()

// Return 1 if x > 0, 0 if x == 0 and -1 if x < 0.
template <class T>
int sign(T x) { return (x > 0) - (x < 0); }

template <class T>
T abs(const T &x) { return (x < T(0)) ? -x : x; }

// Pretty good compilation command:
// g++ -g a.cpp --std=c++14 -Wall -Wextra -Wno-unused-result -Wconversion -Wfatal-errors -fsanitize=undefined,address -o a.out

#define left(i) ((i) << 1)
#define right(i) (((i) << 1) + 1)

struct segtree
{
	vector<int> val;
	int n;

	segtree(int n) : val(4 * (n + 1), 0), n(n) {}

	void update(int id, int l, int r, int a, int x)
	{
		if (l == r)
			val[id] = x;
		else
		{
			int mid = (l + r) / 2;
			if (a <= mid)
				update(left(id), l, mid, a, x);
			else
				update(right(id), mid + 1, r, a, x);

			val[id] = val[left(id)] + val[right(id)];
		}
	}

	int bsearch(int id, int l, int r, int x)
	{
		if (l == r)
			return l;
		else
		{
			int mid = (l + r) / 2;
			if (x <= val[left(id)])
				return bsearch(left(id), l, mid, x);
			else
				return bsearch(right(id), mid + 1, r, x - val[left(id)]);
		}
	}

	void update(int a, int x)
	{
		update(1, 0, n - 1, a, x);
	}

	int kth(int k)
	{
		return bsearch(1, 0, n-1, k);
	}
};


int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		v.push_back({-a[i], i});
	}
	sort(all(v));

	int nq;
	cin >> nq;
	map<int, vector<pii>> q;
	vector<int> ans(nq);
	for (int i = 0; i < nq; i++)
	{
		int x, y;
		cin >> x >> y;
		q[x].push_back({y, i});
	}

	// debug(v);
	segtree seg(n);
	for (int i = 1; i <= n; i++)
	{
		// debug(v[i-1].second);
		seg.update(v[i-1].second, 1);
		for (pii kvp : q[i])
		{
			ans[kvp.second] = seg.kth(kvp.first);
		}
	}

	// debug(ans);
	for (int i = 0; i < nq; i++)
		cout << a[ans[i]] << endl;
}