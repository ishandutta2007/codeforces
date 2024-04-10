#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
int n;
typedef long long ll;
ll m[1111111],v[1111111];
int main()
{
	scanf("%d",&n);
	register int i,ii;
	ll S0=0,R=0;
	for(i=1;i<=n;i++)scanf("%lld%lld",v+i,m+i),S0+=v[i];
	for(i=61;~i;i--)
	{
		ll M=1ll<<i,S=0;
		for(ii=1;ii<=n;ii++)
		{
			if((m[ii]&(-m[ii]))==M)S+=v[ii];
		}if(S0<0)S=-S;
		if(S>0)
		{
			R|=M;
			for(ii=1;ii<=n;ii++)
				if(m[ii]&M)v[ii]=-v[ii];
		}
	}printf("%lld\n",R);
}
/*
Please don't let me down.
*/