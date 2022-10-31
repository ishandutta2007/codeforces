#include<bits/stdc++.h>
#define N 3010
using namespace std;
int w[N][N],sz[N];
long long val[N][N],x[N];
vector<int> g[N];
void solve(int u,int p, bool full){
	w[u][0]=0;
	val[u][0]=x[u];
	sz[u]=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==p) continue;
		solve(v,u,false);
		for(int i=sz[u];i>=0;i--){
			for(int j=sz[v];j>=0;j--){
				if(j==0||w[u][i]+w[v][j]>w[u][i+j]
					|| (w[u][i]+w[v][j]==w[u][i+j]&&val[u][i]+val[v][j]>val[u][i+j])){
					w[u][i+j]=w[u][i]+w[v][j];
					val[u][i+j]=val[u][i]+val[v][j];
				}
			}
		}
		sz[u]+=sz[v];
	}
	sz[u]++;
	int nw[N];
	for(int i=0;i<sz[u];i++){
		nw[i+1]=w[u][i];
		if(val[u][i]>0) nw[i+1]++;
	}
	if(full){
		for(int i=1;i<=sz[u];i++) w[u][i]=nw[i];
	}
	else{
		for(int i=1;i<=sz[u];i++){
			if(nw[i]>w[u][i]){
				w[u][i]=nw[i];
				val[u][i]=0;
			}
			else if(nw[i]==w[u][i]&&val[u][i]<0) val[u][i]=0;
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,a,b;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
				w[i][j]=-1;
				val[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
			x[i]=a-x[i];
		}
		for(int i=1;i<n;i++){
			scanf("%d%d",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		solve(1,0,true);
		printf("%d\n",w[1][m]);
		for(int i=1;i<=n;i++) g[i].clear();
	}
}