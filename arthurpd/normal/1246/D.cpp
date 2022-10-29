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

#define MAXN 112345

int n;
vector<int> p;
vector<int> graph[MAXN];
int sz[MAXN];
int mx[MAXN];

int id = 0;
int num[MAXN];
vector<int> ops;

int dfs(int a)
{
	if (sz(graph[a]) == 0)
		sz[a] = 1;
	else
		sz[a] = inf;
	
	for (int i = 0; i < graph[a].size(); i++)
		sz[a] = max(sz[a], dfs(graph[a][i]) + 1);
	return sz[a];
}

int dfs2(int a)
{
	num[a] = id++;
	vector<pii> v;
	for (int i = 0; i < graph[a].size(); i++)
		v.push_back({sz[graph[a][i]], graph[a][i]});

	sort(v.begin(), v.end());
	// debug(a, v);
	int hprev = 0;
	for (int i = 0; i < v.size(); i++)
	{	
		int x = dfs2(v[i].second);

		for (int j = 0; j < hprev; j++)
			ops.push_back(v[i].second);
	
		hprev = x;
	}

	return hprev + 1;
}

int main()
{
	// srand(atol(argv[1]));
	cin.sync_with_stdio(0);
	cin.tie(0);
	// n = 7;
	cin >> n;

	p.assign(n, 0);
	int a;
	for (int i = 1; i < n; i++)
	{
		// a = rand() % i;
		cin >> a;
		p[i] = a;
		graph[a].push_back(i);
	}
	// debug(p);

	dfs(0);
	dfs2(0);
	// for (int i = 0; i < n; i++)
	// 	debug(i, sz[i]);
	vector<int> ord(n);
	for (int i = 0; i < n; i++)
		ord[num[i]] = i;
	for (int i = 0; i < n; i++)
		cout << ord[i] << " ";

	vector<int> np(n);
	for (int i = 1; i < n; i++)
		np[ord[i]] = ord[i-1];

	cout << endl;
	cout << sz(ops) << endl;
	for (int i = 0; i < sz(ops); i++)
		cout << ops[i] << " ";
	cout << endl;

	for (int i = 0; i < sz(ops); i++)
	{
		assert(np[ops[i]] != 0);
		np[ops[i]] = np[np[ops[i]]];
	}
	for (int i = 0; i < n; i++)
		assert(p[i] == np[i]);

}