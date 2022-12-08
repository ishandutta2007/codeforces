#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
 
int n,m,k,ans;
int a[N],d[2][N];
vector<int>g[N];
 
void bfs(int S,int *d){
	queue<int>q;
	d[S]=0;
	q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<g[x].size();++i)
		if(!d[g[x][i]]&&g[x][i]!=S){
			d[g[x][i]]=d[x]+1;
			q.push(g[x][i]);
		}
	}
}
 
bool cmp(int x,int y){
	return d[0][x]-d[1][x]<d[0][y]-d[1][y];
}
 
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i)scanf("%d",&a[i]);
	for(int i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	bfs(1,d[0]);
	bfs(n,d[1]);
	sort(a+1,a+k+1,cmp);
	int mx=0,ans=0;
	for(int i=1;i<=k;++i){
		int x=a[i];
		if(i!=1)ans=max(ans,d[1][x]+mx+1);
		mx=max(mx,d[0][x]);
	}
	cout<<min(ans,d[0][n])<<endl;
}