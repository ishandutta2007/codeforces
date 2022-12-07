#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=22;
const LL M=100005;
LL a[1<<N];
LL b[1<<N];
LL tmp[1<<N];
char ss[N][M];
LL n,nn,m;
void FWT (LL *a,LL n,LL o)
{
	for (LL u=1;u<=n;u<<=1)
	{
		for (LL i=0;i<=n;i++) tmp[i]=0;
		for (LL i=0;i<=n;i++)
		{
			if (u&i) tmp[i]-=a[i],tmp[i^u]+=a[i];
			else tmp[i]+=a[i],tmp[i^u]+=a[i];
		}
		for (LL i=0;i<=n;i++) 
		{
			a[i]=tmp[i];
			if (o==-1) a[i]/=2;
		}
	}
}
int main()
{
	scanf("%lld%lld",&n,&m);nn=(1<<n);nn--;
	for (LL u=1;u<=n;u++)	scanf("%s",ss[u]+1);
	for (LL u=1;u<=m;u++)
	{
		LL now=0;
		for (LL i=1;i<=n;i++)
			now=((now<<1)+ss[i][u]-'0');
		a[now]++;
	}
	b[0]=0;for (LL u=1;u<=nn;u++) b[u]=b[u>>1]+(u&1);
	for (LL u=0;u<=nn;u++) b[u]=min(b[u],n-b[u]);
	FWT(a,nn,1);FWT(b,nn,1);
	for (LL u=0;u<=nn;u++) a[u]=a[u]*b[u];
	FWT(a,nn,-1);
	LL ans=n*m;
	for (LL u=0;u<=nn;u++) ans=min(ans,a[u]);
	printf("%lld\n",ans);
	return 0;
}