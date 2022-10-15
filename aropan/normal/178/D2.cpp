#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 4;
const int MAXM = MAXN * MAXN;
const int MAXT = 1 << MAXM;
const int INF = (int)1e+9;

int n, m;
int a[MAXM];
int p[MAXM];
vector < pair <int, int> > v;
int upd[MAXT], cnt;
int row[MAXN], col[MAXN], d1, d2, mask;
int I[MAXM], J[MAXM];
int ans[MAXN][MAXN];
int s;

void rec(int k)
{
	if (k == m)
	{
		printf("%d\n", s);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j) printf(" ");
				printf("%d", ans[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	int
		x = I[k],
		y = J[k];
	ans[x][y] = -INF;
	for (int i = 0; i < m; i++)
		if ((mask & (1 << i)) == 0 && ans[x][y] != a[i])
		{
			if (
				upd[row[x] | (1 << i)] != cnt ||
				upd[col[y] | (1 << i)] != cnt ||
				x == y && upd[d1 | (1 << i)] != cnt ||
				x == n - y - 1 && upd[d2 | (1 << i)] != cnt
			) continue;

			ans[x][y] = a[i];
			row[x] ^= 1 << i;
			col[y] ^= 1 << i;
			if (x == y) d1 ^= 1 << i;
			if (x == n - y - 1) d2 ^= 1 << i;
			mask ^= 1 << i;

			rec(k + 1);

			row[x] ^= 1 << i;
			col[y] ^= 1 << i;
			if (x == y) d1 ^= 1 << i;
			if (x == n - y - 1) d2 ^= 1 << i;
			mask ^= 1 << i;
		}
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d", &n);
    m = n * n;
    for (int i = 0; i < m; i++)
    	scanf("%d", &a[i]);

    if (n == 1)
    {
    	printf("%d\n%d\n", a[0], a[0]);
    	return 0;
    }

    sort(a, a + m);
    for (int i = 0; i < n; i++)
    	p[i] = 1;
    sort(p, p + m);

    do
    {
    	int sum = 0;
    	int mask = 0;
    	for (int i = 0; i < m; i++)
    		if (p[i])
    		{
    			sum += a[i];
    			mask |= 1 << i;
    		}
    	v.push_back(make_pair(sum, mask));
    } while (next_permutation(p, p + m));


    for (int i = 0; i < m; i++)
    {
    	I[i] = i / n;
    	J[i] = i % n;
    }


    sort(v.begin(), v.end());
    for (int i = 0, j = 0; i < (int)v.size(); i = j)
    {
    	cnt++;
    	while (j < (int)v.size() && v[i].first == v[j].first)
    	{
    		int mask = v[j].second;
    		int m = mask;
    		while (m)
    		{
    			upd[m] = cnt;
    			m = (m - 1) & mask;
    		}
    		j++;
    	}
    	if (j - i < n + n + 2) continue;
    	s = v[i].first;
    	rec(0);
    }



    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}