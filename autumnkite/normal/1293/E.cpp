#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 3030
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,cnt,head[N],f[N][N],siz[N][N],root;
ll ans;
ll dp[N][N];
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int a,int b){
	cnt++;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs1(int u,int fa){
	f[root][u]=fa;
	siz[root][u]=1;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs1(v,u);
		siz[root][u]+=siz[root][v];
	}
}
ll dfs2(int u,int v){
	if(u==v)return 0;
	if(dp[u][v])return dp[u][v];
	return dp[u][v]=max(dfs2(u,f[u][v]),dfs2(v,f[v][u]))+siz[u][v]*siz[v][u];
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;++i){
		root=i;
		dfs1(i,0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=max(ans,dfs2(i,j));
		}
	}
	cout<<ans<<endl;
	return 0;
}