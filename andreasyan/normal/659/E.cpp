#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;
 
int n, m;
pair<int, int> b[N];
vector<int> a[N];
 
int c[N];
int k;
void dfs(int x)
{
    c[x] = k;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs(h);
    }
}
 
int qg[N], qk[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
        b[i] = m_p(x, y);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            ++k;
            dfs(i);
        }
    }
    for (int i = 0; i < m; ++i)
    {
        qk[c[b[i].first]]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        qg[c[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= k; ++i)
    {
        if (qk[i] == qg[i] - 1)
            ++ans;
    }
    printf("%d\n", ans);
    return 0;
}