// https://codeforces.com/problemset/problem/869/E
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

/*
	BIT: element update, range sum query in O(log(n) * log(m)). This can also be generalized for 3d.
*/

template <class T>
struct bit2d
{
	int n, m;
	vector<vector<T>> val;
	bit2d(int _n, int _m) : n(_n), m(_m), val(_n + 1, vector<T>(_m + 1, 0)) {}

	// val[i][j] += x
	void update(int r, int c, T x)
	{
		for (int i = r; i <= n; i += -i & i)
			for (int j = c; j <= m; j += -j & j)
				val[i][j] += x;
	}

	// sum of positions (1 ... r, 1 ... c)
	T query(int r, int c)
	{
		T retv = 0;
		for (int i = r; i > 0; i -= -i & i)
			for (int j = c; j > 0; j -= -j & j)
				retv += val[i][j];
		return retv;
	}

	// sum of positions (ri ... rf, ci ... cf). (1 <= ri <= rf <= n) and (1 <= ci <= cf <= m)
	T query_rect(int ri, int ci, int rf, int cf)
	{
		return query(rf, cf) - query(rf, ci - 1) - query(ri - 1, cf) + query(ri - 1, ci - 1);
	}
};

#define NHASH 3
#define MAXN 3123
int tab[MAXN][MAXN][NHASH];

int main(void)
{
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	srand(42);

	vector<bit2d<long long>> bit;
	for (int i = 0; i < NHASH; i++)
		bit.emplace_back(n, m);

	for (int i = 0; i < q; i++)
	{
		int tp, r1, r2, c1, c2;
		scanf("%d %d %d %d %d", &tp, &r1, &c1, &r2, &c2);
		if (tp == 1)
		{
			for (int j = 0; j < NHASH; j++)
			{
				assert(bit[j].query_rect(r1, c1, r2 + 1, c2 + 1) == 0);
				tab[r1][c1][j] = rand();
				bit[j].update(r1, c1, tab[r1][c1][j]);
				bit[j].update(r1, c2 + 1, -tab[r1][c1][j]);
				bit[j].update(r2 + 1, c1, -tab[r1][c1][j]);
				bit[j].update(r2 + 1, c2 + 1, tab[r1][c1][j]);
				assert(bit[j].query_rect(r1, c1, r2 + 1, c2 + 1) == 0);
			}
		}
		else if (tp == 2)
		{
			for (int j = 0; j < NHASH; j++)
			{
				assert(bit[j].query_rect(r1, c1, r2 + 1, c2 + 1) == 0);
				bit[j].update(r1, c1, -tab[r1][c1][j]);
				bit[j].update(r1, c2 + 1, tab[r1][c1][j]);
				bit[j].update(r2 + 1, c1, tab[r1][c1][j]);
				bit[j].update(r2 + 1, c2 + 1, -tab[r1][c1][j]);				
				assert(bit[j].query_rect(r1, c1, r2 + 1, c2 + 1) == 0);
			}
		}
		else
		{
			bool ok = true;
			for (int j = 0; j < NHASH; j++)
				ok = ok && (bit[j].query(r1, c1) == bit[j].query(r2, c2));

			printf("%s\n", ok ? "Yes" : "No");
		}		
	}
}