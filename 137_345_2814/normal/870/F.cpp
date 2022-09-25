#include<cstdio>
#include<algorithm>
using namespace std;
#define N 10000070
int pr[N],ch[N],phi[N],s[N],su1[N],n,ct;
int prime(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!ch[i])pr[++ct]=i,phi[i]=i-1,s[i]=i;
		for(int j=1;1ll*i*pr[j]<=n&&j<=ct;j++)
		{
			ch[i*pr[j]]=1,phi[i*pr[j]]=phi[i]*(pr[j]-1);
			s[i*pr[j]]=pr[j];
			if(i%pr[j]==0)
			{
				phi[i*pr[j]]=phi[i]*pr[j];
				break;
			}
		}
	}
}
int main()
{
	scanf("%d",&n);prime(n);
	long long su=n-1,as=0,sp=0;
	for(int i=1;i<=ct;i++)if(pr[i]>n/2)su--;
	su=su*(su-1)/2;
	for(int i=2;i<=n;i++)sp+=phi[i];
	as+=1ll*n*(n-1)/2-sp;
	as+=(su-as)*2;
	for(int i=2;i<=n;i++)su1[s[i]]++;
	for(int i=2;i<=n;i++)su1[i]+=su1[i-1];
	for(int i=1;i<=ct;i++)
	{
		int l=max(n/pr[i],pr[i])+1,r=n/2;
		if(l>r)continue;
		as+=1ll*(su1[r]-su1[l-1])*(su1[pr[i]]-su1[pr[i]-1]);
	}
	printf("%lld\n",as);
}