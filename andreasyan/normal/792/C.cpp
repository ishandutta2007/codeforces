#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
const int N = 100005;

int n, sum;
string a;
int dp[N][3];
bool c[N][3];

int main()
{
	cin >> a;
	n = a.size();
	for (int i = 0; i < n; ++i)
	{
		sum += (a[i] - '0');
	}
	dp[n][0] = 0;
	dp[n][1] = -1;
	dp[n][2] = -1;
	for (int i = n - 1; i >= 0; --i)
	{
		if (i == 0)
			cout << "";
		dp[i][0] = dp[i + 1][0];
		dp[i][1] = dp[i + 1][1];
		dp[i][2] = dp[i + 1][2];
		if (dp[i + 1][0] >= 0)
		{
			if (dp[i + 1][0] + 1 >= dp[i][(0 + a[i] - '0') % 3])
			{
				dp[i][(0 + a[i] - '0') % 3] = dp[i + 1][0] + 1;
				c[i][(0 + a[i] - '0') % 3] = true;
			}
		}
		if (dp[i + 1][1] >= 0)
		{
			if (dp[i + 1][1] + 1 >= dp[i][(1 + a[i] - '0') % 3])
			{
				dp[i][(1 + a[i] - '0') % 3] = dp[i + 1][1] + 1;
				c[i][(1 + a[i] - '0') % 3] = true;
			}
		}
		if (dp[i + 1][2] >= 0)
		{
			if (dp[i + 1][2] + 1 >= dp[i][(2 + a[i] - '0') % 3])
			{
				dp[i][(2 + a[i] - '0') % 3] = dp[i + 1][2] + 1;
				c[i][(2 + a[i] - '0') % 3] = true;
			}
		}
	}
	string ans;
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		if (c[i][m])
		{
			ans += a[i];
			m = (m + 3 + 3 + 3 + 3 - (a[i] - '0')) % 3;
		}
	}
	if (ans.empty())
	{
		cout << "-1" << endl;
		return 0;
	}
	string yans;
	m = 0;
	c[0][0] = true;
	for (int i = 0; i < n; ++i)
	{
		if (c[i][m])
		{
			if (c[i][m]==-1)
			{ 
				yans.clear();
				break;
			}
			yans += a[i];
			m = (m + 3 + 3 + 3 + 3 - (a[i] - '0')) % 3;
		}
	}
	while (ans.front() == '0')
	{
		ans.erase(ans.begin());
	}
	if (ans.empty())
		ans = "0";
	while (yans.front() == '0')
	{
		yans.erase(yans.begin());
	}
	if (yans.empty())
		yans = "0";
	if (ans.size() >= yans.size())
		cout << ans << endl;
	else
		cout << yans << endl;
	return 0;
}