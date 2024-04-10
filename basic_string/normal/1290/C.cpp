#include<bits/stdc++.h>
using namespace std;
const int N=6e5+3;
int a[N],u[N],v[N],f[N],sz[N],ans,b[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void mg(int x,int y){
	int u=gf(x),v=gf(y);
	if(u!=v)f[u]=v,sz[v]+=sz[u];
}
void mk(int x,int y){
	x=gf(x);
	if(y>0)ans+=sz[x];
	b[x]=y;
}
void clr(int x){
	x=gf(x);
	if(b[x]>0)ans-=sz[x];
	b[x]=0;
}
int main(){
	int n,m,i,j,k,bu,bv;
	scanf("%d%d",&n,&m),iota(f+1,f+m*2+1,1),fill(sz+1,sz+m+1,1);
	for(i=1;i<=n;++i)scanf("%1d",a+i);
	for(i=1;i<=m;++i){
		scanf("%d",&k);
		while(k--)if(scanf("%d",&j),u[j])v[j]=i;else u[j]=i;
	}
	for(i=1;i<=n;printf("%d\n",ans),++i)if(a[i]){
		if(v[i]){
			bu=max(b[gf(u[i])],max(b[gf(v[i])],1));
			bv=max(b[gf(u[i]+m)],max(b[gf(v[i]+m)],1));
			if(min(b[gf(u[i])],b[gf(v[i])])==-1)bv=2,bu=0;
			else if(min(b[gf(u[i]+m)],b[gf(v[i]+m)])==-1)bu=2,bv=0;
			clr(u[i]),clr(v[i]),clr(u[i]+m),clr(v[i]+m); 
			mg(u[i]+m,v[i]+m),mg(u[i],v[i]);
			if(bu==2||(bv!=2&&sz[gf(v[i]+m)]>sz[gf(u[i])]))mk(u[i],bu),mk(v[i]+m,1-bu);
			else mk(v[i]+m,bv),mk(u[i],1-bv);
		}else if(u[i])clr(u[i]),clr(u[i]+m),mk(u[i],-1),mk(u[i]+m,2);
	}else{
		if(v[i]){
			bu=max(b[gf(u[i])],max(b[gf(v[i]+m)],1)),bv=max(b[gf(u[i]+m)],max(b[gf(v[i])],1));
			if(min(b[gf(u[i])],b[gf(v[i]+m)])==-1)bv=2,bu=0;
			else if(min(b[gf(u[i]+m)],b[gf(v[i])])==-1)bu=2,bv=0;
			clr(u[i]),clr(v[i]),clr(u[i]+m),clr(v[i]+m);
			mg(u[i]+m,v[i]),mg(u[i],v[i]+m);
			if(bu==2||(bv!=2&&sz[gf(v[i])]>sz[gf(u[i])]))mk(u[i],bu),mk(v[i],1-bu);
			else mk(v[i],bv),mk(u[i],1-bv);
		}else clr(u[i]),clr(u[i]+m),mk(u[i]+m,-1),mk(u[i],2);
	}
	return 0;
}