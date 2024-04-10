#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N];

int getMax()
{
	int ans = 0, cur = -1e9;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] - 1 > cur)
		{
			ans++;
			cur = a[i] - 1;
		}
		else if(a[i] > cur)
		{
			ans++;
			cur = a[i];
		}
		else if(a[i] + 1 > cur)
		{
			ans++;
			cur = a[i] + 1;
		}
	}
	return ans;
}

int mark[N];
int cache[N];

int dp(int idx)
{
	if(idx > n)
		return 0;
	int &ans = cache[idx];
	if(ans != -1)
		return ans;
	if(!mark[idx])
		ans = dp(idx + 1);
	else
		ans = 1 + min(dp(idx + 2), dp(idx + 3));
	return ans;
}

int getMin()
{
	return dp(1);
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mark[a[i]] = 1;
	}
	sort(a + 1, a + n + 1);
	cout << getMin() << " " << getMax();
	return 0;
}