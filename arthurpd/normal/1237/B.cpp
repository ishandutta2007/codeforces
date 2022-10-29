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

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n;
	vector<int> pi(n+1);
	vector<int> a(n);
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		pi[x] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a[i] = pi[x];
	}

	bit<int> bt(n+1);

	reverse(a.begin(), a.end());
	// debug(a);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (bt.query(a[i]) != 0)
			ans++;
		bt.update(a[i], 1);
	}

	cout << ans << endl;
}