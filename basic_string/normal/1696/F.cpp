#include<bits/stdc++.h>
using namespace std;
enum{N=109};
char s[N];
bool b[N][N][N],vis[N];
int fa[N],d[N];
queue<int>q;
bitset<N>u[N][N],v[N][N],w;
basic_string<int>e[N];
void dfs(int x,int y){
	d[x]=d[y]+1;
	for(int i:e[x])if(i^y)dfs(i,x);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,x,y;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)e[i]={};
		for(i=1;i<n;++i)for(j=i+1;j<=n;++j){
			cin>>(s+1);u[i][j].reset(),v[i][j].reset();
			for(k=1;k<=n;++k)if((b[i][j][k]=b[j][i][k]=(s[k]=='1')))v[i][j][k]=1;else u[i][j][k]=1;
		}
		if(n==2){x=1,y=2;goto gg;}
		for(x=1;x<=n;++x){
			w.set();
			for(i=1;i<n;++i)for(j=i+1;j<=n;++j)if(i!=x&&j!=x){
				if(b[i][j][x])w&=v[i][j];else w&=u[i][j];
			}
			for(y=w._Find_first();y!=N;y=w._Find_next(y))if(y!=x){
				for(i=1;i<=n;++i)if(b[i][x][y])goto gg;
			}
		}
		cout<<"No\n";continue;
		gg:;
		memset(vis,0,sizeof vis),vis[x]=vis[y]=1,fa[x]=y,fa[y]=x,q.push(x),q.push(y),e[x]+=y,e[y]+=x;
		while(q.size()){
			i=q.front(),q.pop();
			for(j=1;j<=n;++j)if(!vis[j]&&b[j][fa[i]][i])fa[j]=i,q.push(j),vis[j]=1,e[i]+=j,e[j]+=i;
		}
		for(i=1;i<=n;++i){
			dfs(i,0);
			for(j=1;j<n;++j)for(k=j+1;k<=n;++k)if((d[j]==d[k])!=b[j][k][i]){cout<<"No\n";goto g2;}
		}
		cout<<"Yes\n";
		for(i=1;i<=n;++i)for(int o:e[i])if(i<o)cout<<i<<' '<<o<<'\n';
		g2:;
	}
}