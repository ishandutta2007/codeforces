#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct P{
	int a,b,i;
	inline bool operator<(P x)const{return a<x.a;}
}p[N];
struct Q{
	int c,d,k,i;
	inline bool operator<(Q x)const{return c<x.c;}
}q[N];
int ans[N];
struct R{
	int d,k,i;
	inline bool operator<(R x)const{return d<x.d||(d==x.d&&i<x.i);}
};
multiset<R>s;
int main(){
	int n,m,i,j,k,l,t=1;
	set<R>::iterator it;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",&p[i].a,&p[i].b),p[i].i=i;
	scanf("%d",&m);
	for(i=1;i<=m;++i)scanf("%d%d%d",&q[i].c,&q[i].d,&q[i].k),q[i].i=i;
	sort(p+1,p+n+1),sort(q+1,q+m+1),q[m+1].c=2e9;
	for(i=1;i<=n;++i){
		while(q[t].c<=p[i].a)s.insert({q[t].d,q[t].k,q[t].i}),++t;
		it=s.upper_bound({p[i].b,0,0});
		if(it==s.end())return puts("NO"),0;
		ans[p[i].i]=it->i;
		if(it->k>1)s.insert({it->d,it->k-1,it->i});
		s.erase(it);
	}
	puts("YES");
	for(i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}