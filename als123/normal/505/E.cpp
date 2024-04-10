#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<set>
#include<queue>
using namespace std;
typedef long long LL;
const LL N=100005;
const LL MAX=(1LL<<55);
typedef pair<LL,pair<LL,LL> > PI;
LL n,m,k,p;
LL h[N],a[N];
priority_queue<PI,vector<PI>,greater<PI> > s;
inline LL read()
{
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool check (LL x)
{
	while(!s.empty()) s.pop(); 
	for (LL u=1;u<=n;u++)	
	{
		if (x<a[u]) return false;
		//printf("YES:%lld  %lld\n",u,x/a[u]);
		s.push({x/a[u],{u,x}});
	}
	LL tot=0;//
	for (LL u=1;u<m;u++)
	{
		while (true)
		{
			PI x=s.top();
			if (x.first==u)//
			{
				LL now=x.second.second;//
				LL id=x.second.first;//
				now=now%a[id];
				LL need=(a[id]-now+p-1)/p;//
				tot=tot+need;
				if (tot>u*k) return false;
				now=now+need*p;
				s.pop();
				s.push({x.first+now/a[id],{id,now}});
			}
			else break;
		}
		if (tot>u*k) return false;
	}
	//printf("%lld\n",tot);
	while (!s.empty())
	{
		PI x=s.top();s.pop();
		LL now=x.second.second;
		LL id=x.second.first;
		LL nxt=x.first;//
		now=now%a[id];//
		now=now+(nxt-m)*a[id];
		if (now>=h[id]) continue;
		LL need=(h[id]-now+p-1)/p;
		tot=tot+need;
	}
	if (tot>m*k) return false;
	return true;
}
int main()
{
	n=read();m=read();k=read();p=read();
	//scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
	for (LL u=1;u<=n;u++)
	{
		h[u]=read();
		a[u]=read();
	}
	//printf("%d",check(7));
	LL l=0,r=MAX,ans=0;
	while (l<=r)
	{
		LL mid=(l+r)>>1;
		if (check(mid))	{ans=mid;r=mid-1;}
		else l=mid+1;
	}
	printf("%I64d\n",ans);
	return 0;
}