#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,X,Y,res,ans=0;
int val[52];
int dp[52][2];
bool vis[52];
vector<int> vec;
inline void dfs(int x)
{
	if(vis[x])return ;
	vis[x]=1,vec.push_back(x),dfs((x+X)%(X+Y)),dfs((x+Y)%(X+Y));
}
int main()
{
	scanf("%d%d%d",&n,&X,&Y);
	for(int i=0;i<X+Y;++i)val[i]=(n-i+X+Y-1)/(X+Y);
	for(int i=0;i<X+Y;++i)
		if(!vis[i])
		{
			vec.clear(),dfs(i),dp[0][0]=0,dp[0][1]=-inf;
			for(int j=1;j<vec.size();++j)dp[j][0]=max(dp[j-1][0],dp[j-1][1]),dp[j][1]=dp[j-1][0]+val[vec[j]];
			res=max(dp[vec.size()-1][0],dp[vec.size()-1][1]),dp[0][0]=-inf,dp[0][1]=val[vec[0]];
			for(int j=1;j<vec.size();++j)dp[j][0]=max(dp[j-1][0],dp[j-1][1]),dp[j][1]=dp[j-1][0]+val[vec[j]];
			ans+=max(res,dp[vec.size()-1][0]);
		}
	return 0&printf("%d",ans);
}