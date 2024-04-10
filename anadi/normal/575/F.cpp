#include <bits/stdc++.h>
using namespace std;

const int MX = 5005;
const long long int INF = 1e18;
int n, x, beg[MX], endd[MX];
vector<long long int> pos;
long long int dp[2][1000005];

int main()
{
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%d%d", &beg[i], &endd[i]);
		pos.push_back(beg[i]);
		pos.push_back(endd[i]);
		pos.push_back(beg[i]-1);
		pos.push_back(endd[i]+1);	
	}
	pos.push_back(x);
	pos.push_back(x+1);
	pos.push_back(x-1);
	
	sort(pos.begin(), pos.end());
	pos.resize(distance(pos.begin(), unique(pos.begin(), pos.end())));

	for (int i = 0; i < pos.size(); ++ i)
		dp[1][i] = 0;

	for (int ru = n; ru >= 1; -- ru)
	{
		int b = beg[ru], e = endd[ru];
	
		vector<int> bef, aft, in;

		for (int i = 0; i < pos.size(); ++ i)
		{
			if (pos[i] < b)
				bef.push_back(i);		
			if (pos[i] >= b && pos[i] <= e)
				in.push_back(i);
			if (pos[i] > e)
				aft.push_back(i);
		}

		for (int i = 0; i < in.size(); ++ i)
			dp[0][in[i]] = dp[1][in[i]];

		if (!in.empty() && !bef.empty())
		{
			int x = bef[bef.size()-1], y = in[0];
			dp[0][x] = dp[0][y] + pos[y] - pos[x];
		}
		if (!in.empty() && !aft.empty())
		{
			int x = in[in.size()-1], y = aft[0];
			dp[0][y] = dp[0][x] + pos[y] - pos[x];
		}

		for (int i = bef.size()-1; i >= 0; -- i)
		{
			if (dp[0][bef[i]] == 0)
				dp[0][bef[i]] = INF;

			if (i != bef.size()-1)
				dp[0][bef[i]] = min(dp[0][bef[i]], dp[0][bef[i+1]] + pos[bef[i+1]] - pos[bef[i]]);	
			dp[0][bef[i]] = min(dp[0][bef[i]], dp[1][bef[i]] + (b - pos[bef[i]]));
		}
		for (int i = 0; i < aft.size(); ++ i)
		{
			if (dp[0][aft[i]] == 0)
				dp[0][aft[i]] = INF;

			if (i != 0)
				dp[0][aft[i]] = min(dp[0][aft[i]], dp[0][aft[i-1]] + (pos[aft[i]] -	 pos[aft[i-1]]));
			dp[0][aft[i]] = min(dp[0][aft[i]], dp[1][aft[i]] + (pos[aft[i]] - e));
		}

		for (int i = 0; i < pos.size(); ++ i)
			dp[1][i] = dp[0][i];
		for (int i = 0; i < pos.size(); ++ i)
			dp[0][i] = INF;
	}	

	for (int i = 0; i < pos.size(); ++ i)
	{
		if (pos[i] == x)
		{
			printf("%I64d\n", dp[1][i]);
			return 0;
		}
	}

	return 0;
}