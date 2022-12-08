#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e2+5;
const ll mod = 998244353;

int n,m;
int d[N][N];
ll f[N][N];
vector<int> g[N];
ll ans[N][N];
bool vis[N];

void dfs(int x,int y,int f){
    vis[x]=1;
	for(int t=0;t<g[x].size();++t)
    if(d[y][g[x][t]]+1==d[y][x]){
        dfs(g[x][t],y,f);
    }
}

int main(){
	scanf("%d%d",&n,&m);
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;++i)d[i][i]=0,f[i][i]=1;
	for(int i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		d[x][y]=1;d[y][x]=1;
		f[x][y]=f[y][x]=1;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int k=1;k<=n;++k)
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	if(i!=j&&i!=k&&k!=j){
		if(d[i][k]+d[k][j]<d[i][j]){
			d[i][j]=d[i][k]+d[k][j];
			f[i][j]=f[i][k]*f[k][j];
			f[i][j]=min(f[i][j],2ll);
		}
		else if(d[i][k]+d[k][j]==d[i][j]){
			f[i][j]+=f[i][k]*f[k][j];
			f[i][j]=min(f[i][j],2ll);
		}
	}
	for(int i=1;i<=n;++i)
	for(int j=i;j<=n;++j)
	if(f[i][j]==1){
		for(int k=1;k<=n;++k)vis[k]=0;
		vis[i]=vis[j]=1;
		ans[i][j]=1;
		dfs(i,j,0);
		for(int k=1;k<=n;++k)
		if(!vis[k]){
			int c=0;
			for(int t=0;t<g[k].size();++t){
				if(d[i][k]==d[i][g[k][t]]+1&&d[j][k]==d[j][g[k][t]]+1)c++;
			}
			(ans[i][j]*=c)%=mod;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i<=j)printf("%d ",ans[i][j]);
			else printf("%d ",ans[j][i]);
		}
		printf("\n");
	}
}
/*
*/