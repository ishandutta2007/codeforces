#include<bits/stdc++.h>
using namespace std;

const int MAXM=15000000;

int a[303030];
int isprime[15050505];
int prime[10101010];
int last[15101010],c[10101010];
int cnt=0;

int gcd(int x,int y)
{
	if(x==0)
		return y;
	if(y==0)
		return x;
	return gcd(y,x%y);
}

int main()
{
	for(int i=2;i<=MAXM;i++)
	{
		if(!isprime[i])
		{
			prime[++cnt]=i;
			last[i]=cnt;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(1ll*i*prime[j]>MAXM)
				break;
			isprime[i*prime[j]]=1;
			last[i*prime[j]]=j;
			if(i%prime[j]==0)
				break;
		}
	}
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int cd=a[1];
	for(int i=2;i<=n;i++)
		cd=gcd(cd,a[i]);
	for(int i=1;i<=n;i++)
		a[i]/=cd;
	for(int i=1;i<=n;i++)
	{
		while(a[i]!=1)
		{
			int tmp=last[a[i]];
			while(a[i]%prime[tmp]==0)
				a[i]/=prime[tmp];
			c[tmp]++;
		}
	}
	int ma=0;
	for(int i=1;i<=cnt;i++)
		ma=max(ma,c[i]);
	if(ma==0)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",n-ma);
	return 0;
}