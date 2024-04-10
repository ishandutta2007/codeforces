#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const LL N=100005;
LL n,k;
LL a[N],b[N];
priority_queue<pair<LL,LL> > q;
LL calc (LL x,LL y)
{
	x=a[x];
	LL t=x/y,t1=x%y;
	return t1*(t+1)*(t+1)+(y-t1)*t*t;
}
int main()
{
	LL ans=0;
	scanf("%lld%lld",&n,&k);
	for (LL u=1;u<=n;u++)
	{
		scanf("%lld",&a[u]);
		b[u]=1;ans=ans+a[u]*a[u];
		if (a[u]!=b[u]) 
		{
			q.push(make_pair(calc(u,b[u])-calc(u,b[u]+1),u));
		}
	}
	//printf("%lld\n",calc(1,3));
	for (LL u=n+1;u<=k;u++)
	{
		pair<LL,LL> x=q.top();q.pop();
		LL xx=x.second;
		//printf("%lld %lld\n",xx,x.first);
		ans=ans-x.first;
		b[xx]++;
		if (b[xx]!=a[xx]) q.push(make_pair(calc(xx,b[xx])-calc(xx,b[xx]+1),xx));
	}
	printf("%lld\n",ans);
	return 0;
}