#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<map>
using namespace std;
typedef unsigned long long LL;
const LL N=200005;
LL n,m;
LL f[N];
LL sum[N];
LL g[N],h[N];//    
//l^r^
LL f1[N];
LL sum1[N];
LL g1[N],h1[N];//    

map<LL,LL> mp;
map<LL,LL> mp1;
LL cnt[N];
LL calc (LL x)
{
	return (1LL+x)*x/2LL;
}
int main()
{
	srand(200815147);
	scanf("%llu%llu",&n,&m);
	LL tot=0;
	for (LL u=1;u<=n;u++)	
	{
		f[u]=(rand()<<2)*(rand()*3)*rand()*(LL)200815143;
		tot^=f[u];
		
		f1[u]=(rand()<<5)|(rand()*3)^rand()*(LL)200815147;
		tot^=f1[u];
	}
	for (LL u=1;u<=n;u++)
	{
		LL l,r;
		scanf("%llu%llu",&l,&r);
		sum[l]^=f[u];sum[r+1]^=f[u];g[r]^=f[u];h[l]^=f[u];
		sum1[l]^=f1[u];sum1[r+1]^=f1[u];g1[r]^=f1[u];h1[l]^=f1[u];
		cnt[l]++;cnt[r+1]--;
	}
	for (LL u=1;u<=m;u++) h[u]=h[u]^h[u-1];
	for (LL u=m;u>=1;u--) g[u]=g[u]^g[u+1];
	for (LL u=0;u<=m;u++) g[u]=g[u+1];
	for (LL u=1;u<=m;u++) sum[u]=sum[u]^sum[u-1];
	for (LL u=1;u<=m;u++) sum[u]=sum[u]^sum[u-1];
	
	for (LL u=1;u<=m;u++) h1[u]=h1[u]^h1[u-1];
	for (LL u=m;u>=1;u--) g1[u]=g1[u]^g1[u+1];
	for (LL u=0;u<=m;u++) g1[u]=g1[u+1];
	for (LL u=1;u<=m;u++) sum1[u]=sum1[u]^sum1[u-1];
	for (LL u=1;u<=m;u++) sum1[u]=sum1[u]^sum1[u-1];
	
	LL ans=0;
	mp[g[0]^sum[0]^g1[0]^sum1[0]]=1;
	mp1[g[0]^sum[0]^g1[0]^sum1[0]]=0;
	for (LL u=1;u<=m;u++)
	{
		LL xx=(h[u]^tot^sum[u]^h1[u]^sum1[u]);
		ans=ans+mp[xx]*u-mp1[xx];
		mp[g[u]^sum[u]^g1[u]^sum1[u]]++;
		mp1[g[u]^sum[u]^g1[u]^sum1[u]]+=u;
	}
	/*for (LL i=1;i<=m;i++)
		for (LL u=0;u<i;u++)
			if ((g[u]^h[i]^tot^(sum[i]^sum[u]))==0)
				ans=ans+(i-u);*/
	
	for (LL u=1;u<=m;u++) cnt[u]=cnt[u-1]+cnt[u];
	for (LL u=1;u<=m;u++) cnt[u]=cnt[u-1]+cnt[u];
	/*for (LL u=1;u<=m;u++) printf("%llu ",cnt[u]);
	printf("\n");*/
	LL r=0;
	for (LL l=0;l<m;l++)
	{
		r=max(r,l);
		while (r<=m&&cnt[r]==cnt[l]) r++;
		r--;	
		ans=ans-calc(r-l);
	}
	printf("%llu\n",ans);
	return 0;
}