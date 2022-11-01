#include <iostream>

#include <vector>

using namespace std;

vector <int> a[1005];
int dp[1005];
int main()
{
	int n, s;
	cin >> n;
	cin >> s;
	for(int i = 0; i < n; i ++)
	{
		int f, t;
		cin >> f;
		cin >> t;
		a[f].push_back(t);
	}
	dp[s + 1] = -1;
	for(int i = s; i >= 0; i --)
	{
		dp[i] = dp[i + 1] + 1;
		for(int j = 0; j < a[i].size(); j ++)
		{
			dp[i] = max(dp[i], a[i][j]);
		}
	}
	cout << dp[0];
	return 0;
}