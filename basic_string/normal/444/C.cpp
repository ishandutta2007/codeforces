#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
ll s[N],t[N];
int u,v,w;
void upd(int k,int l,int r){
	if(u<=l&&r<=v){s[k]+=w*1ll*(r-l+1),t[k]+=w;return;}
	int m=l+r>>1,a=k<<1,b=a|1;
	t[a]+=t[k],t[b]+=t[k],s[a]+=t[k]*(m-l+1),s[b]+=t[k]*(r-m),t[k]=0;
	if(u<=m)upd(a,l,m);
	if(m<v)upd(b,m+1,r);
	s[k]=s[a]+s[b];
}
ll qry(int k,int l,int r){
	if(u<=l&&r<=v)return s[k];
	int m=l+r>>1,a=k<<1,b=a|1;
	t[a]+=t[k],t[b]+=t[k],s[a]+=t[k]*(m-l+1),s[b]+=t[k]*(r-m),t[k]=0;
	ll z=u<=m?qry(a,l,m):0;
	if(m<v)z+=qry(b,m+1,r);
	return z;
}
struct P{
	int l,r,s;
	inline bool operator<(P a)const{return l<a.l||(l==a.l&&r<a.r);}
}st[5];
set<P>a;
int main(){
	int n,m,i,l,r,x,t;
	set<P>::iterator it,it2;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)a.insert({i,i,i});
	while(m--){
		scanf("%d%d%d",&i,&l,&r);
		if(i==1){
			scanf("%d",&x),it=--a.upper_bound({l,n+1,0}),t=0;
			u=l,v=min(r,it->r),w=abs(x-it->s),upd(1,1,n),it2=it;
			if(it->l<l)st[++t]={it->l,l-1,it->s};
			if(it->r>r){
				st[++t]={r+1,it->r,it->s},a.erase(it2);
				goto gg;
			}
			++it,a.erase(it2);
			while(it!=a.end()&&it->r<=r)u=it->l,v=it->r,w=abs(x-it->s),upd(1,1,n),it2=it,++it,a.erase(it2);
			if(it!=a.end()&&it->l<=r)u=it->l,v=r,w=abs(x-it->s),st[++t]={r+1,it->r,it->s},upd(1,1,n),it2=it,++it,a.erase(it2);
			gg:;
			a.insert({l,r,x});
			while(t)a.insert(st[t--]);
		}else u=l,v=r,printf("%lld\n",qry(1,1,n));
	}
	return 0;
}