#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,M=2e5+3;
bool b[N];
int he[N],to[M],len[M],ne[M],f[3][N],g[3][N],h[2][N],p[N],fa[N],s[N];
void pre(int x,int y){
	if(b[x])f[0][x]=0,g[0][x]=x;
	for(int i=he[x],j,k,l;i;i=ne[i])if((j=to[i])!=y){
		fa[j]=x,pre(j,x),k=f[0][j]+len[i],l=p[j];
		if(k>f[0][x])f[2][x]=f[1][x],f[1][x]=f[0][x],f[0][x]=k,g[2][x]=g[1][x],g[1][x]=g[0][x],g[0][x]=l,h[1][x]=h[0][x],h[0][x]=j;
		else if(k>f[1][x])f[2][x]=f[1][x],f[1][x]=k,g[2][x]=g[1][x],g[1][x]=l,h[1][x]=j;
		else if(k>f[2][x])f[2][x]=k,g[2][x]=l;
	}p[x]=f[0][x]==f[1][x]?x:g[0][x];
}
void dp(int x,int u,int v,int w){
	if(b[x])if(f[0][x]>w)++s[p[x]],--s[fa[x]];else if(f[0][x]<w)++s[u],++s[x],--s[v],--s[fa[v]];
	for(int i=he[x],j,k,l;i;i=ne[i])if((j=to[i])!=fa[x]){
		if(j==h[0][x])k=f[1][x],l=f[1][x]==f[2][x]?x:g[1][x];
		else if(j==h[1][x])k=f[0][x],l=f[0][x]==f[2][x]?x:g[0][x];
		else k=f[0][x],l=p[x];
		if(k>w)dp(j,l,x,k+len[i]);
		else if(k==w)dp(j,x,x,k+len[i]);
		else dp(j,u,v,w+len[i]);
	}
}
void dfs(int x){for(int i=he[x],j;i;i=ne[i])if((j=to[i])!=fa[x])dfs(j),s[x]+=s[j];}
int main(){
	int n,m,i,j,k,l,t=0;
	scanf("%d%d",&n,&m),memset(f,-9,sizeof(f));
	for(i=1;i<=m;++i)scanf("%d",&j),b[j]=1;
	for(i=1;i<n;++i){
		scanf("%d%d%d",&j,&k,&l);
		ne[++t]=he[j],to[t]=k,len[t]=l,he[j]=t;
		ne[++t]=he[k],to[t]=j,len[t]=l,he[k]=t;
	}
	pre(1,0),dp(1,0,0,-1e9),dfs(1);
	for(i=1,j=k=0;i<=n;++i)if(!b[i])if(s[i]>j)j=s[i],k=1;else if(s[i]==j)++k;
	printf("%d %d\n",j,k);
	return 0;
}