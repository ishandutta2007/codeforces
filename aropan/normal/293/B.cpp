#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 22;
const int MAXK = 12;

int a[MAXN][MAXN];
int cnt[MAXK], col[MAXK];
int r[MAXN][MAXN];
int f[MAXN][MAXN];
int cb[1 << MAXK];
int n, m, k, d;
int ans;

long long rec(int x, int y, int c)
{
	if (x < 1 || y > m)
	{
		if (x == n)
		{
			/*
			printf("%d %d\n", n, m);
			for (int i = 1; i <= n; i++, printf("\n"))
				for (int j = 1; j <= m; j++)
					printf("%d", r[i][j] + 1);
			printf("\n");
			//*/
			
			for (int i = 1; i <= k; i++)
				for (int j = i + 1; j <= k; j++)
					if (cnt[i] && cnt[j] && col[i] == col[j])
						return 0;
			
			c -= d;
			//cout << c << endl;
			long long res = 1;
			for (int i = k - d - c + 1; i <= k - d; i++)
				res *= i;
			return res;
		}
		
		x += 1;
		y = 1;
	}

	f[x][y] = f[x - 1][y] | f[x][y - 1];

	if (cb[f[x][y]] + n - x + 1 + m - y + 1 - 1 > k)
		return 0;
	
	long long res = 0;
	for (int i = 0; i <= c && i < k; i++)
		if ((f[x][y] & (1 << i)) == 0 && (a[x][y] == 0 || cnt[a[x][y]] == 0 || col[a[x][y]] == i))
		{
			f[x][y] ^= 1 << i;
			cnt[a[x][y]] += 1;
			col[a[x][y]] = i;
			r[x][y] = i;
			res += rec(x, y + 1, c + (i == c));
			f[x][y] ^= 1 << i;
			cnt[a[x][y]] -= 1;
		}
	return res;
}

int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	cb[0] = 0;
	for (int i = 1; i < (1 << MAXK); i++)
		cb[i] += cb[i >> 1] + (i & 1);
	
	scanf("%d %d %d", &n, &m, &k);
	if (n + m - 1 > k)
	{
		puts("0");
		return 0;
	}
		
	d = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] == 0)
				continue;
				
			d += cnt[a[i][j]] == 0;
			cnt[a[i][j]] += 1;
		}

	memset(cnt, 0, sizeof(cnt));
	memset(col, 0, sizeof(col));
	cout << rec(1, 1, 0) % 1000000007 << endl;
	
	fprintf(stderr, "Time execute: %.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}