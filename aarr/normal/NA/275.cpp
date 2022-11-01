#include <iostream>

#include <deque>

using namespace std;

const long long N = 1ll * 6000 * 1000 * 1000 * 1000;
long long dp[5005][5005];
int a[5005];
deque<int> dq;
int main()
{
	int n, k, x;
	cin >> n;
	cin >> k;
	cin >> x;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];	
	}
	for(int i = 1; i <= k; i ++)
	{
		dp[1][i] = a[i];
	}
	for(int i = k + 1; i <= n; i ++)
	{
		dp[1][i] = -N;
	}
	for(int i = 2; i <= x + 1; i ++)
	{
		for(int j = 1; j <= n + 1; j ++)
		{
			if(j == 1 && k == 1)
			{
				j = j;
			}
			if(dq.size())
			{
				dp[i][j] = dp[i - 1][dq.front()] + a[j];
			}
			while(dq.size() && dp[i - 1][dq.back()] < dp[i - 1][j])
			{
				dq.pop_back();
			}
			dq.push_back(j);
			if(dq.size() && dq.front() == j - k)
			{
				dq.pop_front();
			}
			//cout << dp[i][j] << " ";
		}
		while(dq.size())
		{
			dq.pop_back();
		}
		//cout << endl;
	}
	if(dp[x + 1][n + 1] <= 0)
	{
		dp[x + 1][n + 1] = -1;
	}
	cout << dp[x + 1][n + 1];
	return 0;
}