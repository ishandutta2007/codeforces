#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, q, a, b;
int val[N], col[N];
int dp[N], vis[N];

int32_t main()
{
	IOS;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>val[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>col[i];
	}
	for(int j=1;j<=q;j++)
	{
		cin>>a>>b;
		int max1=0, max2=0, col1=-1, col2=-1;
		for(int i=1;i<=n;i++)
		{
			if(vis[col[i]]!=j)
			{
				vis[col[i]]=j;
				dp[col[i]]=((col1==col[i])?max2:max1) + val[i]*b;
			}
			else
			{
				dp[col[i]]=max(max(dp[col[i]], dp[col[i]] + val[i]*a), ((col1==col[i])?max2:max1) + val[i]*b);
			}
			if(dp[col[i]]>max1)
			{
				if(col[i]==col1)
				{
					max1=dp[col[i]];
				}
				else
				{
					max2=max1;
					col2=col1;
					col1=col[i];
					max1=dp[col[i]];
				}
			}
			else if(dp[col[i]]>max2)
			{
				if(col[i]==col2)
				{
					max2=dp[col[i]];
				}
				else
				{
					if(col[i]==col1)
						continue;
					col2=col[i];
					max2=dp[col[i]];
				}
			}
		}
		cout<<max1<<endl;
	}
}