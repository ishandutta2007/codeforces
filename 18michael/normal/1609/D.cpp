#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,d,t=0,p=0;
LL now,ans=1;
int rt[1000002];
LL siz[1000002];
set<LL,greater<LL> > s;
set<LL,greater<LL> >::iterator it;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline LL num(LL x,LL y)
{
	return x*2006+y;
}
int main()
{
	read(n),read(d),now=num(1,n);
	for(int i=1;i<=n;++i)rt[i]=i,s.insert(siz[i]=num(1,++p));
	for(int x,y;d--;)
	{
		read(x),read(y),getroot(x),getroot(y);
		if(rt[x]==rt[y])it=s.upper_bound(now),ans+=(*it)/2006,now=(*it);
		else
		{
			if(siz[rt[x]]>=now)++t,ans-=siz[rt[x]]/2006;
			it=s.lower_bound(siz[rt[x]]),s.erase(it);
			if(siz[rt[y]]>=now)++t,ans-=siz[rt[y]]/2006;
			it=s.lower_bound(siz[rt[y]]),s.erase(it);
			siz[rt[x]]/=2006,siz[rt[y]]/=2006;
			siz[rt[x]]+=siz[rt[y]],rt[rt[y]]=rt[x];
			siz[rt[x]]=num(siz[rt[x]],++p);
			s.insert(siz[rt[x]]);
			if(siz[rt[x]]>=now)
			{
				if(t)--t,ans+=siz[rt[x]]/2006;
				else
				{
					it=s.upper_bound(now),--it;
					ans-=(*it)/2006;
					ans+=siz[rt[x]]/2006;
					--it,now=(*it);
				}
			}
			it=s.upper_bound(now);
			while(t)ans+=(*it)/2006,now=(*it),++it,--t;
		}
		printf("%lld\n",ans-1);
	}
	return 0;
}