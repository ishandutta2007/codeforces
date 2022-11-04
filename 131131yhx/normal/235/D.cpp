#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, S[5010], dis1[5010], dis2[5010], Head[5010], Next[10010], Go[10010], Cnt = 0, Top = 0, Where[5010], Cycle = 0;

bool Vis[5010];

double ans = 0.0;

inline void addedge(int x, int y)
{
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
}

void Find(int x, int before = 0)
{
    S[++Top] = x;
    if(Where[x])
    {
        for(int i = Where[x]; i < Top; i++)
            Cycle++;
        return;
    }
    Where[x] = Top;
    for(int T = Head[x]; T; T = Next[T])
        if(Go[T] != before)
            Find(Go[T], x);
    Top--;
}

void dfs(int x, int k)
{
    if(k)
        (!dis1[x]) ? dis1[x] = k, dis2[x] = 0 : dis2[x] = k;
    Vis[x] = 1;
    for(int T = Head[x]; T; T = Next[T])
        if(!Vis[Go[T]]) dfs(Go[T], k + 1);
    Vis[x] = 0;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        addedge(x, y);
        addedge(y, x);
    }
    Find(1);
    for(int i = 0; i < n; i++)
    {
        memset(Vis, 0, sizeof Vis);
        memset(dis1, 0, sizeof dis1);
        dfs(i, 1);
        for(int j = 0; j < n; j++)
            if(j != i)
                ans += (dis2[j]) ? 1.0 / dis1[j] + 1.0 / dis2[j] - 2.0 / (dis1[j] + dis2[j] + Cycle - 2) : 1.0 / dis1[j];
    }
    printf("%.12lf\n", ans + n);
    return 0;
}