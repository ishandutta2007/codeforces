#include<stdio.h>
#define it register int
#define ct const int
#define il inline
#define P 1000000007
const int N=1000005;
int h[N],nxt[N],adj[N],t,u,v,fa[N],x,d[N],k[N],b[N],top,st[N],n;
il void add(){nxt[++t]=h[u],h[u]=t,adj[t]=v,nxt[++t]=h[v],h[v]=t,adj[t]=u;}
il int ksm(it x,it L){it ans=1;while(L) L&1?ans=(0ll+ans)*x%P:0,x=(0ll+x)*x%P,L>>=1;return ans;}
il void dfs(ct x){
	st[++top]=x;
	for(it i=h[x],j;i;i=nxt[i]) if((j=adj[i])^fa[x]) fa[j]=x,dfs(j);
}
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%d",&n);it i,x,inv;
	for(i=1;i<n;++i) scanf("%d%d%d",&u,&v,&x),++u,++v,add(),++k[u],++k[v],++d[u],++d[v],b[u]+=x,b[v]+=x;
    dfs(1);
	for(i=n;i>=2;--i)
		if(d[x=st[i]]^1)
			inv=ksm(k[x],P-2),k[fa[x]]+=P-inv,k[fa[x]]=(k[fa[x]]>=P?k[fa[x]]-P:k[fa[x]]),b[fa[x]]=(b[fa[x]]+(0ll+b[x])*inv)%P;
	x=(0ll+b[1])*ksm(k[1],P-2)%P;
    printf("%d",x);
	return 0;
}