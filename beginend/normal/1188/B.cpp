#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>

typedef long long LL;

const int N=300005;

int n,p,k,a[N];
std::map<int,int> ma;

int main()
{
	scanf("%d%d%d",&n,&p,&k);
	LL ans=0;
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		a[i]=((LL)x*x%p*x%p*x%p-(LL)k*x%p)%p;
		a[i]+=a[i]<0?p:0;
		ans+=ma[a[i]];
		ma[a[i]]++;
	}
	printf("%lld\n",ans);
	return 0;
}