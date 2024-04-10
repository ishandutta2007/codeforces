#include<bits/stdc++.h>
#define LD long double
using namespace std;
int n,t,q;
LD ans=0;
int p[200002],l[200002],X[200002];
LD tot[200002];
typedef pair<LD,int> P;P pr;
multiset<P,greater<P> > ms[2];
inline void Insert(int x,int y)
{
	if(((!x && X[y]) || (x && X[y]<l[y])) && X[y]-1+x+l[y])ms[x].insert(P(1.0l*p[y]*l[y]/(X[y]+x+l[y])/(X[y]-1+x+l[y]),y));
}
inline void Erase(int x,int y)
{
	if(X[y]-1+x+l[y])ms[x].erase(P(1.0l*p[y]*l[y]/(X[y]+x+l[y])/(X[y]-1+x+l[y]),y));
}
int main()
{
	scanf("%d%d%d",&n,&t,&q);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=1;i<=n;++i)scanf("%d",&l[i]),Insert(1,i);
	for(;t && ms[1].size();--t)ans+=(pr=*ms[1].begin()).first,tot[pr.second]+=pr.first,Erase(0,pr.second),Erase(1,pr.second),++X[pr.second],Insert(0,pr.second),Insert(1,pr.second);
	for(int o,x;q--;)
	{
		scanf("%d%d",&o,&x),ans-=tot[x],Erase(0,x),Erase(1,x);
		if(o==1)
		{
			if(X[x])tot[x]-=1.0l*p[x]/(l[x]+1),--X[x],++t;
			tot[x]=tot[x]/l[x]*(l[x]+1),ans+=tot[x],++l[x];
		}
		else
		{
			if(X[x]==l[x])tot[x]-=1.0l*p[x]*l[x]/(X[x]+l[x])/(X[x]-1+l[x]),--X[x],++t;
			tot[x]+=1.0l*p[x]/(l[x]-1)-1.0l*p[x]*l[x]/(X[x]+l[x])/(X[x]-1+l[x]),tot[x]=tot[x]/l[x]*(l[x]-1),ans+=tot[x],--l[x];
		}
		Insert(0,x),Insert(1,x);
		if(ms[0].size())pr=*(--ms[0].end()),tot[pr.second]-=pr.first,ans-=pr.first,Erase(0,pr.second),Erase(1,pr.second),--X[pr.second],Insert(0,pr.second),Insert(1,pr.second),++t;
		for(;t && ms[1].size();--t)ans+=(pr=*ms[1].begin()).first,tot[pr.second]+=pr.first,Erase(0,pr.second),Erase(1,pr.second),++X[pr.second],Insert(0,pr.second),Insert(1,pr.second);
		printf("%.9Lf\n",ans);
	}
	return 0;
}