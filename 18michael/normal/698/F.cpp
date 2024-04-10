#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
using namespace std;
int n,p_t=0;
LL ans=1;
int a[1000002],p[1000002],t[1000002],t1[1000002],cnt[1000002],cnt2[1000002],to[1000002];
LL fac[1000002];
bool u[1000002];
inline void init()
{
	for(int i=fac[0]=cnt2[1]=1;i<=n;++i)t[i]=t1[i]=1,fac[i]=(fac[i-1]*i)%mod;
	t[1]=n;
	for(int i=2;i<=n;++i)
	{
		if(!u[i])
		{
			++cnt2[n/(p[++p_t]=i)];
			for(int j=i;j<=n;j+=i)t[j]*=i;
			if(i<=n/i)for(int j=i;j<=n;j+=i)t1[j]*=i;
		}
		for(int j=1;p[j]*i<=n;++j)
		{
			u[p[j]*i]=1;
			if(!(i%p[j]))break;
		}
	}
	for(int i=2;i<=n;++i)++cnt[t[i]];
}
int main()
{
	scanf("%d",&n),init();
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i])
		{
			x=t[a[i]]/t1[a[i]];
			if((t1[a[i]]^t1[i]) || ((n/x)^(n/(t[i]/t1[i]))))return 0&puts("0");
			if(a[i]>1)--cnt[t[a[i]]];
			if(a[i]==1)--cnt2[1];
			else if(x>n/x)
			{
				if(!to[x])to[x]=t[i]/t1[i],--cnt2[n/x];
				else if(to[x]^(t[i]/t1[i]))return 0&puts("0");
			}
		}
	}
	for(int i=1;i<=n;++i)(((ans*=fac[cnt[i]])%=mod)*=fac[cnt2[i]])%=mod;
	return 0&printf("%lld",ans);
}