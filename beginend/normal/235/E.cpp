#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=2005;
const int MOD=1073741824;

int a,b,c,n,tot,prime[N*N],mu[N*N],f[N],s[N*N];
bool not_prime[N*N];

void mod(int &x)
{
	x-=x>=MOD?MOD:0;
}

int gcd(int x,int y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

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
}

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	get_prime(a*b);
	for (int d=1;d<=c;d++)
	{
		int n=c/d;
		for (int i=1,last;i<=n;i=last+1)
		{
			last=n/(n/i);
			mod(f[d]+=(n/i)*(last-i+1));
		}
	}
	for (int i=1;i<=c;i++)
	{
		if (!mu[i]) continue;
		int w=mu[i]*f[i];
		w+=w<0?MOD:0;
		for (int j=i;j<=a*b;j+=i) mod(s[j]+=w);
	}
	int ans=0;
	for (int i=1;i<=a;i++)
		for (int j=1;j<=b;j++)
			if (gcd(i,j)==1) mod(ans+=(LL)(a/i)*(b/j)*s[i*j]&(MOD-1));
	printf("%d",ans);
	return 0;
}