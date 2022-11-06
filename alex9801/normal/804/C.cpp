#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int N, M;
int color[505050];
set<int> S;
vector<int> colors[505050];
vector<int> conn[505050];
void colorpicker(int c)
{
    for(auto x: colors[c])
        if(color[x])
            S.erase(color[x]);
    for(auto x: colors[c])
    {
        if(!color[x])
        {
            color[x] = *S.begin();
            S.erase(color[x]);
        }
    }
    for(auto x: colors[c])
    {
        S.insert(color[x]);
    }
    return;
}
void dfs(int a, int pa)
{
    colorpicker(a);
    for(auto x: conn[a])
    {
        if(x==pa) continue;
        dfs(x, a);
    }
    return;
}
int main()
{
    scanf("%d%d", &N, &M);
    for(int i = 1; i<=M; ++i)
        S.insert(i);
    int maxv = 0;
    for(int i = 0; i<N; ++i)
    {
        int Q;
        scanf("%d", &Q);
        for(int j = 0; j<Q; ++j)
        {
            int t;
            scanf("%d", &t);
            --t;
            colors[i].push_back(t);
        }
    }
    for(int i = 0; i<N-1; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        conn[u].push_back(v);
        conn[v].push_back(u);
    }
    dfs(0, -1);
    for(int i = 0; i<M; ++i)
    {
        if(color[i]==0) color[i] = 1;
        maxv = max(maxv, color[i]);
    }
    printf("%d\n", maxv);
    for(int i = 0; i<M; ++i)
        printf("%d ", i+1);
    return 0;

}