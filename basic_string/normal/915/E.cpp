#include<bits/stdc++.h>
using namespace std;
struct P{
	int l,r;
	mutable int s;
	bool operator<(P a)const{return l<a.l;}
};
set<P>s;
#define it set<P>::iterator
it sp(int x){
	it p=s.lower_bound({x,0,0});
	if(p!=s.end()&&p->l==x)return p;
	--p;
	int l=p->l,r=p->r,v=p->s;
	return s.erase(p),s.insert({l,x-1,v}),s.insert({x,r,v}).first;
}
int main(){
	int n,m,l,r,k;
	it p,q,o;
	scanf("%d%d",&n,&m),s.insert({1,n,1});
	while(m--){
		scanf("%d%d%d",&l,&r,&k),q=sp(r+1),p=sp(l),--k;
		for(o=p;p!=q;++p)if(p->s!=k)k?(n+=p->r-p->l+1):(n-=p->r-p->l+1);
		s.erase(o,q),s.insert({l,r,k});
		printf("%d\n",n);
	}
	return 0;
}