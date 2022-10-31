#include<cstdio>
#include<vector>
#define N 100100
using namespace std;
//6: impossible 5:full and bound 4:full and one side 3: full 2: one side two row 1:one row 0: chain
bool vis[N];
vector<int> g[N];
int DFS(int u){
	vis[u]=true;
	int cnt[7]={};
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v]) continue;
		cnt[DFS(v)]++;
	}
	if(cnt[6]||cnt[5]) return 6;
	else if(cnt[4]){
		if(cnt[3]||cnt[2]||cnt[1]||cnt[0]>1) return 6;
		else if(cnt[0]==1) return 5;
		else return 4;
	}
	else if(cnt[3]){
		if(cnt[3]>=2||cnt[2]||cnt[1]||cnt[0]>2) return 6;
		else if(cnt[0]==2) return 5;
		else return 4;
	}
	else{
		if(cnt[2]>2) return 6;
		else if(cnt[2]==2) return 3;
		else if(cnt[2]==1) return 2;
		else{
			if(cnt[1]) return 2;
			else{
				if(cnt[0]<=1) return 0;
				else if(cnt[0]==2) return 1;
				else return 2;
			}
		}
	}
}
int main(){
	int n,i,x,y;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if(DFS(1)<6) puts("Yes");
	else puts("No");
	return 0;
}