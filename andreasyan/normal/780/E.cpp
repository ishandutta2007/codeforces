#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int n, m, k;
vector<int> a[N];

bool c[N];
vector<int> v;
void dfs(int x)
{
    v.push_back(x);
    c[x] = true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (c[h])
            continue;
        dfs(h);
        v.push_back(x);
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1);
    int j = 0;
    for (int i = 1; i <= k; ++i)
    {
        vector<int> ans;
        int q = (2 * n - 1) / k;
        if (i <= (2 * n - 1) % k)
            ++q;
        while (q--)
        {
            ans.push_back(v[j++]);
        }
        printf("%d ", ans.size());
        for (int i = 0; i < ans.size(); ++i)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}