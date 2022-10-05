#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3,M=2e6+3;
int s[M],p[N],w[N],x[N],y[N],o[N],z[N],f[N],st[N],c[N][2],id,dfn[N],ls[N],ct,u,v,g,ps[N];
bool b[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void mg(int x,int y){
	x=gf(x),y=gf(y);
	if(x!=y)f[x]=f[y]=++id,c[id][0]=x,c[id][1]=y;
}
void dfs(int x){
	dfn[x]=++ct,w[ct]=p[x];
	if(c[x][0])dfs(c[x][0]),dfs(c[x][1]);
	ls[x]=ct;
}
void build(int k,int l,int r){
	if(l==r){s[k]=w[l];return;}
	int m=l+r>>1;
	build(k*2,l,m),build(k*2+1,m+1,r),s[k]=max(s[k*2],s[k*2+1]);
}
int qry(int k,int l,int r){
	if(u<=l&&r<=v)return s[k];
	int m=l+r>>1,w=0;
	if(u<=m)w=qry(k*2,l,m);
	if(m<v)w=max(w,qry(k*2+1,m+1,r));
	return w;
}
void upd(int k,int l,int r){
	if(l==r){s[k]=0;return;}
	int m=l+r>>1;
	if(u<=m)upd(k*2,l,m);else upd(k*2+1,m+1,r);
	s[k]=max(s[k*2],s[k*2+1]);
}
int main(){
	int n,m,q,i,j,k,tp=0;
	scanf("%d%d%d",&n,&m,&q),id=n;
	for(i=1;i<=n;++i)scanf("%d",p+i),ps[p[i]]=i;
	for(i=1;i<=m;++i)scanf("%d%d",x+i,y+i);
	for(i=1;i<=q;++i){
		scanf("%d%d",o+i,z+i);
		if(o[i]==2)b[z[i]]=1;
	}
	for(i=1;i<N;++i)f[i]=i;
	for(i=1;i<=m;++i)if(!b[i])mg(x[i],y[i]);
	for(i=q;i;--i){
		if(o[i]==1)st[++tp]=gf(z[i]);
		else mg(x[z[i]],y[z[i]]);
	}
	for(i=1;i<=id;++i)if(f[i]==i)dfs(i);
	build(1,1,id);
	for(i=tp;i;--i){
		u=dfn[st[i]],v=ls[st[i]],printf("%d\n",g=qry(1,1,id));
		if(g)u=dfn[ps[g]],upd(1,1,id);
	}
	return 0;
}