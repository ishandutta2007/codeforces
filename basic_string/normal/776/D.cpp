#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int u[N],v[N],a[N],f[N],b[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void mg(int x,int y){
	int u=gf(x),v=gf(y);
	if(u!=v){
		f[u]=v;
		if(b[u]==1){
			if(b[v]==-1)puts("NO"),exit(0);
			b[v]=1;
		}
		if(b[u]==-1){
			if(b[v]==1)puts("NO"),exit(0);
			b[v]=-1;
		}
	}
}
int main(){
	int n,m,i,j,k,bu,bv;
	scanf("%d%d",&n,&m),iota(f+1,f+m*2+1,1); 
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=m;++i){
		scanf("%d",&k);
		while(k--)if(scanf("%d",&j),u[j])v[j]=i;else u[j]=i;
	}
	for(i=1;i<=n;++i)if(a[i]){
		if(v[i])mg(u[i],v[i]),mg(u[i]+m,v[i]+m);
		else if(u[i])b[u[i]+m]=1,b[u[i]]=-1;
	}else{
		if(v[i])mg(u[i],v[i]+m),mg(u[i]+m,v[i]);
		else if(u[i])b[u[i]]=1,b[u[i]+m]=-1;
		else puts("NO"),exit(0);
	}
	for(i=1;i<=m;++i)if(gf(i)==gf(i+m)||(b[gf(i)]==1&&b[gf(i+m)]==1)||(b[gf(i)]==-1&&b[gf(i+m)]==-1))puts("NO"),exit(0);
	for(i=1;i<=n;++i){
		bu=bv=0;
		if(b[gf(u[i])]==1||b[gf(u[i]+m)]==-1)bu=1;
		if(b[gf(u[i])]==-1||b[gf(u[i]+m)]==1)bu=-1;
		if(b[gf(v[i])]==1||b[gf(v[i]+m)]==-1)bv=1;
		if(b[gf(v[i]+m)]==-1||b[gf(v[i])]==1)bv=-1;
		if(a[i]&&((bu==1&&bv==-1)||(bu==-1&&bv==1)))puts("NO"),exit(0);
		if(!a[i]&&((bu==1&&bv==1)||(bu==-1&&bv==-1)))puts("NO"),exit(0);
		if(a[i]&&(gf(u[i])==gf(v[i]+m))&&(gf(v[i])==gf(u[i]+m)))puts("NO"),exit(0);
		if(!a[i]&&(gf(u[i])==gf(v[i]))&&(gf(u[i]+m)==gf(v[i]+m)))puts("NO"),exit(0);
	}
	puts("YES");
	return 0;
}