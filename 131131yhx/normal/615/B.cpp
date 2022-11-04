#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define M 1000100

using namespace std;

typedef long long ll;

ll Val[M], ans = 0, Cnt = 0;

ll Vis[M];

vector <ll> lis[M];

int Dfs(int x, ll dep)
{
    if(Vis[x]) return Vis[x];
    Vis[x] = 1;
    for(int i = 0; i != lis[x].size(); i++) Vis[x] = max(Vis[x], (ll)Dfs(lis[x][i], dep + 1) + 1);
    ans = max(ans, Val[x] * Vis[x]);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) lis[i].resize(0);
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if(x > y) lis[x].push_back(y);
        else lis[y].push_back(x);
        Val[x]++, Val[y]++;
    }
    for(int i = 1; i <= n; i++) sort(lis[i].begin(), lis[i].end());
    for(int i = 1; i <= n; i++) if(!Vis[i]) Dfs(i, 1);
    printf("%lld\n", ans);
    return 0;
}