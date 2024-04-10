#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PI;
LL n;
map<PI,PI> mp;
PI dfs (LL mx,LL n)
{
	if (mp[make_pair(mx,n)].first!=0)	return mp[make_pair(mx,n)];
	if (n<10) return make_pair((mx>0)||(n>0),max(mx,n)-n);
	LL m=1;
	while (m<=n/10)	m*=10;
	LL p=n/m;
	m=p*m;
	PI a=dfs(max(mx,p),n-m);
	PI b=dfs(mx,m-a.second);
	//printf("%lld %lld %lld %lld %lld\n",n,n-m,a.first,m-a.second,b.first);
	return mp[make_pair(mx,n)]=make_pair(a.first+b.first,b.second);
}
int main()
{
	scanf("%I64d",&n);
	printf("%I64d\n",dfs(0,n).first);
	return 0;
}