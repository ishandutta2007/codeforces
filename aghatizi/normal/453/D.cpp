#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 30;
const int maxm = (1 << 20) + 20;
int mod;

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

struct matrix
{
	int val[maxn][maxn];
	int n;
	matrix(int nn, int x = 0)
	{
		n = nn;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				if (i != j)
					val[i][j] = 0;
				else
					val[i][j] = x;
	}
	int* operator[] (int x)
	{
		return val[x];
	}
	matrix operator * (matrix b)
	{
		matrix ans(n, 0);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				for(int k=0; k<n; k++)
					mkay(ans[i][k] += 1LL * val[i][j] * b[j][k] % mod);
		return ans;
	}
	matrix operator + (matrix b)
	{
		matrix ans(n , 0);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				ans[i][j] = (val[i][j] + b[i][j]);
		return ans;
	}
};

matrix operator ^ (matrix a, ll b)
{
	matrix ans(a.n, 1);
	while(b)
	{
		if (b & 1)
			ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

int b[maxn] , c[maxn][maxn] , sum[maxm][maxn];

int main()
{
	int m;
	ll t;
	scanf("%d%I64d%d", &m, &t, &mod);

	int n = (1 << m);
	for(int i = 0; i < n; i++)
		scanf("%d", &sum[i][0]) , sum[i][0] %= mod;

	for(int i = 0; i <= m; i++)
		scanf("%d", &b[i]) , b[i] %= mod;

	for(int i = 0; i <= m; i++)
		for(int j = 0; j <= i; j++)
		{
			if(!j || i == j)
				c[i][j] = 1;
			else
				mkay(c[i][j] = c[i - 1][j] + c[i - 1][j - 1]);
		}

	matrix adj(m + 1);
	for(int j = 0; j <= m; j++)
		for(int x = 0; x <= j; x++)
			for(int i = x; i + j - x <= m; i++)
				mkay(adj[i][j] += (1LL * b[i + j - 2 * x] * c[j][x] % mod) * (1LL * c[m - j][i - x] % mod) % mod);
	adj = adj ^ t;

	for(int bit = 0; bit < m; bit++)
		for(int j = bit + 1; j >= 1; j--)
			for(int i = 0; i < n; i++)
				mkay(sum[i][j] += sum[i ^ (1 << bit)][j - 1]);

	for(int i = 0; i < n; i++)
	{
		int res = 0;
		for(int j = 0; j <= m; j++)
			mkay(res += 1LL * sum[i][j] * adj[0][j] % mod);

		printf("%d\n", res);
	}
}