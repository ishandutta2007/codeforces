#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 4e3 + 20;

int sum[maxn][maxn] , dp[maxn] , pd[maxn];

void solve(int l , int r , int s , int e)
{
	if(e < s)
		return;

	int m = (s + e) / 2;
	pair<int , int> upd;
	for(int i = l; i <= r && i < m; i++)
	{
		int tmp = pd[i] + sum[m][m] - sum[i][m] - sum[m][i] + sum[i][i];
		if(i == l)
			upd = make_pair(tmp , -i);
		else
			upd = min(upd , make_pair(tmp , -i));
	}

	dp[m] = upd.first;
	solve(l , -upd.second , s , m - 1);
	solve(-upd.second , r , m + 1 , e);
}

int main()
{
	int n , k;
	cin >> n >> k;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			getchar();
			sum[i][j] = getchar() - '0';
			sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
		}

	memset(pd , 63 , sizeof pd);
	pd[0] = 0;
	for(int i = 1; i <= k; i++)
	{
		solve(0 , n , 1 , n);
		memcpy(pd , dp , sizeof dp);
	}

	cout << pd[n] / 2 << endl;
}