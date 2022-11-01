#include <bits/stdc++.h>

using namespace std;

int dp[200001][3][3], p[200001][3][3];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	if(n == 1) return cout << 'a', 0;
	for(int c1 = 0; c1 < 3; c1++)
		for(int c2 = 0; c2 < 3; c2++)
			dp[2][c1][c2] = (c1 == 2) + (c2 == 2);
	for(int i = 3; i <= n; i++)
		for(int c3 = 0; c3 < 3; c3++)
			for(int c2 = 0; c2 < 3; c2++)
			{
				dp[i][c2][c3] = n;
				for(int c1 = 0; c1 < 3; c1++)
				{
					if(c1 == c3) continue;
					if(dp[i - 1][c1][c2] + (c3 == 2) > dp[i][c2][c3]) continue;
					dp[i][c2][c3] = dp[i - 1][c1][c2] + (c3 == 2);
					p[i][c2][c3] = c1;
				}
			}
	vector<int> ans;
	int oc1, oc2, o = n;
	for(int c1 = 0; c1 < 3; c1++)
		for(int c2 = 0; c2 < 3; c2++)
			if(dp[n][c1][c2] < o)
			{
				o = dp[n][c1][c2];
				oc1 = c1;
				oc2 = c2;
			}
	ans.push_back(oc2);
	ans.push_back(oc1);
	for(int i = n - 2; i > 0; i--)
	{
		int c = p[i + 2][oc1][oc2];
		ans.push_back(c);
		oc2 = oc1;
		oc1 = c;
	}
	for(int i = n - 1; i >= 0; i--) cout << char('a' + ans[i]);
}