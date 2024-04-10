#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
using namespace std;

typedef long long LL;
typedef pair<int,int> pi;

const int N=1000020;
const int inf=1000000000;

int n,m,cnt,last[N],bin[10],dis1[N][8],dis2[8][8],dis3[8][1<<8][8][1<<8],size[8][1<<8],s[N],a[N];
struct edge{int to,next,w;}e[N*4];
queue<pi> que;
char str[N];
vector<int> vec[8];

void addedge(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
}

int get_dis(int c1,int s1,int c2,int s2)
{
	int ans=inf;
	for (int i=0;i<m;i++)
	{
		int x=dis2[c1][i]+((bin[i]&s1)>0),y=dis2[c2][i]+((bin[i]&s2)>0);
		ans=min(ans,x+y+1);
	}
	return ans;
}

void fill(int x,int y)
{
	for (int i=last[x];i;i=e[i].next)
		if (e[i].w==0&&dis1[e[i].to][y]==inf)
			dis1[e[i].to][y]=dis1[x][y],que.push(mp(e[i].to,y));
}

void bfs()
{
	while (!que.empty())
	{
		int x=que.front().first,y=que.front().second;que.pop();
		for (int i=last[x];i;i=e[i].next)
			if (dis1[e[i].to][y]==inf)
			{
				dis1[e[i].to][y]=dis1[x][y]+e[i].w;
				que.push(mp(e[i].to,y));fill(e[i].to,y);
			}
	}
}

int main()
{
	scanf("%d%s",&n,str+1);m=8;
	bin[0]=1;
	for (int i=1;i<=m;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<=n;i++)
	{
		s[i]=str[i]-'a';
		addedge(i,n+s[i]+1,1);addedge(n+s[i]+1,i,0);
		if (i<n) addedge(i,i+1,1),addedge(i+1,i,1);
	}
	for (int i=1;i<=n+m;i++)
	{
		for (int j=0;j<m;j++) dis1[i][j]=inf;
		if (i<=n) dis1[i][s[i]]=0,fill(i,s[i]),que.push(mp(i,s[i]));
	}
	bfs();
	for (int j=0;j<m;j++)
	{
		for (int k=0;k<m;k++) dis2[j][k]=inf;
		for (int i=1;i<=n;i++)
			if (s[i]==j)
				for (int k=0;k<m;k++) dis2[j][k]=min(dis2[j][k],dis1[i][k]);
	}
	for (int c1=0;c1<m;c1++)
		for (int s1=0;s1<bin[m];s1++)
			for (int c2=0;c2<m;c2++)
				for (int s2=0;s2<bin[m];s2++)
					dis3[c1][s1][c2][s2]=get_dis(c1,s1,c2,s2);
	int mx=0;LL ans=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<m;j++) a[i]+=bin[j]*(dis1[i][j]-dis2[s[i]][j]);
		for (int j=1;j<=m*2-1;j++)
		{
			if (i-j<1) break;
			int d=min(j,dis3[s[i]][a[i]][s[i-j]][a[i-j]]);
			if (d>mx) mx=d,ans=1;
			else if (d==mx) ans++;
		}
		for (int j=0;j<m;j++)
			for (int k=0;k<vec[j].size();k++)
			{
				int now=vec[j][k],d=dis3[s[i]][a[i]][j][now];
				if (d==inf) continue;
				if (d>mx) mx=d,ans=size[j][now];
				else if (d==mx) ans+=size[j][now];
			}
		if (i-m*2+1<1) continue;
		int c=s[i-m*2+1],now=a[i-m*2+1];
		if (!size[c][now]) vec[c].pb(now);
		size[c][now]++;
	}
	printf("%d %I64d",mx,ans);
	return 0;
}