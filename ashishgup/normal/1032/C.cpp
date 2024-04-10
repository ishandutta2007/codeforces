#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], cache[N][10];

int dp(int idx, int cur)
{
	if(idx==n)
		return 1;
	int &ans=cache[idx][cur];
	if(ans!=-1)
		return ans;
	ans=0;
	if(a[idx+1]>a[idx])
	{
		for(int i=cur+1;i<=5;i++)
			ans|=dp(idx+1, i);
	}
	else if(a[idx+1]==a[idx])
	{
		for(int i=1;i<=5;i++)
		{
			if(i==cur)
				continue;
			ans|=dp(idx+1, i);
		}
	}
	else
	{
		for(int i=1;i<cur;i++)
			ans|=dp(idx+1, i);
	}
	return ans;
}

void path(int idx, int cur)
{
	cout<<cur<<" ";
	if(idx==n)
		return;
	if(a[idx+1]>a[idx])
	{
		for(int i=cur+1;i<=5;i++)
			if(dp(idx+1, i))
				return path(idx+1, i);

	}
	else if(a[idx+1]==a[idx])
	{
		for(int i=1;i<=5;i++)
		{
			if(i==cur)
				continue;
			if(dp(idx+1, i))
				return path(idx+1, i);
		}
	}
	else
	{
		for(int i=1;i<cur;i++)
			if(dp(idx+1, i))
				return path(idx+1, i);
	}
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=5;i++)
	{
		if(dp(1, i))
		{
			path(1, i);
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}