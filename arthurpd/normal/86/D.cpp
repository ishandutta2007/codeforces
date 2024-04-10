// https://codeforces.com/contest/86/problem/D

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
	Mo's Algorithm:
		Solve Q interval queries on a sequence of N values offline
		in O(N * sqrt(Q) * max(insertion time, removal time)).
	
	Usage:
		Queries are defined by closed intervals [l, r] (1 <= l <= r <= n).
		add(i) must add i-th element to your data structure (1 <= i <= n).
		remove(i) must remove the i-th element (1 <= i <= n).
		output(id) should answer query with given id using current state.

	Author: Arthur Pratti Dadalto
*/

struct query {
	int l, r, id;
};

template<class F>
void mos(int n, vector<query> q, const F &add, const F &remove, const F &output)
{
	int bsize = 1 + n / sqrt(sz(q));
	sort(q.begin(), q.end(), [&](const query &lhs, const query &rhs) {
		if (lhs.l / bsize != rhs.l / bsize)
			return  (lhs.l / bsize < rhs.l / bsize);
		return lhs.r < rhs.r;
	});

	int l = 1, r = 0;
	for (int i = 0; i < sz(q); i++)
	{
		while (l > q[i].l)
			add(--l);
		while (r < q[i].r)
			add(++r);
		while (l < q[i].l)
			remove(l++);
		while (r > q[i].r)
			remove(r--);

		output(q[i].id);
	}
}

#define MAXN 212345

int a[MAXN];
ll ans[MAXN];
ll val = 0;
int freq[1123456];

ll calc(int x)
{
	return freq[x] * 1ll * freq[x] * 1ll * x;
}

void add(int i)
{
	val += (long long)(2 * freq[a[i]] + 1) * a[i];
	freq[a[i]]++;
}

void remove(int i)
{
	val -= (long long)(2 * freq[a[i]] - 1) * a[i];
	freq[a[i]]--;
}

void output(int i)
{
	ans[i] = val;
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<query> q(m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].id = i;
	}

	mos(n, q, add, remove, output);
	for (int i = 0; i < m; i++)
		printf("%lld\n", ans[i]);
}