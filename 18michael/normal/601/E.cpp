#include<bits/stdc++.h>
#define bs 10000019
#define LL long long
#define mod 1000000007
using namespace std;
int n,K,q,n1;
LL res,tmp;
int v[15002],w[15002],st[15002];
int dp[18][1002];
bool u[30002];
vector<int> vec[120002];
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
inline void add(int k,int l,int r,int l1,int r1,int x)
{
	if(l>=l1 && r<=r1)return (void)(vec[k].push_back(x));
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	if(l1<=mid)add(ls,l,mid,l1,r1,x);
	if(r1>mid)add(rs,mid+1,r,l1,r1,x);
}
inline void solve(int k,int l,int r,int d)
{
	for(int i=0;i<=K;++i)dp[d][i]=dp[d-1][i];
	for(int i=0;i<vec[k].size();++i)for(int j=K;j>=w[vec[k][i]];--j)dp[d][j]=max(dp[d][j],dp[d][j-w[vec[k][i]]]+v[vec[k][i]]);
	if(l==r)
	{
		if(u[l])
		{
			res=0,tmp=1;
			for(int i=1;i<=K;++i)(res+=tmp*dp[d][i])%=mod,(tmp*=bs)%=mod;
			printf("%lld\n",res);
		}
		return ;
	}
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	solve(ls,l,mid,d+1),solve(rs,mid+1,r,d+1);
}
int main()
{
	scanf("%d%d",&n,&K),n1=n;
	for(int i=1;i<=n;++i)scanf("%d%d",&v[i],&w[i]),st[i]=1;
	scanf("%d",&q);
	for(int i=1,o,x,y;i<=q;++i)
	{
		scanf("%d",&o);
		if(o<3)
		{
			scanf("%d",&x);
			if(o==1)scanf("%d",&y),st[++n1]=i,v[n1]=x,w[n1]=y;
			else add(1,1,q,st[x],i,x),st[x]=0;
		}
		else u[i]=1;
	}
	for(int i=1;i<=n1;++i)if(st[i])add(1,1,q,st[i],q,i);
	return solve(1,1,q,1),0;
}