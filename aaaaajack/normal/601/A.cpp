#include<cstdio>
#include<cstring>
#include<utility>
#include<queue>
#define N 410
using namespace std;
int con[N][N];
int dis[N];
int main(){
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		con[x][y]=con[y][x]=1;
	}
	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	q.push(1);
	dis[1]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(i==u||con[u][i]==con[1][n]) continue;
			if(dis[u]+1<dis[i]){
				dis[i]=dis[u]+1;
				q.push(i);
			}
		}
	}
	if(dis[n]==0x3f3f3f3f) dis[n]=-1;
	printf("%d\n",dis[n]);
	return 0;
}