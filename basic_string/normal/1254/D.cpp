#include<bits/stdc++.h>
using namespace std;
const int p=998244353,N=150009,M=300009,P=600009;
int dg[N],pr[N],pr2[N],he[N],to[M],ne[M],fa[N],d[N],sz[N],tp[N],sn[N],id[N],g[N],ct;
int u,v,s[P];
int qp(long long a,int b,int p){
	register long long r=1;
	while(b){
		if(b&1)r=r*a%p;
		a=a*a%p,b>>=1;
	}
	return r;
}
void dfs1(int x,int y){
	d[x]=d[y]+1,sz[x]=1,fa[x]=y;
	for(register int i=he[x],j;i;i=ne[i]){
		j=to[i];
		if(j!=y){
			dfs1(j,x),sz[x]+=sz[j];
			if(sz[j]>sz[sn[x]])sn[x]=j;
		}
	}
}
void dfs2(int x,int y){
	tp[x]=y,id[x]=++ct;
	if(!sn[x])return;
	dfs2(sn[x],y);
	for(register int i=he[x],j;i;i=ne[i]){
		j=to[i];
		if(j!=fa[x]&&j!=sn[x])dfs2(j,j);
	}
}
void upd(int k,int l,int r){
	if(l==r){
		s[k]=(s[k]+v)%p;
		return;
	}
	register int m=l+r>>1,a=k<<1,b=a|1;
	if(u<=m)upd(a,l,m);else upd(b,m+1,r);
	s[k]=(s[a]+s[b])%p;
}
int qry(int k,int l,int r){
	if(u<=l&&r<=v)return s[k];
	register int m=l+r>>1,s=0;
	if(u<=m)s=qry(k<<1,l,m);
	if(m<v)s+=qry(k<<1|1,m+1,r);
	return s%p;
}
int get(int x){
	register int s=0;
	while(tp[x]!=1)u=id[tp[x]],v=id[x],s=(s+qry(1,1,ct))%p,x=fa[tp[x]];
	u=1,v=id[x],s=(s+qry(1,1,ct))%p;
	return s;
}
int get2(int j){
	register int s=0;
	while(j)s=(s+g[pr[j]]*1ll*sz[pr2[j]])%p,j=pr[j];
	return s;
}
void dfs(int x){
	pr[x]=u,pr2[x]=v;
	if(dg[x]>100){
		u=x;
		for(register int i=he[x];i;i=ne[i]){
			if(to[i]!=fa[x])u=x,v=to[i],dfs(v);
		}
		return;
	}
	register int p=u,q=v;
	for(register int i=he[x];i;i=ne[i]){
		if(to[i]!=fa[x])u=p,v=q,dfs(to[i]);
	}
}
int main(){
	register int n,q,o,i,j,k,t=0,s=0;
	scanf("%d%d",&n,&q),o=qp(n,p-2,p);
	for(i=1;i<n;++i){
		scanf("%d%d",&j,&k),++dg[j],++dg[k];
		ne[++t]=he[j],to[t]=k,he[j]=t;
		ne[++t]=he[k],to[t]=j,he[k]=t;
	}
	dfs1(1,0),dfs2(1,1),u=v=0,dfs(1);
	while(q--){
		scanf("%d%d",&i,&j);
		if(i==1){
			scanf("%d",&k),s=(s+sz[j]*1ll*k)%p,u=id[j],v=(n-sz[j])*1ll*k%p,upd(1,1,n);
			if(dg[j]>100)g[j]=(g[j]+k)%p;
			else for(i=he[j];i;i=ne[i]){
				if(to[i]!=fa[j])u=id[to[i]],v=(-sz[to[i]]*1ll*k)%p,upd(1,1,n);
			}
		}
		else printf("%d\n",((s+get(j)-get2(j))%p+p)*1ll*o%p);
	}
	return 0;
}