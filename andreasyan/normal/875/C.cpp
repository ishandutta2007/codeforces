#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m;
vector<int> a[N];

vector<int> v;

vector<int> g[N];
bool c[N];
void dfs(int x)
{
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs(h);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
        }
    }
    for (int i = 1; i < n; ++i)
    {
        bool z = false;
        for (int j = 0; j < min(a[i].size(), a[i + 1].size()); ++j)
        {
            if (a[i][j] != a[i + 1][j])
            {
                z = true;
                if (a[i][j] > a[i + 1][j])
                    v.push_back(a[i][j]);
                else
                    g[a[i + 1][j]].push_back(a[i][j]);
                break;
            }
        }
        if (!z)
        {
            if (a[i + 1].size() < a[i].size())
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < v.size(); ++i)
    {
        int x = v[i];
        if (!c[x])
            dfs(x);
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < min(a[i].size(), a[i + 1].size()); ++j)
        {
            if (a[i][j] != a[i + 1][j])
            {
                if (a[i][j] > a[i + 1][j])
                {
                    if (!(c[a[i][j]] && !c[a[i + 1][j]]))
                    {
                        cout << "No" << endl;
                        return 0;
                    }
                }
                else
                {
                    if (!c[a[i][j]] && c[a[i + 1][j]])
                    {
                        cout << "No" << endl;
                        return 0;
                    }
                }
                break;
            }
        }
    }
    int k = 0;
    for (int i = 1; i <= m; ++i)
    {
        if (c[i])
            ++k;
    }
    cout << "Yes" << endl;
    cout << k << endl;
    for (int i = 1; i <= m; ++i)
    {
        if (c[i])
            cout << i << ' ';
    }
    cout << endl;
    return 0;
}