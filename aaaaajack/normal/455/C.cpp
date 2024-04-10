#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define N 300100
using namespace std;
vector<int> g[N];
bool visit[N]={},v2[N]={};
int fa[N],dis[N],rec[N]={};
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void uni(int x,int y){
	if(find(x)==find(y)) return;
	int dx=dis[find(x)],dy=dis[find(y)];
	dis[find(x)]=max(max(dx,dy),(dx+1)/2+(dy+1)/2+1);
	fa[find(y)]=find(x);
}
int main(){
	int i,j,n,m,q,x,y,fpt,t;
	scanf("%d%d%d",&n,&m,&q);
	while(m--){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(i=1;i<=n;i++){
		if(visit[i]) continue;
		queue<int> que;
		que.push(i);
		while(!que.empty()){
			int now=que.front();
			que.pop();
			fa[now]=i;
			fpt=now;
			visit[now]=true;
			for(j=0;j<g[now].size();j++){
				if(visit[g[now][j]]) continue;
				que.push(g[now][j]);
			}
		}
		que.push(fpt);
		while(!que.empty()){
			int now=que.front();
			que.pop();
			dis[i]=rec[now];
			v2[now]=true;
			for(j=0;j<g[now].size();j++){
				if(v2[g[now][j]]) continue;
				rec[g[now][j]]=rec[now]+1;
				que.push(g[now][j]);
			}
		}
	}
	while(q--){
		scanf("%d",&t);
		if(t==1){
			scanf("%d",&x);
			printf("%d\n",dis[find(x)]);
		}
		else{
			scanf("%d%d",&x,&y);
			uni(x,y);
		}
	}
	return 0;
}