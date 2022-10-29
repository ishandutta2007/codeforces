#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int N=500005;
struct node
{
	int h,d;
}t;
bool operator <(node a,node b)
{
	return a.d>b.d;
}
priority_queue<node> q;
int m,a,b,d,i,j,dis[N];
bool v[N];
long long ans;
int gcd(int a,int b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
long long cirno(int n)
{
	long long rtn=n;
	if(n%d)
	{
		int i=n;
		n-=n%d;
		for(;i>n;--i)
			rtn+=i/d;
	}
	rtn+=1ll*(1+n/d-1)*(n/d-1)/2*d+n/d;
	return rtn;
}
int main()
{
	scanf("%d%d%d",&m,&a,&b);
	d=gcd(a,b);
	if(m>2*(a+b))
	{
		ans=cirno(m)-cirno(2*(a+b));
		m=2*(a+b);
	}
	for(i=1;i<=2*(a+b);++i)
		dis[i]=1<<30;
	q.push((node){0,0});
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(v[t.h])
			continue;
		v[t.h]=true;
		if(t.h+a<=2*(a+b)&&max(t.d,t.h+a)<dis[t.h+a])
		{
			dis[t.h+a]=max(t.d,t.h+a);
			q.push((node){t.h+a,dis[t.h+a]});
		}
		if(t.h-b>=0&&t.d<dis[t.h-b])
		{
			dis[t.h-b]=t.d;
			q.push((node){t.h-b,dis[t.h-b]});
		}
	}
	for(i=0;i<=m;++i)
		if(dis[i]<=m)
			ans+=m-dis[i]+1;
	printf("%lld",ans);
	return 0;
}