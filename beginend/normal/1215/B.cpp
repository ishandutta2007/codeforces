#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=200005;

int n,a[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]/=abs(a[i]);
	LL s1=0,s2=0,k1=0,k2=0;
	k2++;
	for (int i=1;i<=n;i++)
	{
		if (i>1) a[i]*=a[i-1];
		if (a[i]==1) s1+=k1,s2+=k2,k2++;
		else s1+=k2,s2+=k1,k1++;
	}
	printf("%lld %lld\n",s1,s2);
	return 0;
}