#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,p,s,ans=0,mx,o;
int a[3002],b[3002],f[3002];
typedef pair<int,int> P;
P p1,p2,p3,p4;
priority_queue<P,vector<P> > q1,q2,q3,q4;
inline void upd(int x,int y)
{
	f[x]=y;
	if(y==1)q4.push(P(b[x]-a[x],x));
	else q3.push(P(a[x]-b[x],x));
}
int main()
{
	scanf("%d%d%d",&n,&p,&s),q1.push(P(-inf,0)),q2.push(P(-inf,0)),q3.push(P(-inf,0)),q4.push(P(-inf,0));
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),q1.push(P(a[i],i));
	for(int i=1;i<=n;++i)scanf("%d",&b[i]),q2.push(P(b[i],i));
	for(;p || s;)
	{
		while(f[q1.top().second])q1.pop();
		while(f[q2.top().second])q2.pop();
		while(f[q3.top().second]==1)q3.pop();
		while(f[q4.top().second]==2)q4.pop();
		p1=q1.top(),p2=q2.top(),p3=q3.top(),p4=q4.top(),mx=-inf;
		if(p && p1.first>mx)mx=p1.first,o=1;
		if(s && p2.first>mx)mx=p2.first,o=2;
		if(p && p2.first+p3.first>mx)mx=p2.first+p3.first,o=3;
		if(s && p1.first+p4.first>mx)mx=p1.first+p4.first,o=4;
		ans+=mx;
		if(o==1)--p,upd(p1.second,1);
		else if(o==2)--s,upd(p2.second,2);
		else if(o==3)--p,upd(p2.second,2),upd(p3.second,1);
		else --s,upd(p1.second,1),upd(p4.second,2);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)if(f[i]==1)printf("%d ",i);
	puts("");
	for(int i=1;i<=n;++i)if(f[i]==2)printf("%d ",i);
	return 0;
}