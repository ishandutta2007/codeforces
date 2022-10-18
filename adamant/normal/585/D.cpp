#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9;

void solve()
{
	int n;
	cin >> n;
	int c[3][n];
	for(int i = 0; i < n; i++)
		cin >> c[0][i] >> c[1][i] >> c[2][i];
	int hafn = n / 2 + n % 2;
	int max_msk = round(pow(3, hafn));
	map<pair<int, int>, pair<int, int>> max_sum;
	for(int i = 0; i < max_msk; i++)
	{
		int sum[3];
		memset(sum, 0, sizeof(sum));
		int t = i;
		for(int j = 0; j < hafn; j++)
		{
			sum[0] += c[0][j];
			sum[1] += c[1][j];
			sum[2] += c[2][j];
			sum[t % 3] -= c[t % 3][j];
			t /= 3;
		}
		
		if(max_sum.count({sum[1] - sum[0], sum[2] - sum[1]}) == 0 || max_sum[{sum[1] - sum[0], sum[2] - sum[1]}].first < sum[0] + sum[1] + sum[2])
		{
			max_sum[{sum[1] - sum[0], sum[2] - sum[1]}] = {sum[0] + sum[1] + sum[2], i};
		}
	}
	hafn = n / 2;
	max_msk = round(pow(3, hafn));
	int ans1 = 0, ans2 = 0, bst = -inf;
	int hf = n / 2 + n % 2;
	for(int i = 0; i < max_msk; i++)
	{
		int sum[3];
		memset(sum, 0, sizeof(sum));
		int t = i;
		for(int j = 0; j < hafn; j++)
		{
			sum[0] += c[0][hf + j];
			sum[1] += c[1][hf + j];
			sum[2] += c[2][hf + j];
			sum[t % 3] -= c[t % 3][hf + j];
			t /= 3;
		}
		if(max_sum.count({sum[0] - sum[1], sum[1] - sum[2]}))
		if(max_sum[{sum[0] - sum[1], sum[1] - sum[2]}].first + sum[0] + sum[1] + sum[2] > bst)
		{
			bst = max_sum[{sum[0] - sum[1], sum[1] - sum[2]}].first + sum[0] + sum[1] + sum[2];
			ans1 = max_sum[{sum[0] - sum[1], sum[1] - sum[2]}].second;
			ans2 = i;
		}
	}
	if(bst == -inf)
	{
		cout << "Impossible\n";
		return;
	}
	int s[3] = {0};
	for(int i = 0; i < n / 2 + n % 2; i++)
	{
		if(ans1 % 3 == 0)
			cout << "MW\n";
		if(ans1 % 3 == 1)
			cout << "LW\n";
		if(ans1 % 3 == 2)
			cout << "LM\n";
		ans1 /= 3;
	}
	for(int i = 0; i < n / 2; i++)
	{
		if(ans2 % 3 == 0)
			cout << "MW\n";
		if(ans2 % 3 == 1)
			cout << "LW\n";
		if(ans2 % 3 == 2)
			cout << "LM\n";
		ans2 /= 3;
	}
	
}

main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	while(t--)
		solve();
	return 0;
}