#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N=105;
const int inf=(int)1e9;

int n,map[N][N],cnt,last[N*N],dis[N*N],s,t,pre[N*N],num[N][N],pos[N][N],m;
queue<int> que;
struct edge{int to,next,c,w;}e[N*N*20];
bool vis[N*N];

int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void addedge(int u,int v,int c,int w)
{
    e[++cnt].to=v;e[cnt].c=c;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
    e[++cnt].to=u;e[cnt].c=0;e[cnt].w=-w;e[cnt].next=last[v];last[v]=cnt;
}

bool spfa()
{
    for (int i=s;i<=t;i++) dis[i]=inf;
    dis[s]=0;vis[s]=1;que.push(s);
    while (!que.empty())
    {
        int u=que.front();que.pop();
        for (int i=last[u];i;i=e[i].next)
            if (e[i].c&&dis[u]+e[i].w<dis[e[i].to])
            {
                dis[e[i].to]=dis[u]+e[i].w;
                pre[e[i].to]=i;
                if (!vis[e[i].to]) vis[e[i].to]=1,que.push(e[i].to);
            }
        vis[u]=0;
    }
    if (dis[t]==inf) return 0;
    else return 1;
}

int mcf()
{
    int x=t;
    while (x!=s)
    {
        e[pre[x]].c--;
        e[pre[x]^1].c++;
        x=e[pre[x]^1].to;
    }
    return dis[t];
}

int main()
{
    n=read();m=read();
    for (int i=1;i<=n;i++)
    	for (int j=i+1;j<=n;j++)
    		map[i][j]=map[j][i]=2;
    for (int i=1;i<=m;i++)
    {
    	int x=read(),y=read();
    	map[x][y]=1;
    	map[y][x]=0;
    }
    int sz=0;
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
            num[i][j]=++sz;
    s=0;t=n+sz+1;cnt=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<n-1;j++)
            addedge(s,i,1,j);
    for (int i=1;i<=sz;i++) addedge(i+n,t,1,0);
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
            if (map[i][j]==1) addedge(i,num[i][j]+n,1,0);
            else if (!map[i][j]) addedge(j,num[i][j]+n,1,0);
            else addedge(i,num[i][j]+n,1,0),addedge(j,num[i][j]+n,1,0),pos[i][j]=cnt;
    int ans=n*(n-1)*(n-2)/6;
    while (spfa()) ans-=mcf();
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
            if (map[i][j]==2)
            {
                if (e[pos[i][j]].c) map[i][j]=0,map[j][i]=1;
                else map[i][j]=1,map[j][i]=0;
            }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<n;j++) printf("%d",map[i][j]);
        printf("%d\n",map[i][n]);
    }
    return 0;
}