#include<bits/stdc++.h>
using namespace std;
const int N=3e5+3,M=6e5+3;
int he[N],to[M],ne[M],a[N],dfn[N],fa[N],id;
long long s[N];
void dfs(int x){
	int i=he[x],j,u,v;
	for(dfn[x]=++id;i;i=ne[i])if(!dfn[j=to[i]])fa[j]=x,dfs(j);
	else if(dfn[j]>dfn[x]){
		for(u=v=x;j!=x;j=fa[j])u=min(u,j),v=max(v,j);
		a[u]=min(a[u],v-1);
	}
}
int main(){
	int n,m,q,u,v,l,r,i,j,t=0;
	scanf("%d%d",&n,&m),memset(a,9,N*4);
	while(m--){
		scanf("%d%d",&i,&j);
		ne[++t]=he[i],to[t]=j,he[i]=t;
		ne[++t]=he[j],to[t]=i,he[j]=t;
	}
	for(i=1;i<=n;++i)if(!dfn[i])dfs(i);
	for(i=n;i;--i)a[i]=min(a[i],a[i+1]);
	for(i=1;i<=n;++i)s[i]=s[i-1]+a[i]-i+1;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&u,&v),l=u,r=v;
		while(l<=r){
			m=l+r>>1;
			if(a[m]>v)r=m-1;else l=m+1;
		}
		printf("%lld\n",s[r]-s[u-1]+(v-r)*1ll*(v-r+1)/2);
	}
	return 0;
}