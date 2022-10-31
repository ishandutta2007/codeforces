#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;

const int N=10005;
const int M=1005;
const LL inf=(LL)1e15;

int n,m,a[N],g,r;
LL dis[N][M];
bool vis[N][M];

void bfs()
{
	for (int i=1;i<=m;i++)
		for (int j=0;j<g;j++)
			dis[i][j]=inf;
	dis[1][0]=0;
	vector<pi> vec[2];
	vec[0].clear();
	vec[1].clear();
	int now=0;
	vec[now].pb(mp(1,0));
	for (int i=0;;i++)
	{
		if (!vec[now].size()) break;
		for (int j=0;j<vec[now].size();j++)
		{
			int x=vec[now][j].first,y=vec[now][j].second;
			int w1=a[x]-a[x-1],y1=y+a[x]-a[x-1],w2=a[x+1]-a[x],y2=y+a[x+1]-a[x];
			if (y1>=g) y1=-1;
			if (y2>=g) y2=-1;
			if (y1>=0&&x>1&&dis[x-1][y1]==inf) dis[x-1][y1]=dis[x][y]+w1,vec[now].pb(mp(x-1,y1));
			if (y2>=0&&x<m&&dis[x+1][y2]==inf) dis[x+1][y2]=dis[x][y]+w2,vec[now].pb(mp(x+1,y2));
		}
		for (int j=0;j<vec[now].size();j++)
		{
			int x=vec[now][j].first,y=vec[now][j].second;
			int w1=a[x]-a[x-1],y1=y+a[x]-a[x-1],w2=a[x+1]-a[x],y2=y+a[x+1]-a[x];
			if (y1==g) y1=0,w1+=r;
			else y1=-1;
			if (y2==g) y2=0,w2+=r;
			else y2=-1;
			if (y1>=0&&x>1&&dis[x-1][y1]==inf) dis[x-1][y1]=dis[x][y]+w1,vec[now^1].pb(mp(x-1,y1));
			if (y2>=0&&x<m&&dis[x+1][y2]==inf) dis[x+1][y2]=dis[x][y]+w2,vec[now^1].pb(mp(x+1,y2));
		}
		vec[now].clear();
		now^=1;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	a[++m]=0;
	a[++m]=n;
	std::sort(a+1,a+m+1);
	m=std::unique(a+1,a+m+1)-a-1;
	scanf("%d%d",&g,&r);
	bfs();
	LL ans=inf;
	for (int i=1;i<g;i++) ans=std::min(ans,dis[m][i]);
	if (dis[m][0]<inf) ans=std::min(ans,dis[m][0]-r);
	if (ans==inf) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}