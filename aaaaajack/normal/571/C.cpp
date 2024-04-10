#include<cstdio>
#include<queue>
#define M 200100
#define N 200100
using namespace std;
int val[M],deg[N];
int to[M<<1];
vector<int> g[M],cl[N];
bool in[N],used[M];
int pos[M][3];
void add_edge(int x,int y,int e){
	g[x].push_back(e<<1);
	to[e<<1]=y;
	g[y].push_back(e<<1|1);
	to[e<<1|1]=x;
	deg[x]++;
	deg[y]++;
}
void go(int u){
	while(u){
		int v=0;
		for(int i=0;i<g[u].size();i++){
			if(!used[g[u][i]>>1]){
				in[u]=true;
				val[g[u][i]>>1]=g[u][i]&1;
				used[g[u][i]>>1]=true;
				v=to[g[u][i]];
				break;
			}
		}
		if(in[v]) return;
		else u=v;
	}
}
int main(){
	int n,m,k,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		while(k--){
			scanf("%d",&x);
			cl[i].push_back(x);
			if(x<0){
				if(pos[-x][0]) pos[-x][2]=i;
				else pos[-x][0]=i;
			}
			else{
				if(pos[x][1]) pos[x][2]=i;
				else pos[x][1]=i;
			}
		}
	}
	in[0]=true;
	queue<int> q;
	for(int i=1;i<=m;i++){
		if(!pos[i][0]) val[i]=1;
		else if(!pos[i][1]) val[i]=0;
		else val[i]=-1;
		if(val[i]>=0){
			if(!in[pos[i][0]]) q.push(pos[i][0]),in[pos[i][0]]=true;
			if(!in[pos[i][1]]) q.push(pos[i][1]),in[pos[i][1]]=true;
			if(!in[pos[i][2]]) q.push(pos[i][2]),in[pos[i][2]]=true;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<cl[u].size();i++){
			int x=cl[u][i];
			if(x<0&&val[-x]<0){
				val[-x]=1;
				if(!in[pos[-x][1]]){
					q.push(pos[-x][1]);
					in[pos[-x][1]]=true;
				}
			}
			else if(x>0&&val[x]<0){
				val[x]=0;
				if(!in[pos[x][0]]){
					q.push(pos[x][0]);
					in[pos[x][0]]=true;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(val[i]==-1){
			add_edge(pos[i][0],pos[i][1],i);
		}
	}
	bool wrong=false;
	for(int i=1;i<=n;i++){
		if(deg[i]==1&&!in[i]) q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			if(!used[g[u][i]>>1]){
				val[g[u][i]>>1]=g[u][i]&1;
				used[g[u][i]>>1]=true;
				in[u]=true;
				int v=to[g[u][i]];
				deg[v]--;
				if(!in[v]&&deg[v]==1) q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!in[i]){
			go(i);
			if(!in[i]) wrong=true;
		}
	}
	if(wrong) puts("NO");
	else{
		for(int i=1;i<=m;i++) if(val[i]==-1) val[i]=0;
		puts("YES");
		for(int i=1;i<=m;i++) printf("%d",val[i]);
		puts("");
	}
}