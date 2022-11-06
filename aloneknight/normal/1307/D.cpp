#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005,inf=1e9;
int n,m,k,id[N],d[N][2];
vector<int>g[N];
inline void bfs(int S,int o)
{
	queue<int>Q;Q.push(S);d[S][o]=0;
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		for(int y:g[x])if(d[y][o]>d[x][o]+1){d[y][o]=d[x][o]+1;Q.push(y);}
	}
}
inline bool cmp(int a,int b){return d[a][0]-d[a][1]<d[b][0]-d[b][1];}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)scanf("%d",&id[i]);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	for(int i=1;i<=n;i++)d[i][0]=d[i][1]=inf;
	bfs(1,0);bfs(n,1);sort(id+1,id+k+1,cmp);
	int ans=0,mx=d[id[1]][0];
	for(int i=2;i<=k;i++){ans=max(ans,mx+d[id[i]][1]+1);mx=max(mx,d[id[i]][0]);}
	printf("%d\n",min(d[n][0],ans));
	return 0;
}