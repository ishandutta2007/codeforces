#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k;
int a[N], f[N];
vector<pair<int, int> > store[N];

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[a[i]]++;
	}
	for(int i = 0; i <= 2e5; i++)
	{
		int x = i, cnt = 0;
		while(true)
		{
			bool check = 0;
			if(x == 0)
				check = 1;
			store[x].push_back({i, cnt});
			x /= 2;
			cnt++;
			if(check)
				break;
		}
	}
	int ans = 1e18;
	for(int i = 0; i <= 2e5; i++)
	{
		int cur = 0, reqd = k;
		for(auto &it:store[i])
		{
			int take = min(reqd, f[it.first]);
			reqd -= take;
			cur += it.second * take;
			if(reqd == 0)
				break;
		}
		if(reqd == 0)
			ans = min(ans, cur);
	}
	cout << ans;
	return 0;
}