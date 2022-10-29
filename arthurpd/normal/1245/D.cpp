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

struct edge{
	int a, b;
	ll w;
	bool operator < (edge rhs) const{
		return w < rhs.w;
	}
};

struct union_find
{
	vector<int> p, size;
	union_find(int n) : p(n), size(n, 1)
	{
		iota(p.begin(), p.end(), 0);
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
		size[a] += size[b];
	}
};


int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> x(n), y(n), c(n), k(n);
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < n; i++)
		cin >> k[i];

	vector<edge> e;
	for (int i = 0; i < n; i++)
		e.push_back({i, n, c[i]});
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			e.push_back({i, j, (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]))});

	sort(e.begin(), e.end());
	union_find uf(n + 1);
	ll ans = 0;
	vector<int> ps;
	vector<pii> tree;
	for (int i = 0; i < sz(e); i++)
		if (uf.find(e[i].a) != uf.find(e[i].b))
		{
			ans += e[i].w;
			uf.join(e[i].a, e[i].b);
			if (e[i].b == n)
				ps.push_back(e[i].a);
			else
			{
				tree.push_back({e[i].a, e[i].b});
			}			
		}

	cout << ans << endl;
	cout << sz(ps) << endl;
	for (int i = 0; i < sz(ps); i++)
		cout << ps[i] + 1 << " ";
	cout << endl;
	cout << sz(tree) << endl;
	for (int i = 0; i < sz(tree); i++)
		cout << tree[i].first + 1 << " " << tree[i].second + 1 << endl;
}