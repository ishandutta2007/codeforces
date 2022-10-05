#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+3,M=2e5+3,P=43;
bool b[N];
int he[N],to[M],ne[M],len[M],fa[N],p[P],f[23][N],dp[N];
ll g[23][N],d[P][N];
priority_queue<pair<ll,int> >pq;
struct E{
	int x,y,z;
	bool operator<(E a)const{return z<a.z;}
}e[N];
int gf(int x){return fa[x]==x?x:fa[x]=gf(fa[x]);}
void dfs(int x,int y){
	int i,j;
	dp[x]=dp[y]+1;
	for(i=0;i<20;++i)f[i+1][x]=f[i][f[i][x]],g[i+1][x]=g[i][f[i][x]]+g[i][x];
	for(i=he[x];i;i=ne[i])if((j=to[i])!=y){
		f[0][j]=x,g[0][j]=len[i],dfs(j,x);
	}
}
int main(){
	int n,m,q,i,j,k,l,t=0,tp=0;
	ll w,o;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	sort(e+1,e+m+1);
	for(i=1;i<=n;++i)fa[i]=i;
	for(i=1;i<=m;++i){
		if(gf(e[i].x)!=gf(e[i].y)){
			fa[gf(e[i].x)]=gf(e[i].y);
			ne[++t]=he[e[i].x],to[t]=e[i].y,len[t]=e[i].z,he[e[i].x]=t;
			ne[++t]=he[e[i].y],to[t]=e[i].x,len[t]=e[i].z,he[e[i].y]=t;
		}else{
			if(!b[e[i].x])b[e[i].x]=1,p[++tp]=e[i].x;
			if(!b[e[i].y])b[e[i].y]=1,p[++tp]=e[i].y;
		}
	}
	dfs(1,0),t=0,memset(he,0,n+1<<2);
	for(i=1;i<=m;++i){
		ne[++t]=he[e[i].x],to[t]=e[i].y,len[t]=e[i].z,he[e[i].x]=t;
		ne[++t]=he[e[i].y],to[t]=e[i].x,len[t]=e[i].z,he[e[i].y]=t;
	}
	for(i=1;i<=tp;++i){
		memset(b,0,n+1),memset(d[i],9,n+1<<3),d[i][p[i]]=0,pq.push({0,p[i]});
		while(!pq.empty()){
			j=pq.top().second,pq.pop();
			if(b[j])continue;
			for(b[j]=1,k=he[j];k;k=ne[k])if(!b[l=to[k]]&&d[i][l]>d[i][j]+len[k]){
				d[i][l]=d[i][j]+len[k],pq.push({-d[i][l],l});
			}
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&i,&j),w=1e18,o=0;
		for(k=1;k<=tp;++k)w=min(w,d[k][i]+d[k][j]);
		if(dp[i]<dp[j])swap(i,j);
		for(k=20;~k;--k)if(dp[f[k][i]]>=dp[j])o+=g[k][i],i=f[k][i];
		if(i!=j){
			for(k=20;~k;--k)if(f[k][i]!=f[k][j])o+=g[k][i]+g[k][j],i=f[k][i],j=f[k][j];
			o+=g[0][i]+g[0][j];
		}
		printf("%lld\n",min(w,o));
	}
	return 0;
}