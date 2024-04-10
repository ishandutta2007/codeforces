#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int M=1000000007;
typedef long double lb;
int n,m,i,j,a[1005][1005],vis[1005][1005],k,c,vc[105],l,r,x,y,u,v,Q;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
struct str{
	int x,y;
}q[1000005];
vector<str> p[1000005];
short g[41][1005][1005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d %d",&n,&m,&c);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		{
			scanf("%d",&a[i][j]);
			p[a[i][j]].push_back((str){i,j});
		}
	for(int pc=1;pc<=c;++pc)
	{
		memset(vis,-1,sizeof(vis));
		memset(vc,0,sizeof(vc));
		r=0;
		l=1;
		for(j=1;j<=n;++j)
			for(k=1;k<=m;++k)
				if(a[j][k]==pc)
				{
					vis[j][k]=0;
					q[++r]=(str){j,k};
				}
		while(l<=r)
		{
			int t=vis[q[l].x][q[l].y];
			if(vc[a[q[l].x][q[l].y]]==0)
			{
				vc[a[q[l].x][q[l].y]]=1;
				for(auto it:p[a[q[l].x][q[l].y]])
					if(vis[it.x][it.y]==-1)
					{
						vis[it.x][it.y]=t+1;
						q[++r]=it;
					}
			}
			for(j=0;j<4;++j)
			{
				int x=q[l].x+dx[j],y=q[l].y+dy[j];
				if(vis[x][y]==-1&&x>=1&&y>=1&&x<=n&&y<=m)
				{
					vis[x][y]=t+1;
					q[++r]=(str){x,y};
				}
			}
			++l;
		}
		for(j=1;j<=n;++j)
			for(k=1;k<=m;++k)
				g[pc][j][k]=vis[j][k];
	}
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d %d %d %d",&u,&v,&x,&y);
		int ans=100000000;
		for(i=1;i<=c;++i)
			ans=min(ans,(int)g[i][u][v]+g[i][x][y]+1);
		ans=min(ans,abs(u-x)+abs(v-y));
		printf("%d\n",ans);
	}
}