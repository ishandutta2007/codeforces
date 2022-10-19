#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,k,Mx,tmpa,tmpb,ans,res=-1,s,e;
int X[1000002],Y[1000002],fa[1048576],fb[1048576],to[22],to1[22];
char a[22],b[22];
inline void calc(int x)
{
	tmpa=tmpb=0;
	for(int i=1;i<=k;++i)to1[to[i]]=i;
	for(int i=1;i<=k;++i)tmpa=((tmpa<<1)|(a[to1[i]]^48)),tmpb=((tmpb<<1)|(b[to1[i]]^48));
	fa[tmpa]=min(fa[tmpa],x),fb[tmpb]=max(fb[tmpb],x);
}
int main()
{
	scanf("%d%d%d%s%s",&n,&m,&k,a+1,b+1),Mx=(1<<(ans=k));
	for(int i=1;i<=k;++i)ans-=(a[i]^48)+(b[i]^48),to[i]=i;
	for(int i=0;i<Mx;++i)fa[i]=inf,fb[i]=-inf;
	for(int i=1;i<=n;++i)scanf("%d%d",&X[i],&Y[i]);
	calc(n+1);
	for(int i=n;i;--i)swap(to[X[i]],to[Y[i]]),calc(i);
	for(int i=Mx-1,t;~i;--i)
	{
		for(int j=t=0;j<k;++j)if((i>>j)&1)fa[i^(1<<j)]=min(fa[i^(1<<j)],fa[i]),fb[i^(1<<j)]=max(fb[i^(1<<j)],fb[i]),++t;
		if(fa[i]+m<=fb[i] && t>res)res=t,s=fa[i],e=fb[i]-1;
	}
	return 0&printf("%d\n%d %d",ans+(res<<1),s,e);
}