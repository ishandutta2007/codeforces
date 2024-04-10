#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#define N 100005
using namespace std;
struct edge{int next,to;}e[N*2];
int dep[N],size[N],head[N],inn[N],out[N],f[N][20];
int n,m,x,y,u,v,r,tot,tim,dis,mid;
inline void ins(int x,int y){
	e[++tot].to=y;
	e[tot].next=head[x];
	head[x]=tot;
}
void dfs(int x,int fa){
	size[x]=1;
	inn[x]=++tim;
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			size[x]+=size[e[i].to];
		}
	out[x]=++tim;
}
inline bool jud(int x,int y){return inn[x]<=inn[y]&&out[x]>=out[y];}
inline int lca(int x,int y){
	if (jud(x,y)) return x;
	if (jud(y,x)) return y;
	int k=x;
	for (int i=19;i>=0;i--)
		if (!jud(f[k][i],y)) k=f[k][i];
	return f[k][0];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		ins(x,y);
		ins(y,x);
	}
	dfs(1,0);
	f[1][0]=1;
	for (int i=1;i<20;i++)
		for (int j=1;j<=n;j++)
			f[j][i]=f[f[j][i-1]][i-1];
	scanf("%d",&m);
	while (m--){
		scanf("%d%d",&u,&v);
		r=lca(u,v);
		//printf("%d ",r);
		dis=dep[u]+dep[v]-2*dep[r];
		if (dis%2){
			printf("0\n");
			continue;
		}
		if (dis==0){
		    printf("%d\n",n);
		    continue;
		}
		if (dep[u]>dep[v]) swap(u,v);
		dis/=2;
		mid=v;
		for (int i=19;i>=0;i--)
			if ((dis>>i)%2) mid=f[mid][i];
		if (mid==r){
			for (int i=19;i>=0;i--)
				if (!jud(f[v][i],r)) v=f[v][i];
			for (int i=19;i>=0;i--)
				if (!jud(f[u][i],r)) u=f[u][i];
			printf("%d\n",n-size[u]-size[v]);
		}
		else{
			for (int i=19;i>=0;i--)
				if (!jud(f[v][i],mid)) v=f[v][i];
			printf("%d\n",size[mid]-size[v]);
		}
	}
}