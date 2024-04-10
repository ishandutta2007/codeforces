#include<bits/stdc++.h>
using namespace std;
const int N=50009;
int a[N],d[N],fa[N],tp[N],f[N][259],w[259],v[259],c[N][2],id;
basic_string<int>g[N];
void ins(int o){for(int i=7,j,x=0;~i;x=c[x][j],--i)if(!c[x][j=o>>i&1])c[x][j]=++id,c[id][0]=c[id][1]=0;}
int qry(int o){
	int i=7,j,x=0,u=0,s=0;
	for(;~i;u|=j<<i,--i)if(c[x][!(j=o>>i&1)])x=c[x][j=!j],s|=1<<i;else x=c[x][j];
	return s<<8|w[u];
}
void dfs(int x,int y){
	d[x]=d[y]+1,fa[x]=y;
	for(int i:g[x])if(i!=y)dfs(i,x);
	if(d[x]<256)return;
	int i=x,j;
	c[0][0]=c[0][1]=id=0,memset(w,0,sizeof w);
	for(;d[x]-d[i]<256;i=fa[i])if(j=a[i]/256,w[j]=max(w[j],d[x]-d[i]^a[i]&255),v[j]!=x)v[j]=x,ins(j);
	for(tp[x]=i,i=0;i<256;++i)f[x][i]=qry(i);
}
int main(){
	int n,q,i,j,k,w;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<n;++i)scanf("%d%d",&j,&k),g[j]+=k,g[k]+=j;
	for(dfs(1,0);q--;printf("%d\n",w)){
		scanf("%d%d",&i,&j),k=w=0;
		while(d[j]-d[i]>256)w=max(w,f[j][k]),++k,j=tp[j];
		for(k<<=8;j!=fa[i];j=fa[j])w=max(w,a[j]^k),++k;
	}
	return 0;
}