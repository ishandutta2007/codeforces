#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=2000005;
const int MOD=1000000007;

int n,k,mu[N],prime[N],tot,ans[N],po[N];
bool not_prime[N];

void get_prime(int n)
{
	mu[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++tot]=i,mu[i]=-1;
		for (int j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=1;
			if (i%prime[j]==0) break;
			mu[i*prime[j]]=-mu[i];
		}
	}
	for (int i=1;i<=n;i++) mu[i]+=mu[i]<0?MOD:0;
}

int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&k);
	get_prime(k);
	for (int i=1;i<=k;i++) po[i]=ksm(i,n);
	for (int i=1;i<=k;i++)
		for (int j=i;j<=k;j+=i)
		{
			int w=(LL)mu[i]*po[j/i]%MOD;
			ans[j]+=w;ans[j]-=ans[j]>=MOD?MOD:0;
			ans[j+i]+=MOD-w;ans[j+i]-=ans[j+i]>=MOD?MOD:0;
		}
	for (int i=1;i<=k;i++) ans[i]+=ans[i-1],ans[i]-=ans[i]>=MOD?MOD:0;
	int s=0;
	for (int i=1;i<=k;i++) s+=ans[i]^i,s-=s>=MOD?MOD:0;
	printf("%d",s);
	return 0;
}