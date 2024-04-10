//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=1e5+9;
int n,m,k,to[N],back[N],now=0,cnt[N],qwq=0,pp[N];
struct point
{
	int d,f,t,c;
}p[N];
inline bool cmp(point xxx,point yyy)
{
	return xxx.d<yyy.d;
}
signed main()
{
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		p[i].d=read(),p[i].f=read(),p[i].t=read(),p[i].c=read();swap(p[i].f,p[i].t);	
	}
	for(int i=1;i<=m;i++)to[i]=back[i]=1e17;
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=n;i++)cnt[i]=1e17;now=0;qwq=0;
	for(int i=1;i<=m;i++)
	{
		if(p[i].f)continue;
		if(cnt[p[i].t]>=1e17)now++,cnt[p[i].t]=p[i].c,qwq+=p[i].c;
		else if(cnt[p[i].t]>p[i].c)qwq-=cnt[p[i].t],cnt[p[i].t]=p[i].c,qwq+=p[i].c;
		if(now==n)to[i]=qwq;
	}
	for(int i=1;i<=n;i++)cnt[i]=1e17;now=0;qwq=0;
	for(int i=m;i>=1;i--)
	{
		if(p[i].t)continue;
		if(cnt[p[i].f]>=1e17)now++,cnt[p[i].f]=p[i].c,qwq+=p[i].c;
		else if(cnt[p[i].f]>p[i].c)qwq-=cnt[p[i].f],cnt[p[i].f]=p[i].c,qwq+=p[i].c;
		if(now==n)back[i]=qwq;
	//	cout<<qwq<<" "<<back[i]<<" "<<i<<endl;
	}
	for(int i=1;i<=m;i++)pp[i]=p[i].d;
	long long ans=1e17;
	for(int i=1;i<=m;i++)
	{
		if(pp[i]+k<pp[m])
		{
			int pos=upper_bound(pp+1,pp+m+1,pp[i]+k)-pp;ans=min(ans,to[i]+back[pos]);
	//		cout<<i<<" "<<pos<<" "<<pp[i]+k<<" "<<pp[pos]<<endl;
		}
	}
	if(ans>=1e17)puts("-1");
	else printf("%lld\n",ans);
	return 0;
}