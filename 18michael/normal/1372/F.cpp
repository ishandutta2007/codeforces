#include<bits/stdc++.h>
using namespace std;
int n;
int a[200002];
typedef pair<int,int> P;
P tmp;
set<P> s;
set<P>::iterator it;
inline P query(int l,int r)
{
	printf("? %d %d\n",max(l,1),min(r,n)),fflush(stdout),scanf("%d%d",&l,&r);
	return P(l,r);
}
inline void cover(int l,int r,int x)
{
	for(int i=l;i<=r;++i)a[i]=x;
}
inline void solve(int l,int r)
{
	if(l>r)return ;
	P p=query(l,r);
	int L,R;
	if((*(it=s.lower_bound(P(p.first,0)))).first!=p.first)
	{
		for(int i=max((it==s.begin()? 0:(*(--it)).second+p.second),l);;i+=p.second)
		{
			tmp=query(i,i),s.insert(P(tmp.first,i));
			if(tmp.first==p.first)break;
		}
		it=s.lower_bound(P(p.first,0));
	}
	if((tmp=query((*it).second-p.second+1,(*it).second)).first==p.first)L=(*it).second-tmp.second+1,R=(*it).second-tmp.second+p.second;
	else tmp=query((*it).second,(*it).second+p.second-1),L=(*it).second+tmp.second-p.second,R=(*it).second+tmp.second-1;
	cover(L,R,p.first),solve(l,L-1),solve(R+1,r);
}
int main()
{
	scanf("%d",&n),solve(1,n),printf("!");
	for(int i=1;i<=n;++i)printf(" %d",a[i]);
	return 0&fflush(stdout);
}