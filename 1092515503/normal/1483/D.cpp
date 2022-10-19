#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q,id[610][610],d[360010],l[610][610],res;
ll g[610][610],dis[610][610];
bool ok[360010];
int main(){
	scanf("%d%d",&n,&m),memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;i++)g[i][i]=0;
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),g[x][y]=g[y][x]=z,id[x][y]=id[y][x]=i,d[i]=z;
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	scanf("%d",&q);
	for(int i=1,x,y,z;i<=q;i++)scanf("%d%d%d",&x,&y,&z),l[x][y]=l[y][x]=z;
	memset(dis,0xc0,sizeof(dis));
	for(int u=1;u<=n;u++)for(int A=1;A<=n;A++)for(int B=1;B<=n;B++)dis[u][B]=max(dis[u][B],l[A][B]-g[u][A]);
	for(int u=1;u<=n;u++)for(int B=1;B<=n;B++)for(int v=1;v<=n;v++)if(g[v][B]+d[id[u][v]]<=dis[u][B])ok[id[u][v]]=true;
	for(int i=1;i<=m;i++)res+=ok[i];
	printf("%d\n",res);
	return 0;
}