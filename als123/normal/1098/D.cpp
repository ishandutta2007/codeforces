#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<set> 
using namespace std;
typedef long long LL;
const LL N=500005;
LL n;
multiset<LL> s[N];
LL sum[N];
LL query ()
{
	LL tot=0,lalal=0;
	for (LL u=0;u<=30;u++)
	{
		if (!s[u].empty())
		{
			LL t=(*s[u].begin());
			if (t>2*tot) lalal++;
		}
		tot=tot+sum[u];
	}
	return lalal;
}
int main()
{
	scanf("%lld",&n);LL cnt=0;
	for (LL u=1;u<=n;u++)
	{
		char ss[N];scanf("%s",ss+1);
		LL x;scanf("%lld",&x);
		LL p=0;
		while ((1LL<<(p+1))<=x)	p++;
		if (ss[1]=='+')		{sum[p]+=x;s[p].insert(x);cnt++;}
		else	{sum[p]-=x;s[p].erase(s[p].find(x));cnt--;}
		printf("%lld\n",cnt-query());	
	}
	return 0;
}