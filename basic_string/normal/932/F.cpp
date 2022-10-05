#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,M=2e5+3;
#define ll long long
int a[N],b[N],he[N],to[M],ne[M],lc[N],rc[N],s[N],rt[N],u;
ll f[N];
#define g(t,x) (b[t]*1ll*(x)+f[t])
void upd(int&k,int l,int r){
	if(k){
		int m=l+r>>1;
		if(g(s[u],m)<g(s[k],m))swap(s[u],s[k]);
		if(l<r)b[s[u]]<b[s[k]]?upd(rc[k],m+1,r):upd(lc[k],l,m);
	}else k=u,lc[k]=rc[k]=0;
}
ll qry(int k,int l,int r){
	if(!k)return 4e18;
	int m=l+r>>1;
	return min(g(s[k],u),u>m?qry(rc[k],m+1,r):qry(lc[k],l,m));
}
void mg(int&k,int t,int l,int r){
	if(!k||!t)k|=t;
	else if(l<r){
		int m=l+r>>1;
		mg(lc[k],lc[t],l,m),mg(rc[k],rc[t],m+1,r),u=t,upd(k,l,r);
	}else if(g(s[t],l)<g(s[k],l))k=t;
}
void dfs(int x,int y){
	int i=he[x],j;
	if(ne[i]||x==1){
		for(;i;i=ne[i])if((j=to[i])!=y)dfs(j,x),mg(rt[x],rt[j],-N,N);
		u=a[x],f[x]=qry(rt[x],-N,N);
	}
	u=s[x]=x,upd(rt[x],-N,N);
} 
int main(){
	int n,i,j,k,t=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i)scanf("%d",b+i);
	for(i=1;i<n;++i){
		scanf("%d%d",&j,&k);
		ne[++t]=he[j],to[t]=k,he[j]=t;
		ne[++t]=he[k],to[t]=j,he[k]=t;
	}
	dfs(1,0);
	for(i=1;i<=n;++i)printf("%lld ",f[i]); 
	return 0;
}