#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;
const int LG = 40;

int n, k;
int a[N];
int par[LG][N], mn[LG][N], sum[LG][N];

void precompute()
{
	for(int i = 1; i < LG; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			par[i][j] = par[i - 1][par[i - 1][j]];
			mn[i][j] = min(mn[i - 1][j], mn[i - 1][par[i - 1][j]]);
			sum[i][j] = sum[i - 1][j] + sum[i - 1][par[i - 1][j]];
		}
	}
}

void work(int u, int k)
{
	int sum1 = 0, mn1 = 1e9;
	for(int i = LG - 1; i >= 0; i--)
	{
		if(k >> i & 1)
		{
			sum1 += sum[i][u];
			mn1 = min(mn1, mn[i][u]);
			u = par[i][u];
		}
	}
	cout << sum1 << " " << mn1 << endl;
}

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i]++;
		par[0][i] = a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		int w;
		cin >> w;
		mn[0][i] = sum[0][i] = w;
	}
	precompute();
	for(int i = 1; i <= n; i++)
		work(i, k);
	return 0;
}