#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rd (w=u,u=(u*7ll+13)%1000000007,w)
struct T{
	int l,r;
	mutable ll v;
	bool operator<(T a)const{return l<a.l;}
};
set<T>s;
vector<pair<ll,int>>v;
using it=set<T>::iterator;
ll qp(ll a,int b,int p){
	int r=1;
	for(a%=p;b;b>>=1,a=a*a%p)if(b&1)r=r*a%p;
	return r;
}
it sp(int x){
	it p=s.lower_bound({x,0,0});
	if(p!=s.end()&&p->l==x)return p;
	--p;
	int l=p->l,r=p->r;
	ll v=p->v;
	return s.erase(p),s.insert({l,x-1,v}),s.insert({x,r,v}).first;
}
void add(int l,int r,int x){
	it q=sp(r+1),p=sp(l);
	for(;p!=q;++p)p->v+=x;
}
void cov(int l,int r,int x){
	it q=sp(r+1),p=sp(l);
	s.erase(p,q),s.insert({l,r,x});
}
ll kth(int l,int r,int k){
	it q=sp(r+1),p=sp(l);
	for(v.clear();p!=q;++p)v.push_back({p->v,p->r-p->l+1});
	sort(v.begin(),v.end());
	for(auto o:v)if(k-=o.second,k<=0)return o.first;
}
int sum(int l,int r,int x,int y){
	it q=sp(r+1),p=sp(l);
	int w=0;
	for(;p!=q;++p)w=(w+(p->r-p->l+1)*qp(p->v,x,y))%y;
	return w;
}
int main(){
	int n,m,i,o,l,r,x,u,v,w;
	scanf("%d%d%d%d",&n,&m,&u,&v);
	for(i=1;i<=n;++i)s.insert({i,i,rd%v+1});
	while(m--){
		o=rd%4+1,l=rd%n+1,r=rd%n+1;
		if(l>r)swap(l,r);
		x=rd%(o==3?(r-l+1):v)+1;
		if(o==1)add(l,r,x);
		else if(o==2)cov(l,r,x);
		else if(o==3)printf("%lld\n",kth(l,r,x));
		else printf("%d\n",sum(l,r,x,rd%v+1));
	}
	return 0;
}