#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k;
vector<int> store[5];

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		int t, a, b;
		cin >> t >> a >> b;
		store[a * 2 + b].push_back(t);
	}
	for(int i = 0; i <= 3; i++)
	{
		store[i].push_back(0);
		sort(store[i].begin(), store[i].end());
		for(int j = 1; j < (int)store[i].size(); j++)
			store[i][j] += store[i][j - 1];
	}
	int ans = -1;
	for(int i = 0; i < (int)store[3].size(); i++)
	{
		int cur = store[3][i];
		int rem = k - i;
		if(rem < (int)store[1].size() && rem < (int)store[2].size())
		{
			if(rem >= 0)
				cur += store[1][rem] + store[2][rem];
			if(ans == -1)
				ans = cur;
			else if(ans > cur)
				ans = cur;
		}
	}
	cout << ans;
	return 0;
}