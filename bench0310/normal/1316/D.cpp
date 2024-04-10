#include <bits/stdc++.h>

using namespace std;

const int N=1005;
int n;
int r[N][N];
int c[N][N];
bool vis[N][N];
char res[N][N];
vector<pair<array<int,2>,char>> dir={{{0,1},'L'},{{0,-1},'R'},{{1,0},'U'},{{-1,0},'D'}};
vector<pair<array<int,2>,char>> tdir={{{0,1},'R'},{{0,-1},'L'},{{1,0},'D'},{{-1,0},'U'}};

bool in(int x,int y)
{
    return (1<=min(x,y)&&max(x,y)<=n);
}

void solve(int x,int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y]=1;
    res[x][y]='X';
    while(!q.empty())
    {
        auto [a,b]=q.front();
        q.pop();
        for(auto temp:dir)
        {
            auto [dx,dy]=temp.first;
            char t=temp.second;
            if(in(a+dx,b+dy)&&vis[a+dx][b+dy]==0&&r[a+dx][b+dy]==x&&c[a+dx][b+dy]==y)
            {
                res[a+dx][b+dy]=t;
                vis[a+dx][b+dy]=1;
                q.push({a+dx,b+dy});
            }
        }
    }
}

bool loop(int x,int y)
{
    int cnt=0;
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y]=1;
    while(!q.empty())
    {
        auto [a,b]=q.front();
        q.pop();
        for(auto temp:dir)
        {
            auto [dx,dy]=temp.first;
            char t=temp.second;
            if(in(a+dx,b+dy)&&vis[a+dx][b+dy]==0&&r[a+dx][b+dy]==-1&&c[a+dx][b+dy]==-1)
            {
                res[a+dx][b+dy]=t;
                vis[a+dx][b+dy]=1;
                q.push({a+dx,b+dy});
            }
        }
        cnt++;
    }
    for(auto temp:tdir)
    {
        auto [dx,dy]=temp.first;
        char t=temp.second;
        if(in(x+dx,y+dy)&&r[x+dx][y+dy]==-1&&c[x+dx][y+dy]==-1)
        {
            res[x][y]=t;
        }
    }
    return (cnt>=2);
}

int main()
{
    scanf("%d",&n);
    for(int o=1;o<=n;o++) for(int i=1;i<=n;i++) scanf("%d%d",&r[o][i],&c[o][i]);
    bool ok=1;
    for(int o=1;o<=n;o++)
    {
        for(int i=1;i<=n;i++)
        {
            if(vis[o][i]) continue;
            if(r[o][i]==o&&c[o][i]==i) solve(o,i);
            if(r[o][i]==-1&&c[o][i]==-1) if(loop(o,i)==0) ok=0;
        }
    }
    for(int o=1;o<=n;o++) for(int i=1;i<=n;i++) if(vis[o][i]==0) ok=0;
    if(ok)
    {
        printf("VALID\n");
        for(int o=1;o<=n;o++)
        {
            for(int i=1;i<=n;i++) printf("%c",res[o][i]);
            printf("\n");
        }
    }
    else printf("INVALID\n");
    return 0;
}