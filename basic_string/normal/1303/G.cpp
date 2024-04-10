#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=150009;
namespace T{
	ll a[N],b[N];
	int s[N<<2],u,t;
	ll f(int x,int o){return b[o]+a[o]*x;}
	void build(int k,int l,int r){
		s[k]=0;
		if(l==r)return;
		int m=l+r>>1;
		build(k<<1,l,m),build(k<<1|1,m+1,r);
	}
	void upd(int k,int l,int r,int t){
		if(l==r){
			if(f(l,t)>f(l,s[k]))s[k]=t;
			return;
		}
		int m=l+r>>1;
		if(f(m,t)>f(m,s[k]))swap(s[k],t);
		if(f(l,t)>f(l,s[k]))upd(k<<1,l,m,t);
		else if(f(r,t)>f(r,s[k]))upd(k<<1|1,m+1,r,t); 
	}
	ll qry(int k,int l,int r){
		if(l==r)return f(u,s[k]);
		int m=l+r>>1;
		return max(f(u,s[k]),u<=m?qry(k<<1,l,m):qry(k<<1|1,m+1,r));
	}
}
ll v[N],ans;
int n,sz[N],mx[N],d[N],he[N],to[N<<1],ne[N<<1],rt,st[N],m;
bool b[N];
void getr(int x,int y){
	sz[x]=1,mx[x]=0;
	for(int i=he[x],j;i;i=ne[i])if(!b[j=to[i]]&&j!=y){
		getr(j,x),sz[x]+=sz[j];
		if(mx[x]<sz[j])mx[x]=sz[j]; 
	}
	if((mx[x]=max(mx[x],n-sz[x]))<mx[rt])rt=x;
}
void getd(int x,int y){
	m=max(m,d[x]=d[y]+1),sz[x]=1;
	for(int i=he[x],j;i;i=ne[i])if(!b[j=to[i]]&&j!=y)getd(j,x),sz[x]+=sz[j];
}
void qry(int x,int y,ll u,ll w){
	u+=v[x],w+=u,T::u=d[x],ans=max(ans,w+T::qry(1,1,m));
	for(int i=he[x],j;i;i=ne[i])if(!b[j=to[i]]&&j!=y)qry(j,x,u,w);
}
void upd(int x,int y,ll u,ll w){
	u+=v[x],w+=v[x]*(d[x]-1),T::a[++T::t]=u,T::b[T::t]=w,T::upd(1,1,m,T::t);
	for(int i=he[x],j;i;i=ne[i])if(!b[j=to[i]]&&j!=y)upd(j,x,u,w);
}
void calc(int x){
	int t=0,i=he[x];
	m=0,getd(x,0),T::build(1,1,m),T::t=0;
	for(;i;i=ne[i])if(!b[to[i]])st[++t]=to[i],qry(st[t],x,v[x],v[x]),upd(st[t],x,0,0);
	T::build(1,1,m),T::t=0;
	while(t)qry(st[t],x,v[x],v[x]),upd(st[t],x,0,0),--t;
}
void work(int x){
	calc(x),b[x]=1;
	for(int i=he[x],j;i;i=ne[i])if(!b[j=to[i]]&&sz[j]>2)n=mx[rt=0]=sz[j],getr(j,0),work(rt);
}
int main(){
	int i,j,k,t=0;
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d",&j,&k);
		ne[++t]=he[j],to[t]=k,he[j]=t;
		ne[++t]=he[k],to[t]=j,he[k]=t;
	}
	for(i=1;i<=n;++i)scanf("%lld",v+i);
	if(n==2)return printf("%lld",v[1]+v[2]+max(v[1],v[2])),0; 
	mx[0]=n,getr(1,0),work(rt),printf("%lld",ans);
	return 0;
}