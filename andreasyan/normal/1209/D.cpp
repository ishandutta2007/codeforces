#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;

int n, m;
vector<int> a[N];
pair<int, int> b[N];

int k;
int c[N];
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

int qg[N];
int qk[N];
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
        int x = b[i].first;
        int y = b[i].second;
        qk[c[x]]++;
    }
    for (int i = 1; i <= n; ++i)
        qg[c[i]]++;
    int ans = 0;
    for (int i = 1; i <= k; ++i)
    {
        ans += (qk[i] - (qg[i] - 1));
    }
    cout << ans << endl;
    return 0;
}