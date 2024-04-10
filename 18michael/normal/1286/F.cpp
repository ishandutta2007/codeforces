#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,Mx;
LL a[22],tmp[2];
int one[1048576],dp[1048576];
LL sum[1048576];
bool ok[2];
vector<LL> vec1[2];
vector<int> Vec[2];
vector<LL> vec[1048576][2];
inline bool solve(int x,int o0,LL a0,int o1,LL a1)
{
	vec1[0].clear(),vec1[1].clear(),ok[0]=ok[1]=0;
	for(int i=0;i<vec[x][0].size();++i)
	{
		if(!o0 && !ok[0] && vec[x][0][i]==a0)
		{
			ok[0]=1;
			continue;
		}
		if(!o1 && !ok[1] && vec[x][0][i]==a1)
		{
			ok[1]=1;
			continue;
		}
		vec1[0].push_back(vec[x][0][i]);
	}
	for(int i=0;i<vec[x][1].size();++i)
	{
		if(o0 && !ok[0] && vec[x][1][i]==a0)
		{
			ok[0]=1;
			continue;
		}
		if(o1 && !ok[1] && vec[x][1][i]==a1)
		{
			ok[1]=1;
			continue;
		}
		vec1[1].push_back(vec[x][1][i]);
	}
	for(int i=0,j=vec1[1].size()-1;i<vec1[0].size();++i)
	{
		for(;~j && (vec1[0][i]+vec1[1][j])*2>sum[x]+one[x]-1;--j);
		if(~j && (vec1[0][i]+vec1[1][j])*2>=sum[x]+1-one[x])return 1;
	}
	return 0;
}
inline bool check(int x)
{
	int t=0,y;
	Vec[0].clear(),Vec[1].clear(),tmp[0]=tmp[1]=0;
	for(int i=0;i<n;++i)if((x>>i)&1)Vec[t].push_back(i),++one[x],tmp[t]+=a[i],sum[x]+=a[i],t^=1;
	vec[x][t]=vec[y=x^(1<<Vec[t^1].back())][t];
	for(int i=0,j=0;i<vec[y][t^1].size();++i)
	{
		for(;j<vec[y][t^1].size() && vec[y][t^1][j]<=vec[y][t^1][i]+a[Vec[t^1].back()];++j)vec[x][t^1].push_back(vec[y][t^1][j]);
		vec[x][t^1].push_back(vec[y][t^1][i]+a[Vec[t^1].back()]);
		if(i+1==vec[y][t^1].size())for(;j<vec[y][t^1].size();++j)vec[x][t^1].push_back(vec[y][t^1][j]);
	}
	if((sum[x]^(one[x]-1))&1)return 0;
	if(one[x]==1)return !sum[x];
	return solve(x,0,0,0,tmp[0]) || solve(x,0,0,1,tmp[1]) || solve(x,1,0,0,tmp[0]) || solve(x,1,0,1,tmp[1]);
}
int main()
{
	scanf("%d",&n),Mx=(1<<n),vec[0][0].push_back(0),vec[0][1].push_back(0);
	for(int i=0;i<n;++i)scanf("%lld",&a[i]);
	for(int i=1,i0;i<Mx;++i)
		if(check(i) && !dp[i])
			for(int j=i0=(Mx-1)^i;;(--j)&=i0)
			{
				dp[i|j]=max(dp[i|j],dp[j]+1);
				if(!j)break;
			}
	return 0&printf("%d",n-dp[Mx-1]);
}