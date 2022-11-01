#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=1000005;

int n,k,tot,prime[N],a[N],phi[N];
bool not_prime[N];

void get_phi(int n)
{
	phi[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++tot]=i,phi[i]=i-1;
		for (int j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=1;
			if (i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	if (k==1) {printf("%d\n",3);return 0;}
	get_phi(n);
	int tot=0;
	for (int i=3;i<=n;i++) a[++tot]=phi[i];
	std::sort(a+1,a+tot+1);
	LL ans=2;
	for (int i=1;i<=k;i++) ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}