#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 5005;

int n, k;
int a[N], prv[N];
int cache[N][N];

int dp(int idx, int take)
{
	if(take < 0)
		return -1e9;
	if(idx == 0)
		return 0;
	int &ans = cache[idx][take];
	if(ans != -1)
		return ans;
	ans = dp(idx - 1, take);
	ans = max(ans, idx - prv[idx] + dp(prv[idx], take - 1));
	return ans;
}	

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	int l = 1;
	for(int r=1;r<=n;r++)
	{
		while(a[r] - a[l] > 5)
			l++;
		prv[r] = l - 1;
	}
	int ans = dp(n, k);
	cout<<ans;
	return 0;
}