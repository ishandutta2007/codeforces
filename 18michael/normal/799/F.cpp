#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m;
LL tmp,ans=0;
LL sum[200002],sum1[200002],w[200002];
unordered_map<LL,LL> mp,mp1;
inline LL RND()
{
	LL res=rand();
	res*=rand(),res^=rand();
	res*=rand(),res^=rand();
	res*=rand(),res^=rand();
	res*=rand(),res^=rand();
	return res;
}
inline LL F(LL x)
{
	return ((x*(x+1))>>1);
}
inline LL F2(LL x)
{
	return (x*(x+1)*((x<<1)+1))/6;
}
inline void ins(int x,int o)
{
	mp[sum[x]]+=x*o,mp1[sum[x]]+=o;
	if(!mp1[sum[x]])mp.erase(sum[x]),mp1.erase(sum[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=n;++i)scanf("%d%d",&x,&y),tmp=RND(),w[x]^=tmp,w[y]^=tmp,sum1[x]^=tmp,sum1[y+1]^=tmp,sum[x+1]^=tmp,sum[y+1]^=tmp;
	for(int i=1;i<=m;++i)sum[i]^=sum[i-1],sum1[i]^=sum1[i-1];
	for(int i=0;i<=m;ins(i,1),++i)if(i)sum[i]^=sum[i-1];
	for(int i=1,j;i<=m;ans-=((F2(j-i)+F(j-i))>>1),i=j+1)for(j=i;j<=m && !sum1[j];++j);
	for(int i=tmp=0;i<m;++i)
	{
		ins(i,-1),tmp^=w[i],sum[i]^=tmp;
		if(mp1.count(sum[i]))ans+=mp[sum[i]]-mp1[sum[i]]*i;
	}
	return 0&printf("%lld",ans);
}