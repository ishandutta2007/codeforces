#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

#define mp(a,b) std::make_pair(a,b)

std::vector<int> arr[3001];
std::queue<std::pair<int,int> > q;
int dis[3001][3001];
bool chk[3001];

int main()
{
    int r=0, t, x, y, a, b, n, m, i, j;
    int s1, t1, l1, s2, t2, l2;
    scanf("%d%d", &n, &m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d", &a, &b);
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
    for(i=1;i<=n;i++)
    {
        memset(chk, 0, sizeof(chk));
        q.push(mp(i,0));
        dis[i][i]=0;
        chk[i]=1;
        while(!q.empty())
        {
            x=q.front().first;
            t=q.front().second;
            q.pop();
            for(j=0;j<arr[x].size();j++)
            {
                y=arr[x][j];
                if(!chk[y])
                {
                    chk[y]=1;
                    dis[i][y]=t+1;
                    dis[y][i]=t+1;
                    q.push(mp(y, t+1));
                }
            }
        }
    }
    if(dis[s1][t1]>l1||dis[s2][t2]>l2)
    {
        printf("-1");
        return 0;
    }
    r=std::max(r, m-(dis[s1][t1]+dis[s2][t2]));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(dis[s1][i] + dis[i][j] + dis[j][t1] <= l1 && dis[s2][i] + dis[i][j] + dis[j][t2] <= l2)
                r=std::max(r, m - (dis[s1][i] + dis[j][t1] + dis[s2][i] + dis[j][t2] + dis[i][j]));

            if(dis[s1][j] + dis[i][j] + dis[i][t1] <= l1 && dis[s2][i] + dis[i][j] + dis[j][t2] <= l2)
                r=std::max(r, m - (dis[s1][j] + dis[i][t1] + dis[s2][i] + dis[j][t2] + dis[i][j]));
        }
    }
    printf("%d", r);
    return 0;
}