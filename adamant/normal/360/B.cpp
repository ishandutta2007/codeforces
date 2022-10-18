#include <bits/stdc++.h>

using namespace std;

const int maxn = 3000, inf = 2e9 + 42;
int a[maxn];
int n, k;

bool check(int t)
{
	int dp[n + 2]; 
	fill(dp, dp + n + 2, inf);
	dp[0] = 0;
	for(int i = 1; i <= n + 1; i++)
	{
		a[0] = a[i];
		for(int j = 0; j < i; j++)
		{
			a[n + 1] = a[j];
			if(abs(a[i] - a[j]) <= 1LL * t * (i - j))
				dp[i] = min(dp[i], dp[j] + (i - j - 1));
		}
	}
	return dp[n + 1] <= k;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int l = -1, r = inf;
	while(r - l > 1)
	{
		int m = l + (r - l) / 2;
		if(check(m))
			r = m;
		else
			l = m;
	}
	cout << r << "\n";
}