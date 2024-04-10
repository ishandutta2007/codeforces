#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

vector < int > v1;
int dp[5050];



int main()
{
	int n,m;
	cin >> n >> m;

	int a;double b;
	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		v1.push_back(a-1);
	}

	dp[0] = 1;

	int ans = 1;

	for(int i=1;i<n;i++)
	{
		dp[i] = 1;
		for(int j=i-1;j>=0;j--)
		{
			if(v1[j]<=v1[i])
			{
				dp[i] = max(dp[i],dp[j]+1);
				ans = max(dp[i],ans);
			}
		}
	}

	cout << n-ans;

	return 0;
}