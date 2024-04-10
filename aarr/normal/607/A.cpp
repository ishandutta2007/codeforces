#include <iostream>

#include <algorithm>

using namespace std;

int n;
pair<int, int> a[100005];
int dp[100005];
int bns(int x)
{
	int dw = -1, up = n - 1;
	while(up - dw > 1)
	{
		int md = (dw + up) / 2;
		if(a[md].first >= x)
		{
			up = md;
		}
		else
		{
			dw = md;
		}
	}
	return up;
}
int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i].first;
		cin >> a[i].second;
	}
	sort(a, a + n);
	dp[0] = 1;
	for(int i = 1; i < n; i ++)
	{
		dp[i] = max(dp[bns(max(a[0].first, a[i].first - a[i].second)) - 1], 0) + 1;
	}
	int x = 0;
	for(int i = 0; i < n; i ++)
	{
		x = max(x, dp[i]);
	}
	cout << n - x;
	return 0;
}