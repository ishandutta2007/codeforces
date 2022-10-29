// https://codeforces.com/contest/1236/problem/F

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

// int main()
// {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// }

/*
	Extended Euclidean Algorithm:
		Returns the gcd of a and b.
		Also finds numbers x and y for which a * x + b * y = gcd(a, b) (not unique).
		All pairs can be represented in the form (x + k * b / gcd, y - k * a / gcd) for k an arbitrary integer.
		If there are several such x and y, the function returns the pair for which |x| + |y| is minimal.
		If there are several x and y satisfying the minimal criteria, it outputs the pair for which X <= Y.

	Source: modified from https://cp-algorithms.com/algebra/extended-euclid-algorithm.html

	Usage:
		For non-extendend version, c++ has __gcd and __lcm.

	Constraints:
		Produces correct results for negative integers as well.
*/

template<class T>
T gcd(T a, T b, T &x, T &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}

	T x1, y1;
	T d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

/*
	Modular Inverse:
		Returns an integer x such that (a * x) % m == 1.
		The modular inverse exists if and only if a and m are relatively prime.
		Modular inverse is also equal to a^(phi(m) - 1) % m.
		In particular, if m is prime a^(-1) == a^(m-2), which might be faster to code.

	Source: modified from https://cp-algorithms.com/algebra/module-inverse.html
*/

template<class T>
T mod_inverse(T a, T m)
{
	T x, y;
	assert(gcd(a, m, x, y) == 1); // Or return something, if gcd is not 1 the inverse doesn't exist.
	return (x % m + m) % m;
}

/*
	Modular Arithmetic:
		Struct wrapper on to of modular arithmetics.

	Source: modified from https://github.com/kth-competitive-programming/kactl/blob/master/content/number-theory/ModularArithmetic.h
*/

template <ll mod>
struct mod_num
{
	ll x;
	explicit mod_num(ll x = 0) : x(x % mod) {}
	mod_num operator+(mod_num b) { return mod_num(x + b.x); }
	mod_num operator-(mod_num b) { return mod_num(x - b.x + mod); }
	mod_num operator*(mod_num b) { return mod_num(x * b.x); }
	mod_num operator/(mod_num b) { return mod_num(x * mod_inverse(b.x, mod)); }
	mod_num operator^(ll e)
	{
		mod_num ans(1);
		mod_num b = *this;
		for (; e; b = b * b, e /= 2)
			if (e & 1)
				ans = ans * b;
		return ans;
	}

	void operator+=(mod_num b) { x = (x + b.x) % mod; }
};

template <ll mod>
ostream &operator<<(ostream &os, mod_num<mod> x)
{
	return os << x.x;
}

#define MAXN 512345
#define mod_num mod_num<1000000007>

vector<int> graph[MAXN];
int been[MAXN];
vector<int> st;

vector<vector<int>> rings;
vector<pii> edges;

mod_num vertex_rings_factor[MAXN];

void dfs(int a, int p)
{
	been[a] = 1;
	st.push_back(a);
	for (int i = 0; i < sz(graph[a]); i++)
	{
		if (graph[a][i] != p)
		{
			if (been[graph[a][i]] == 0)
				dfs(graph[a][i], a);
			else if (been[graph[a][i]] == 1)
			{
				vector<int> tmp;
				for (int j = sz(st) - 1; st[j] != graph[a][i]; j--)
					tmp.push_back(st[j]);
				tmp.push_back(graph[a][i]);

				rings.push_back(tmp);
			}
		}
	}

	st.pop_back();
	been[a] = 2;
}

bool intersect(const vector<int> &v1, const vector<int> &v2)
{
	for (int i = 0; i < sz(v1); i++)
		if (find(v2.begin(), v2.end(), v1[i]) != v2.end())
			return true;
	return false;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		edges.push_back({min(a, b), max(a, b)});
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, 1);

	vector<mod_num> pot2div(max(11, n + 1));
	pot2div[0] = mod_num(1);
	pot2div[1] = pot2div[0] / mod_num(2);

	for (int i = 2; i < sz(pot2div); i++)
		pot2div[i] = pot2div[i-1] * pot2div[1];

	mod_num sum_rings_factors(0);

	for (int i = 0; i < sz(rings); i++)
	{
		sum_rings_factors += pot2div[sz(rings[i])];
		for (int x : rings[i])
		{
			vertex_rings_factor[x] += pot2div[sz(rings[i])];
		}
	}

	vector<mod_num> intersecting_rings_factors(sz(rings));
	for (int i = 0; i < sz(rings); i++)
		for (int x : rings[i])
			intersecting_rings_factors[i] += vertex_rings_factor[x] - pot2div[sz(rings[i])];

	mod_num ex = (mod_num(2)^0) * mod_num(n) / mod_num(2) - mod_num(m) / mod_num(4);
	for (int i = 0; i < sz(rings); i++)
		ex += pot2div[sz(rings[i])];

	mod_num ex2(0);

	mod_num ev2 = mod_num(n) * mod_num(n - 1) / (mod_num(2)^2) + mod_num(n) / (mod_num(2)^1);

	mod_num ee2(0);
	for (int i = 0; i < m; i++)
	{
		ee2 += pot2div[2];
		ee2 += mod_num(sz(graph[edges[i].first]) + sz(graph[edges[i].second]) - 2) * pot2div[3];
		ee2 += mod_num(m - (sz(graph[edges[i].first]) + sz(graph[edges[i].second]) - 1)) * pot2div[4];
	}

	mod_num er2(0);
	for (int i = 0; i < sz(rings); i++)
	{
		er2 += pot2div[sz(rings[i])];
		er2 += pot2div[sz(rings[i]) - 1] * intersecting_rings_factors[i];
		er2 += pot2div[sz(rings[i])] * (sum_rings_factors - intersecting_rings_factors[i] - pot2div[sz(rings[i])]);
	}

	mod_num eve;
	for (int i = 1; i <= n; i++)
	{
		eve += mod_num(sz(graph[i])) * pot2div[2];
		eve += mod_num(m - sz(graph[i])) * pot2div[3];
	}

	mod_num eer;
	for (int j = 0; j < sz(rings); j++)
	{
		int k = sz(rings[j]);

		eer += mod_num(sz(rings[j])) * pot2div[sz(rings[j])];
		for (int x : rings[j])
		{
			eer += mod_num(sz(graph[x]) - 2) * pot2div[sz(rings[j]) + 1];
			k += sz(graph[x]) - 2;
		}

		eer += mod_num(m - k) * pot2div[sz(rings[j]) + 2];
	}

	mod_num evr;
	for (int i = 1; i <= n; i++)
	{
		evr += vertex_rings_factor[i];
		evr += (sum_rings_factors - vertex_rings_factor[i]) * pot2div[1];
	}

	ex2 = ev2 + ee2 + er2 - mod_num(2) * eve - mod_num(2) * eer + mod_num(2) * evr;

	cout << (mod_num(2)^(1000000007)) * (ex2 - ex * ex) * (mod_num(2)^(1000000005)) << endl;
}