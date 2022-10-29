// https://codeforces.com/contest/321/problem/E

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

/*
	Binary Search Optimization for DP:
		Transforms dp of the form (or similar) dp[i][j] = min_{k < i}(dp[k][j-1] + c[k + 1][i]).
		The classical case is a partitioning dp, where k determines the break point for the next partition.
		In this case, i is the number of elements to partition and j is the number of partitions allowed.
		
		Let opt[i][j] be the values of k which minimizes the function. (in case of tie, choose the smallest)
		To apply this optimization, you need opt[i][j] <= opt[i+1][j].
		That means the when you add an extra element (i + 1), your partitioning choice will not be to include more elements
		than before (e.g. will no go from choosing [k, i] to [k-1, i+1]).
		This is usually intuitive by the problem details.
		
		Time goes from O(n^2m) to O(nm log n).

		To apply try to write the dp in the format above and verify if the property holds.
*/


#define MAXN 4123
#define MAXM 812

int n, m;
int u[MAXN][MAXN];
// int c[MAXN][MAXN];
int tab[MAXN][MAXM];

inline int c(int i, int j)
{
	return (u[j][j] - u[j][i-1] - u[i-1][j] + u[i-1][i-1]) / 2;
}

// This is responsible for computing tab[l...r][j], knowing that opt[l...r][j] is in range [low_opt...high_opt]
void compute(int j, int l, int r, int low_opt, int high_opt)
{
	int mid = (l + r) / 2, opt = -1; // mid is equivalent to i in the original dp.

	tab[mid][j] = inf;
	for (int k = low_opt; k <= high_opt && k < mid; k++)
		if (tab[k][j-1] + c(k + 1,mid) < tab[mid][j])
		{
			tab[mid][j] = tab[k][j-1] + c(k + 1,mid);
			opt = k;
		}
	
	// New bounds on opt for other pending computation.
	if (l <= mid - 1)
		compute(j, l, mid - 1, low_opt, opt);
	if (mid + 1 <= r)
		compute(j, mid + 1, r, opt, high_opt);		
}


int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			getchar();
			u[i][j] = getchar() - '0';
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			u[i][j] += u[i-1][j] + u[i][j-1] - u[i-1][j-1];
	
	for (int i = 1; i <= n; i++)
		tab[i][0] = inf;

	// Original dp
	// for (int i = 1; i <= n; i++)
	// 	for (int j = 1; j <= m; j++)
	// 	{
	// 		tab[i][j] = inf;
	// 		for (int k = 0; k < i; k++)
	// 			tab[i][j] = min(tab[i][j], tab[k][j-1] + c(k + 1,i);
	// 	}
	
	for (int j = 1; j <= m; j++)
		compute(j, 1, n, 0, n-1);

	cout << tab[n][m] << endl;
}