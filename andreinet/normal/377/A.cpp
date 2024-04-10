#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

const int N=505;

vector <PII> sol[N*N];
char a[N][N];
int n, m, d[N][N], dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};

bool verif(int i, int j)
{
    if(d[i][j]!=-1) return 0;
    if(a[i][j]!='.') return 0;
    return 1;
}

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int k, i, j, ok=1;
    queue <PII> q;
    PII p;
    scanf("%d %d %d\n", &n, &m, &k);
    for(i=1;i<=n;i++)
    {
        fgets(a[i]+1, N, stdin);
    }
    for(i=1;i<=n&&ok;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i][j]=='.')
            {
                p=make_pair(i, j);
                ok=0;
                break;
            }
        }
    }
    memset(d, -1, sizeof(d));
    d[p.x][p.y]=0;
    sol[0].push_back(p);
    for(q.push(p);!q.empty();q.pop())
    {
        p=q.front();
        sol[d[p.x][p.y]].push_back(p);
        for(i=0;i<4;i++)
        {
            if(verif(p.x+dx[i], p.y+dy[i]))
            {
                d[p.x+dx[i]][p.y+dy[i]]=d[p.x][p.y]+1;
                q.push(make_pair(p.x+dx[i], p.y+dy[i]));
            }
        }
    }
    for(i=n*m;k;k--)
    {
        while(!sol[i].size()) i--;
        a[sol[i].back().x][sol[i].back().y]='X';
        sol[i].pop_back();
    }
    for(i=1;i<=n;i++)
    {
        printf("%s", a[i]+1);
    }
}