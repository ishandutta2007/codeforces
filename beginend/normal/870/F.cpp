#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long LL;

const int N=10000005;

int n,tot,prime[N],phi[N],low[N],s[N];
bool not_prime[N];

void get_prime(int n)
{
	phi[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++tot]=i,phi[i]=i-1,low[i]=tot;
		for (int j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=1;
			low[i*prime[j]]=j;
			if (i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
	for (int i=2;i<=n;i++) s[low[i]]++;
	while (prime[tot]>n/2) tot--;
	for (int i=tot-1;i>=1;i--) s[i]+=s[i+1];
}

int main()
{
	scanf("%d",&n);
	get_prime(n);
	LL ans=0,sum=0;int now=0;
	for (int i=2;i<=n;i++)
	{
		ans+=i-1-phi[i];
		if (i<=n/2||not_prime[i]) sum+=phi[i]-1-now;
		else now++;
	}
	ans+=sum*2;sum=0;
	int p=tot,lim=sqrt(n),cnt=0;
	for (int i=1;i<=tot;i++)
	{
		if (prime[i]<=lim) continue;
		while ((LL)prime[p-1]*prime[i]>(LL)n) p--;
		sum+=s[p];cnt++;
	}
	ans+=sum-(LL)cnt*(cnt+1)/2;
	printf("%I64d",ans);
	return 0;
}