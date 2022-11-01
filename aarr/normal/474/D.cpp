#include <iostream>

using namespace std;

const int N = 1000 * 1000 * 1000 + 7;
long long dp[100005];
long long ps[100005];
long long ans[100005];
int main()
{
	int t, k;
	cin >> t;
	cin >> k;
	dp[0] = 1;
	for(int i = 1; i <= 100005; i ++)
	{
		dp[i] = 0;
		dp[i] += dp[i - 1];	
		if(i >= k)
		{
			dp[i] += dp[i - k];
		}
		dp[i] = dp[i] % N;
	}
	ps[0] = 1;
	for(int i = 1; i <= 100005; i ++)
	{
		ps[i] = ps[i - 1] + dp[i];
		ps[i] = ps[i] % N;
	}
	for(int i = 0; i < t; i ++)
	{
		int l, r;
		cin >> l;
		cin >> r;
		ans[i] = ps[r] - ps[l - 1];
		if(ans[i] < 0)
		{
			ans[i] += N;
		}
	}
	for(int i = 0; i < t; i ++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}