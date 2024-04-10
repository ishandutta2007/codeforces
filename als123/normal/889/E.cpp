#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
typedef long long LL;
map<LL,LL> f;
map<LL,LL> :: iterator it;
int main()
{
	LL n;
	scanf("%lld",&n);
	LL x;
	scanf("%lld",&x);
	f[x-1]=0;
	for (LL i=1;i<n;i++)
	{
		LL x;
		scanf("%lld",&x);
		while (f.begin()!=f.end())
		{
			it=--f.end();
			LL a,b;
			a=(*it).first;b=(*it).second;
			if (a<x) break;
			f[x-1]=max(f[x-1],b+i*(a-a%x-x));
			f[a%x]=max(f[a%x],b+i*(a-a%x));
			f.erase(it);
		}
	}
	LL ans=0;
	for (it=f.begin();it!=f.end();it++) ans=max(ans,n*(*it).first+(*it).second);
	printf("%lld\n",ans);
	return 0;
}