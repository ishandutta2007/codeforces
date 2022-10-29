#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int N=100005;
struct node
{
	ll id,num;
};
bool operator <(node a,node b)
{
	return a.num>b.num;
}
priority_queue<node> q;
ll n,m,K,p,h[N],a[N],i,k,lt,rt,mid,w[N],j;
int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&K,&p);
	for(i=1;i<=n;++i)
		scanf("%lld%lld",h+i,a+i);
	lt=0,rt=(m+1)*1000000000ll;
	while(lt<rt)
	{
		mid=lt+rt>>1;
		while(!q.empty())
			q.pop();
		j=0;
		for(i=1;i<=n;++i)
		{
			w[i]=0;
			q.push((node){i,mid/a[i]+1});
		}
		for(k=1;k<=m;++k)
		{
			while(!q.empty()&&q.top().num==k)
			{
				i=q.top().id;
				q.pop();
				j-=(-(mid-a[i]*k+w[i]*p)-1)/p+1;
				if(j<0)
					break;
				w[i]+=(-(mid-a[i]*k+w[i]*p)-1)/p+1;
				q.push((node){i,(mid+w[i]*p+1)/a[i]+1});
			}
			if(j<0)
				break;
			j+=K;
		}
		if(k<=m)
		{
			lt=mid+1;
			continue;
		}
		for(i=1;i<=n;++i)
		{
			w[i]=mid+w[i]*p-1ll*a[i]*m;
			if(w[i]<h[i])
				j-=(h[i]-w[i]-1)/p+1;
		}
		if(j>=0)
			rt=mid;
		else
			lt=mid+1;
	}
	printf("%lld",lt);
	return 0;
}