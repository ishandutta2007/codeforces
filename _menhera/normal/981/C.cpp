#include<bits/stdc++.h>
using namespace std;
vector<int> conn[1010101];
int dfs(int a, int pa)
{
    if(conn[a].size() == 1) return a;
    for(auto x: conn[a])
        if(x!=pa) return dfs(x, a);
}
int main()
{
    int N; scanf("%d", &N);
    for(int i=0; i<N-1; ++i)
    {
        int u, v; scanf("%d%d", &u, &v);
        conn[u].push_back(v);
        conn[v].push_back(u);
    }
    int cnt = 0;
    int deg3 = 0;
    for(int i=1; i<=N; ++i)
    {
        if(conn[i].size() >= 3)
        {
            deg3 = i; ++cnt;
        }
    }
    if(cnt >= 2)
    {
        puts("No");
        return 0;
    }
    if(cnt == 0)
    {
        puts("Yes\n1");
        for(int i=1; i<=N; ++i)
        {
            if(conn[i].size() == 1) printf("%d ", i);
        }
        puts("");
        return 0;
    }
    puts("Yes");
    printf("%d\n", (int)conn[deg3].size());
    for(auto x: conn[deg3])
    {
        printf("%d %d\n", deg3, dfs(x, deg3));
    }
    return 0;
}