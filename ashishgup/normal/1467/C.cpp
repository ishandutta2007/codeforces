//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 3e5 + 5;

int sz[5];
vector<int> v[5];

int32_t main()
{
	IOS;
	for(int i = 1; i <= 3; i++)
		cin >> sz[i];
	int ans = 0;
	int sum = 0;
	for(int i = 1; i <= 3; i++)
	{
		for(int j = 1; j <= sz[i]; j++)
		{
			int x;
			cin >> x;
			sum += x;
			v[i].push_back(x);
		}
		sort(v[i].begin(), v[i].end());
	}
	for(int i = 1; i <= 3; i++)
	{
		int val = sum;
		int mn = 2e9;
		for(int j = 1; j <= 3; j++)
		{
			if(j == i)
				continue;
			int val = sum;
			for(auto &it:v[j])
				val -= 2 * it;
			ans = max(ans, val);
			if(v[i].size() >= 2 && v[j].size() >= 2)
				ans = max(ans, sum - 2 * v[i][0] - 2 * v[j][0]);
		}
	}
	cout << ans;
	return 0;
}