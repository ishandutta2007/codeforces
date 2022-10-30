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

struct union_find
{
	vector<int> p, size, mx;
	union_find(int n) : p(n), size(n, 1), mx(n)
	{
		iota(p.begin(), p.end(), 0);
		iota(mx.begin(), mx.end(), 0);
	}

	int find(int a)
	{
		return (p[a] == a) ? a : (p[a] = find(p[a]));
	}

	void join(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)
			return;
		if (size[a] < size[b])
			swap(a, b);
		p[b] = a;
		mx[a] = max(mx[a], mx[b]);
		size[a] += size[b];
	}
};


int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b;
	cin >> n >> m;
	union_find uf(n+1);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		uf.join(a, b);
	}

	int cur = 1;
	int cnt = 0, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (uf.find(i) != uf.find(cur))
		{
			uf.join(i, cur);
			ans++;
		}

		cnt++;
		if (cnt == uf.size[uf.find(cur)])
		{
			cur = i + 1;
			cnt = 0;
		}
	}

	cout << ans << endl;
}