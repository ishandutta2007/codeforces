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

template<class T>
T mod_inverse(T a, T m)
{
	T x, y;
	assert(gcd(a, m, x, y) == 1); // Or return something, if gcd is 
								// not 1 the inverse doesn't exist.
	return (x % m + m) % m;
}


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

#define modnum mod_num<998244353>

#define MAX_RANGE 212345

modnum val[4 * MAX_RANGE];
modnum delta[4 * MAX_RANGE];

#define left(i) ((i) << 1)
#define right(i) (((i) << 1) + 1)

void prop(int id, int l, int r)
{
	if (l != r)
	{
		// Updates need to be numerically stackable (e.g. not valid
		// to have a list of updates).
		delta[left(id)] += delta[id];
		delta[right(id)] += delta[id];
	}

	val[id] += modnum(r - l + 1) * delta[id]; // Node value needs to be obtainable without
											  // propagating all the way to root.
	delta[id] = modnum(0);
}

// Sum x in all elements in range [a, b].
void update(int id, int l, int r, int a, int b, modnum x)
{
	if (a == l && b == r)
	{
		delta[id] = delta[id] + x;
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

		val[id] = val[left(id)] + val[right(id)];
	}
}

// Get the minimum value in range [a, b].
modnum get(int id, int l, int r, int a, int b)
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
			return get(left(id), l, mid, a, mid) + get(right(id), mid + 1, r, mid + 1, b);
	}
}

#define MAXN 212345
#define HEAVY_TH 52

modnum pending[MAXN];
vector<int> graph[MAXN];
vector<int> sub_size[MAXN];
int heavy_par[MAXN];
int heavy_edge_id[MAXN];
bool heavy[MAXN];
int dfs_id = 0;
int num[MAXN];
int last_num[MAXN];
int pidx[MAXN];

int dfs(int a, int p, int sz)
{
	num[a] = ++dfs_id;

	int sum = 0;
	pidx[a] = -1;
	for (int i = 0; i < sz(graph[a]); i++)
		if (graph[a][i] != p)
		{
			heavy_edge_id[graph[a][i]] = (heavy[a] ? i : heavy_edge_id[a]);
			heavy_par[graph[a][i]] = (heavy[a] ? a : heavy_par[a]);

			int x = dfs(graph[a][i], a, sz);

			sub_size[a][i] = x;
			sum += x;
		}
		else
			pidx[a] = i;

	if (pidx[a] != -1)
		sub_size[a][pidx[a]] = sz - sum - 1;

	last_num[a] = dfs_id;

	return sum + 1;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n, q, a, b;
	cin >> n >> q;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		sub_size[a].push_back(0);
		graph[b].push_back(a);
		sub_size[b].push_back(0);
	}

	for (int i = 1; i <= n; i++)
		heavy[i] = sz(graph[i]) >= HEAVY_TH;
	heavy[1] = true;

	heavy_edge_id[1] = -inf;
	heavy_par[1] = 1;

	dfs(1, 1, n);
	int v, d;
	modnum tot(0);
	for (int i = 0; i < q; i++)
	{
		int tp;
		cin >> tp;
		if (tp == 1)
		{
			cin >> v >> d;
			modnum rdm(0);
			if (pidx[v] != -1)
				rdm = modnum(n - sub_size[v][pidx[v]]) * modnum(d) / modnum(n);

			tot += rdm;

			if (heavy[v])
			{
				pending[v] += modnum(d);
			}
			else
			{
				for (int i = 0; i < sz(graph[v]); i++)
					if (i != pidx[v])
					{
						update(1, 1, n, num[graph[v][i]], last_num[graph[v][i]], modnum(n - sub_size[v][i]) * modnum(d) / modnum(n) - rdm);
					}
			}			

			update(1, 1, n, num[v], num[v], modnum(d) - rdm);
		}
		else
		{
			cin >> v;
			modnum ans = (tot + get(1, 1, n, num[v], num[v]));
			while (v != 1)
			{
				int k = heavy_edge_id[v];
				v = heavy_par[v];

				modnum rdm(0);
				if (pidx[v] != -1)
					rdm = modnum(n - sub_size[v][pidx[v]]) * modnum(pending[v]) / modnum(n);

				ans += modnum(n - sub_size[v][k]) * modnum(pending[v]) / modnum(n) - rdm;
			}

			cout << ans << endl;
		}
	}
}