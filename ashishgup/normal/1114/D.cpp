#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5005;

int n;
int a[N], cache[N][N];

int dp(int l, int r)
{
	if(l==1 && r==n)
		return 0;
	int &ans=cache[l][r];
	if(ans!=-1)
		return ans;
	ans=1e9;
	if(l-1>=1 && a[l-1]==a[l])
		ans=min(ans, dp(l-1, r));
	else if(l-1>=1)
		ans=min(ans, 1 + dp(l-1, r));
	if(r+1<=n && a[r+1]==a[r])
		ans=min(ans, dp(l, r+1));
	else if(r+1<=n)
		ans=min(ans, 1 + dp(l, r+1));
	if(l-1>=1 && r+1<=n && a[l-1]==a[r+1])
		ans=min(ans, 1 + dp(l-1, r+1));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=1e9;
	for(int i=1;i<=n;i++)
		ans=min(ans, dp(i, i));
	cout<<ans;
	return 0;
}