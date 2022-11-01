#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>

typedef long long LL;

const int N=1000005;

LL n,a[N],b[N],f[N];
int prime[N],tot,pri,m;
bool not_prime[N];
std::map<LL,int> ma;
std::vector<LL> vec[N];

void get_prime(int n)
{
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++pri]=i;
		for (int j=1;j<=pri&&i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
}

void divi()
{
	for (LL i=1;i*i<=n;i++)
		if (n%i==0)
		{
			a[++tot]=i;
			if (n/i!=i) a[++tot]=n/i;
		}
}

int main()
{
	scanf("%I64d",&n);
	get_prime(sqrt(n));
	divi();
	std::sort(a+1,a+tot+1);
	for (int i=1;i<=tot;i++) ma[a[i]]=i;
	for (int i=1;i<=tot;i++)
	{
		if (a[i]<=2) continue;
		int flag=1,id=pri+1;
		for (int j=1;j<=pri;j++)
			if ((a[i]-1)%prime[j]==0)
			{
				LL tmp=a[i]-1;
				while (tmp%prime[j]==0) tmp/=prime[j];
				flag=(tmp==1);id=j;
				break;
			}
		if (flag) vec[id].push_back(a[i]);
	}
	f[1]=1;
	for (int i=1;i<=pri+1;i++)
		for (int j=tot;j>=1;j--)
			for (int k=0;k<vec[i].size();k++)
			{
				LL p=vec[i][k];
				if (a[j]%p==0) f[j]+=f[ma[a[j]/p]];
			}
	printf("%I64d",f[tot]);
	return 0;
}