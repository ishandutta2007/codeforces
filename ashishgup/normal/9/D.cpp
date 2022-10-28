#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=50;

int cache[N][N];

int dp(int n, int h)
{
	if(n==0)
		return h==0;
	if(h==0)
		return 0;
	if(n==1)
		return h==1;
	if(cache[n][h]!=-1)
		return cache[n][h];
	int &ans=cache[n][h];
	ans=0;
	for(int root=1;root<=n;root++)
	{
		int leftnodes=root-1;
		int rightnodes=n-root;
		int left1=dp(leftnodes, h-1);
		int right1=0;
		for(int curh=0;curh<h-1;curh++)
			right1+=dp(rightnodes, curh);
		int pos1=left1*right1;
		int left2=0;
		for(int curh=0;curh<h-1;curh++)
			left2+=dp(leftnodes, curh);
		int right2=dp(rightnodes, h-1);
		int pos2=left2*right2;
		int pos3=dp(leftnodes, h-1)*dp(rightnodes, h-1);
		ans+=pos1+pos2+pos3;
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	int n, h;
	cin>>n>>h;
	int ans=0;
	for(int i=h;i<=n;i++)
	{
		ans+=dp(n, i);
	}
	cout<<ans;
	return 0;
}