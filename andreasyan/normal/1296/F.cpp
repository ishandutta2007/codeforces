#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 5003;

int n;
vector<pair<int, int> > a[N];
int ans[N];

int m;
pair<pair<int, int>, int> b[N];

vector<int> v;
bool dfs(int x, int p, int y)
{
    if (x == y)
        return true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        v.push_back(a[x][i].second);
        if (dfs(h, x, y))
            return true;
        v.pop_back();
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(m_p(y, i));
        a[y].push_back(m_p(x, i));
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &b[i].first.first, &b[i].first.second, &b[i].second);
    }
    for (int i = 0; i < n - 1; ++i)
        ans[i] = 1;
    for (int i = 0; i < m; ++i)
    {
        int x = b[i].first.first;
        int y = b[i].first.second;
        int z = b[i].second;
        v.clear();
        dfs(x, x, y);
        for (int i = 0; i < v.size(); ++i)
        {
            ans[v[i]] = max(ans[v[i]], z);
        }
    }
    for (int i = 0; i < m; ++i)
    {
        int x = b[i].first.first;
        int y = b[i].first.second;
        int z = b[i].second;
        v.clear();
        dfs(x, x, y);
        int minu = 1000000;
        for (int i = 0; i < v.size(); ++i)
        {
            minu = min(minu, ans[v[i]]);
        }
        if (minu != z)
        {
            printf("-1\n");
            return 0;
        }
    }
    for (int i = 0; i < n - 1; ++i)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}