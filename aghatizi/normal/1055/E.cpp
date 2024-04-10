#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 15e2 + 20;

int l[maxn] , r[maxn] , a[maxn] , n , s , m , k;

int dp[maxn][maxn];

bool check(int x)
{
	memset(dp , 0 , sizeof dp);
	for(int i = 1; i <= n; i++)
	{
		int last = i + 1;
		for(int j = 0; j < s; j++)
			if(l[j] <= i && i <= r[j])
				last = min(last , l[j]);

		int sum = 0;

		for(int j = last; j <= i; j++)
			if(a[j] <= x)
				sum++;

		for(int j = 1; j <= m; j++)
			dp[i][j] = max(dp[i - 1][j] , dp[last - 1][j - 1] + sum);
	}

	return (dp[n][m] >= k);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s >> m >> k;

	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 0; i < s; i++)
		cin >> l[i] >> r[i];

	int l = 0 , r = 1e9 + 20;

	while(r - l > 1)
	{
		int mid = (l + r) / 2;

		if(check(mid))
			r = mid;
		else
			l = mid;
	}

	if(!check(r))
		r = -1;
	cout << r << endl;
}