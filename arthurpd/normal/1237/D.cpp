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
	bit(int _n) : n(_n), LOGN(log2(n + 1)), val(_n + 1, inf) {}

	// val[pos] += x
	void update(int pos, T x)
	{
		for (int i = pos; i <= n; i += -i & i)
			val[i] = min(val[i], x);
	}

	// sum of range [1, pos]
	T query(int pos)
	{
		T retv = inf;
		for (int i = pos; i > 0; i -= -i & i)
			retv = min(retv, val[i]);
		return retv;
	}
};


int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(3*n);
	map<int,int> rdm;
	map<int,int> stop;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i + n] = a[i];
		a[i + 2 * n] = a[i];
		rdm[a[i]] = 1;
	}
	rdm[0] = 1;

	int id = 0;
	for(auto &x : rdm)
		x.second = ++id;

	for (int i = 0; i < n; i++)
	{
		auto it = rdm.lower_bound((a[i] + 1) / 2);
		it--;
		stop[rdm[a[i]]] = it->second;
	}

	for (int i = 0; i < 3*n; i++)
		a[i] = rdm[a[i]];

	bit<int> bt(id + 2);

	vector<int> res(3*n);
	int ans = inf;
	for (int i = 3*n - 1; i >= 0; i--)
	{
		ans = min(ans, bt.query(stop[a[i]]));
		bt.update(a[i], i);

		res[i] = (ans == inf ? -1 : (ans - i));
	}


	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;

}