#include <bits/stdc++.h>
using namespace std;
const int N = 302;

int n, k;
vector<int> a[N];
int b[N];

int tin[N], tout[N], ti;
int pp[N];
void dfs0(int x, int p)
{
    tin[x] = ti++;
    pp[x] = p;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
    }
    tout[x] = ti++;
}
bool pqry(int x, int y)
{
    return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}

int q[N];
vector<int> v;

void go(int x, int y)
{
    if (v.empty() || x != v.back())
        v.push_back(x);
    if (x == y)
        return;
    if (pqry(x, y))
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (h == pp[x])
                continue;
            if (pqry(h, y))
            {
                q[h]++;
                go(h, y);
            }
        }
    }
    else
    {
        q[x]++;
        go(pp[x], y);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 2; i <= n; ++i)
    {
        if (a[i].size() == 1)
            ++k;
    }
    for (int i = 1; i <= k; ++i)
    {
        cin >> b[i];
    }
    dfs0(1, 1);

    int x = 1;
    for (int i = 1; i <= k; ++i)
    {
        go(x, b[i]);
        x = b[i];
    }
    go(x, 1);
    for (int i = 2; i <= n; ++i)
    {
        if (q[i] != 2)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}