#include<cstdio>
#include<utility>
#include<vector>
#define F first
#define S second
#define N 100100
#define Q 1000000007
using namespace std;
int f[N],sz[N];
bool vis[N],col[N];
vector<int> g[N];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void uni(int x,int y){
	if(find(x)!=find(y)) f[f[x]]=f[y];
}
bool DFS(int u,bool c){
	vis[u]=true;
	col[u]=c;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v]){
			if(col[v]==c){
				return false;
			}
		}
		else{
			if(!DFS(v,!c)) return false;
		}
	}
	return true;
}
int main(){
	int n,m;
	long long ans=1;
	vector<pair<int,int> > hate;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=0;i<m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(z) uni(x,y);
		else hate.push_back(make_pair(x,y));
	}
	for(int i=0;i<hate.size();i++){
		int x=find(hate[i].F),y=find(hate[i].S);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(f[i]==i&&!vis[i]){
			if(!DFS(i,true)){
				ans=0;
				break;
			}
			else ans=(ans<<1)%Q;
		}
	}
	printf("%I64d\n",ans&1?(ans+Q)>>1:ans>>1);
	return 0;
}