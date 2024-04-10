#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1005;
const int MOD = 1e9 + 7;

int n, m;
int a[N][N], r[N], c[N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> r[i];
		for(int j = 1; j <= r[i]; j++)
			a[i][j] = 1;
	}
	for(int i = 1; i <= m; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= c[i]; j++)
			a[j][i] = 1;
	}
	int ans = n * m;
	for(int i = 1; i <= n; i++)
	{
		if(a[i][r[i] + 1])
		{
			cout << 0;
			return 0;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		if(a[c[i] + 1][i])
		{
			cout << 0;
			return 0;
		}
	}
	for(int i = 1; i <= n; i++)
		a[i][r[i] + 1] = 1;
	for(int i = 1; i <= m; i++)
		a[c[i] + 1][i] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ans -= a[i][j];
	int val = 1;
	for(int i = 1; i <= ans; i++)
	{
		val *= 2;
		val %= MOD;
	}
	cout << val;
	return 0;
}