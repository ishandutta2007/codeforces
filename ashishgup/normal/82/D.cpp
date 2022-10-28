#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n;
int a[N], cache[N][N];

int dp(int idx, int prev)
{	
	if(idx>n)
		return a[prev];
	if(idx==n)
		return max(a[idx], a[prev]);
	int &ans=cache[idx][prev];
	if(ans!=-1)
		return ans;
	ans=1e9;
	if(!prev)
	{
		ans=min(ans, max(a[idx], a[idx+1]) + dp(idx+2, prev));
		if(idx+2<=n)
		{
			ans=min(ans, max(a[idx], a[idx+2]) + dp(idx+3, idx+1));
			ans=min(ans, max(a[idx+1], a[idx+2]) + dp(idx+3, idx));
		}
	}
	else
	{
		ans=min(ans, max(a[idx], a[idx+1]) + dp(idx+2, prev));
		ans=min(ans, max(a[idx], a[prev]) + dp(idx+1, 0));
		ans=min(ans, max(a[idx+1], a[prev]) + dp(idx+2, idx));
	}
	return ans;
}

void path(int idx, int prev)
{	
	if(idx>n)
	{
		if(prev)
			cout<<prev<<endl;
		return;
	}
	if(idx==n)
	{
		if(prev)
			cout<<idx<<" "<<prev<<endl;
		else
			cout<<idx<<endl;
	}
	int ans=cache[idx][prev];
	if(!prev)
	{
		if(ans==max(a[idx], a[idx+1]) + dp(idx+2, prev))
		{
			cout<<idx<<" "<<idx+1<<endl;
			return path(idx+2, prev);
		}
		if(idx+2<=n)
		{
			if(ans==max(a[idx], a[idx+2]) + dp(idx+3, idx+1))
			{
				cout<<idx<<" "<<idx+2<<endl;
				return path(idx+3, idx+1);
			}
			if(ans==max(a[idx+1], a[idx+2]) + dp(idx+3, idx))
			{
				cout<<idx+1<<" "<<idx+2<<endl;
				return path(idx+3, idx);
			}
		}
	}
	else
	{
		if(ans==max(a[idx], a[idx+1]) + dp(idx+2, prev))
		{
			cout<<idx<<" "<<idx+1<<endl;
			return path(idx+2, prev);
		}
		if(ans==max(a[idx], a[prev]) + dp(idx+1, 0))
		{
			cout<<idx<<" "<<prev<<endl;
			return path(idx+1, 0);
		}
		if(ans==max(a[idx+1], a[prev]) + dp(idx+2, idx))
		{
			cout<<idx+1<<" "<<prev<<endl;
			return path(idx+2, idx);
		}
	}
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=dp(1, 0);
	cout<<ans<<endl;
	path(1, 0);
	return 0;
}