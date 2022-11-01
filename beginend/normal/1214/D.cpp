#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N=2000005;
const int inf=1000000000;

int n,cnt,last[N],dis[N],s,t,cur[N],ans,m;
struct edge{int to,next,c;}e[N*3];
queue<int> que;
char str[N];

int point(int x,int y,int z)
{
	return (x-1)*m+y+z*n*m;
}

void addedge(int u,int v,int c)
{
    e[++cnt].to=v;e[cnt].c=c;e[cnt].next=last[u];last[u]=cnt;
    e[++cnt].to=u;e[cnt].c=0;e[cnt].next=last[v];last[v]=cnt;
}

bool bfs()
{
    for (int i=s;i<=t;i++) dis[i]=0;
    while (!que.empty()) que.pop();
    que.push(s);dis[s]=1;
    while (!que.empty())
    {
        int u=que.front();que.pop();
        for (int i=last[u];i;i=e[i].next)
            if (e[i].c&&!dis[e[i].to])
            {
                dis[e[i].to]=dis[u]+1;
                if (e[i].to==t) return 1;
                que.push(e[i].to);
            }
    }
    return 0;
}

int dfs(int x,int maxf)
{
    if (x==t||!maxf) return maxf;
    int ret=0;
    for (int &i=cur[x];i;i=e[i].next)
        if (e[i].c&&dis[e[i].to]==dis[x]+1)
        {
            int f=dfs(e[i].to,min(e[i].c,maxf-ret));
            e[i].c-=f;
            e[i^1].c+=f;
            ret+=f;
            if (maxf==ret) break;
        }
    return ret;
}

int dinic()
{
    int ans=0;
    while (bfs())
    {
        for (int i=s;i<=t;i++) cur[i]=last[i];
        ans+=dfs(s,inf);
    }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
    	scanf("%s",str+1);
    	for (int j=1;j<=m;j++)
    	{
    		if (str[j]=='.') addedge(point(i,j,0),point(i,j,1),1);
    		if (i<n) addedge(point(i,j,1),point(i+1,j,0),inf);
    		if (j<m) addedge(point(i,j,1),point(i,j+1,0),inf);
    	}
    }
    s=0;t=n*m*2+1;
    addedge(s,point(1,1,1),inf);
    addedge(point(n,m,0),t,inf);
    printf("%d\n",dinic());
    return 0;
}