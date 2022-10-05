#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
using ll=long long;
struct P{
	int l,r,a;
	bool operator<(P a)const{return l<a.l;}
};
using it=set<P>::iterator;
int n,id;
set<P>st;
set<int>ps[N];
unordered_map<int,int>mp;
struct FW{
	ll t[N];
	void add(int x,int y){for(;x<=n;x+=x&-x)t[x]+=y;}
	void add(int l,int r,int y){add(l,y),add(r+1,-y);}
	ll sum(int x){ll r=0;for(;x;x-=x&-x)r+=t[x];return r;}
}A,B;
void add(int l,int r,int a,int w){
	if(!mp[a])mp[a]=++id,ps[id].insert(0),ps[id].insert(n+1);
	if(a=mp[a],w==-1)ps[a].erase(l),ps[a].erase(r);
	int x=*(--ps[a].lower_bound(l)),y=*ps[a].lower_bound(r),u=min(l-x,y-r),v=max(l-x,y-r),p=min(r-l+u+v,n);
	A.add(1,u,(r-l)*w),B.add(1,u,w);
	A.add(u+1,v,(r-l+u)*w);
	A.add(v+1,p,(r-l+u+v)*w),B.add(v+1,p,-w);
	if(w==1)ps[a].insert(l),ps[a].insert(r);
}
it sp(int x){
	it p=st.lower_bound({x,0,0});
	if(p!=st.end()&&p->l==x)return p;
	--p;
	int l=p->l,r=p->r,a=p->a,b=mp[a];
	return ps[b].insert(x-1),ps[b].insert(x),st.erase(p),st.insert({l,x-1,a}),st.insert({x,r,a}).first;
}
int main(){
	int m,i,j,k;
	it p,q,o;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&j),add(i,i,j,1),st.insert({i,i,j});
	while(m--){
		scanf("%d%d",&i,&j);
		if(i==1){
			scanf("%d%d",&k,&i),q=sp(k+1),p=sp(j);
			for(o=p;o!=q;++o)add(o->l,o->r,o->a,-1);
			st.erase(p,q),st.insert({j,k,i}),add(j,k,i,1);
		}else printf("%lld\n",A.sum(j)+B.sum(j)*j);
	}
	return 0;
}