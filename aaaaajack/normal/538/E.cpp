#include<cstdio>
#include<vector>
#define N 200100
using namespace std;
vector<int> g[N];
int DFS(int u,bool diff){
	if(g[u].empty()) return 1;
	int x=1023456789,y=0;
	for(int i=0;i<g[u].size();i++){
		if(diff) y+=DFS(g[u][i],!diff);
		else x=min(x,DFS(g[u][i],!diff));
	}
	return diff?y:x;
}
int main(){
	int n,x,y,i,m=0;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
	}
	for(i=1;i<=n;i++){
		if(g[i].empty()) m++;
	}
	printf("%d %d\n",m+1-DFS(1,false),DFS(1,true));
	return 0;
}