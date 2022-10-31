#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=2005;
const int dx[]={0,0,1,1},dy[]={-1,0,-1,0};
int n,m,id1[N][N],id2[N][N],cid1,cid2,h[N*N],nxt[N*N],adj[N*N],mc[N*N],now,ans,t,vs[N*N];
char s[N][N];
il bool dfs(ct x){
	for(it i=h[x],j;i;i=nxt[i])
		if(vs[j=adj[i]]!=now){
			vs[j]=now;
			if(!mc[j]||dfs(mc[j])) return mc[j]=x,1;
		}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);it i,j;
	for(i=1;i<=n;++i)
		for(scanf("%s",s[i]+1),j=1;j<=m;++j)
			if(s[i][j]=='#'){
				++ans;
				if(s[i][j-1]=='#') id1[i][j]=++cid1,--ans;
				if(s[i-1][j]=='#') id2[i][j]=++cid2,--ans;
			}
	auto add = [&](ct u,ct v){nxt[++t]=h[u],h[u]=t,adj[t]=v;};
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(id1[i][j])
				for(it k=0,ti,tj;k<4;++k){
					ti=i+dx[k],tj=j+dy[k];
					if(id2[ti][tj]) add(id1[i][j],id2[ti][tj]);
				}
	for(i=1;i<=cid1;++i) ++now,ans+=dfs(i);
	printf("%d",ans);
	return 0;
}