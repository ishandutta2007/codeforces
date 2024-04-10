#include<bits/stdc++.h>
using namespace std;
const int N=1000005,M=998244353,P=1000000007;
typedef long double lb;
int n,i,j,k,a,f[N];
long long dp[N][4];
void dfs(int i,int l,int r)
{
	if(r-l==1)
	{
		if(f[l]&&f[l+1])
		{
			dp[i][3]=1;
			dp[i][1]=dp[i][2]=dp[i][0]=-1000000000;
		}
		else
			if(f[l]||f[l+1])
			{
				dp[i][3]=dp[i][0]=-1000000000;
				dp[i][1]=dp[i][2]=1;
			}
			else
				dp[i][1]=dp[i][2]=dp[i][3]=-1000000000;
		return;
	}
	int mid=l+r>>1;
	int x=i<<1,y=i<<1|1;
	dfs(x,l,mid);
	dfs(y,mid+1,r);
	for(int j=0;j<4;++j)
		dp[i][j]=-1000000000;
	for(j=0;j<4;++j)
		for(k=0;k<4;++k)
			if(j==1&&k==1)
				dp[i][3]=max(dp[i][3],dp[x][j]+dp[y][k]+2);
			else
				if(j==1)
				{
					if(k==0)
					{
						dp[i][2]=max(dp[i][2],dp[x][j]+dp[y][k]+2);
						dp[i][1]=max(dp[i][1],dp[x][j]+dp[y][k]+1);
					}
					else
						dp[i][3]=max(dp[i][3],dp[x][j]+dp[y][k]+(k==1?2:3));
				}
				else
					if(k==1)
					{
						if(j==0)
						{
							dp[i][2]=max(dp[i][2],dp[x][j]+dp[y][k]+2);
							dp[i][1]=max(dp[i][1],dp[x][j]+dp[y][k]+1);
						}
						else
							dp[i][3]=max(dp[i][3],dp[x][j]+dp[y][k]+(j==1?2:3));
					}
					else
						dp[i][j|k]=max(dp[i][j|k],dp[x][j]+dp[y][k]+(j|k));
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&k);
	for(i=1;i<=k;++i)
	{
		scanf("%d",&a);
		f[a]=1;
	}
	dfs(1,1,1<<n);
	cout<<max({dp[1][0],dp[1][1]+1,dp[1][2]+1,dp[1][3]+1});
}