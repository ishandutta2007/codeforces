#include <iostream>

using namespace std;

long long a[200005];
long long ps[200005];
long long ks[200005];
long long mks[200005];
long long dp[200005];
int main()
{
	int n, k;
	cin >> n;
	cin >> k;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	ps[0] = a[0];
	for(int i = 1; i <= n; i ++)
	{
		ps[i] = a[i] + ps[i - 1];
	}
	for(int i = 1; i <= n - k + 1; i ++)
	{
		ks[i] = ps[i + k - 1] - ps[i - 1];
		mks[i] = max(mks[i - 1], ks[i]);
	}
	for(int i = k + 1; i <= n - k + 1; i ++)
	{
		dp[i] = mks[i - k] + ks[i];
	}
	int x = k + 1, y = 1;	
	for(int i = k + 1; i <= n - k + 1; i ++)
	{
		if(dp[i] > dp[x])
		{
			x = i;
		}
	}
	for(int i = 1; i <= x - k; i ++)
	{
		if(ks[i] > ks[y])
		{
			y = i;
		}
	}
	cout << y << " " << x;
	return 0;
}