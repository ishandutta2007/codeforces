#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1005;

int n, m;
char a[N][N];
int r[N][N], d[N][N];
int floorlog[N];
int RMQ[N][11][N];

void precompute()
{
	for(int i=0;(1<<i)<N;i++)
	{
		for(int j=(1<<i);j<N && j<(1<<(i+1)); j++)
			floorlog[j]=i;
	}
	for(int k = 1; k <= m; k++)
	{
		for(int i = n; i >= 1; i--)
		{
			RMQ[k][0][i] = r[i][k]; 
			int mxj = floorlog[n - i + 1]; //2^j <= n-i+1
			int pw = 1;
			for(int j = 1;j <= mxj; j++)
			{
				RMQ[k][j][i] = min(RMQ[k][j-1][i], RMQ[k][j-1][i+pw]);
				pw <<= 1;
			}
		}	
	}
}

int getMin(int idx, int L, int R)
{
	int k = floorlog[R-L+1]; //2^k <= R-L+1
	return min(RMQ[idx][k][L], RMQ[idx][k][R - (1<<k) +1]);
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
	{
		for(int j = m; j >= 1; j--)
		{
			r[i][j] = 1;
			if(j + 1 <= m && a[i][j] == a[i][j + 1])
				r[i][j] = r[i][j + 1] + 1;
		}
	}
	for(int j = 1; j <= m; j++)
	{
		for(int i = n; i >= 1; i--)
		{
			d[i][j] = 1;
			if(i + 1 <= n && a[i][j] == a[i + 1][j])
				d[i][j] = d[i + 1][j] + 1;
		}
	}
	precompute();
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			int cur = r[i][j];
			int x = d[i][j];
			if(i + x <= n)
			{
				int cx = d[i + x][j];
				if(cx == x && i + x + cx <= n)
				{
					int nx = d[i + x + cx][j];
					if(nx >= x)
					{	
						cur = getMin(j, i, i + 3 * x - 1);
						ans += cur;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}