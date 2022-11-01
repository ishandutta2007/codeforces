#include<bits/stdc++.h>
using namespace std;

const int N = 205;
const int M = N * N * 2;
const int inf = 1e9;

int n, m, tot, down[N][N], rig[N][N], s, t, last[M], cnt, dis[M], cur[M];
struct edge{int to, c, next;}e[N * N * 20];
queue<int> que;
char ma[N][N];

void addedge(int u,int v,int c)
{
	if (!u || !v) return;
    e[++cnt].to=v;e[cnt].c=c;e[cnt].next=last[u];last[u]=cnt;
    e[++cnt].to=u;e[cnt].c=0;e[cnt].next=last[v];last[v]=cnt;
}

bool bfs()
{
    for (int i=1;i<=tot;i++) dis[i]=0;
    while (!que.empty()) que.pop();
    dis[s]=1;que.push(s);
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
            int f=dfs(e[i].to,std::min(e[i].c,maxf-ret));
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
        for (int i=1;i<=tot;i++) cur[i]=last[i];
        ans+=dfs(s,inf);
    }
    return ans;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", ma[i] + 1);
	s = 1; t = 2; tot = 2; cnt = 1;
	int sum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (ma[i][j] == '#')
		{
			sum++;
			if (i < n && ma[i + 1][j] == '#') down[i][j] = ++tot, addedge(s, tot, 1);
			if (j < m && ma[i][j + 1] == '#') rig[i][j] = ++tot, addedge(tot, t, 1);
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (ma[i][j] == '#')
		{
			if (i < n && ma[i + 1][j] == '#')
			{
				addedge(down[i][j], rig[i][j - 1], inf);
				addedge(down[i][j], rig[i][j], inf);
				addedge(down[i][j], rig[i + 1][j - 1], inf);
				addedge(down[i][j], rig[i + 1][j], inf);
			}
			if (j < m && ma[i][j + 1] == '#')
			{
				addedge(down[i][j], rig[i][j], inf);
				addedge(down[i - 1][j], rig[i][j], inf);
				addedge(down[i][j + 1], rig[i][j], inf);
				addedge(down[i - 1][j + 1], rig[i][j], inf);
			}
		}
	printf("%d\n", sum - (tot - 2) + dinic());
	return 0;
}