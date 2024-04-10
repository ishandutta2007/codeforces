#include <bits/stdc++.h>
using namespace std;
int dp[200][3000], n;
pair<int, int> pre[200][3000];
pair<pair<int, int>, pair<int, int> > info[200];
pair<int, int > ans;
pair<int, int> a;
vector<int> pri;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &info[i].second.first, &info[i].first.first, &info[i].second.second);
		info[i].first.second = i+1;
	}
	sort(info, info+n);
	for (int i = 0; i < n; i++)
	{
		int t, d, p;
		t = info[i].second.first;
		d = info[i].first.first;
		p = info[i].second.second;
		for (int j = 0; j < d-t; j++)
		{
			if (dp[i+1][j+t] < dp[i][j]+p)
			{
				dp[i+1][j+t] = dp[i][j]+p;
				pre[i+1][j+t] = make_pair(i+1, j);
			}
		}
		for (int j = 0; j < 3000; j++)
		{
			if (dp[i+1][j] < dp[i][j])
			{
				dp[i+1][j] = dp[i][j];
				pre[i+1][j] = pre[i][j];
			}
		}
	}
	for (int i = 0; i < 3000; i++)
	{
		ans = max(ans, make_pair(dp[n][i], i));
	}
	printf("%d\n", ans.first);
	ans = pre[n][ans.second];
	while (ans != make_pair(0, 0))
	{
		pri.push_back(info[ans.first-1].first.second);
		ans = pre[ans.first-1][ans.second];
	}
	printf("%d\n", pri.size());
	for (int i = pri.size()-1; i >= 0; i--) printf("%d ", pri[i]);
	printf("\n");
}