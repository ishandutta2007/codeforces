#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
vector<int> a[N];

int qryd(int x)
{
    cout << "d " << x << endl;
    int dx;
    cin >> dx;
    if (dx == -1)
        exit(0);
    return dx;
}

int dd, d[N];
int pp[N];
void dfs00(int x, int p)
{
    pp[x] = p;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        d[h] = d[x] + 1;
        dfs00(h, x);
    }
}

bool c[N];

int q[N];
void dfs0(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (c[h])
            continue;
        if (h == p)
            continue;
        dfs0(h, x);
        q[x] += q[h];
    }
}

int dfs(int x, int p, int xx)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (c[h])
            continue;
        if (h == p)
            continue;
        if (q[h] > q[xx] / 2)
            return dfs(h, x, xx);
    }
    return x;
}

int center(int x)
{
    dfs0(x, x);
    return dfs(x, x, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs00(1, 1);
    dd = qryd(1);

    int x = 1;
    while (1)
    {
        int y = center(x);
        c[y] = true;
        int dy = qryd(y);
        if (dy == 0)
        {
            cout << "! " << y << endl;
            return 0;
        }
        if (d[y] + dy == dd)
        {
            cout << "s " << y << endl;
            cin >> x;
            if (x == -1)
                return 0;
        }
        else
        {
            x = pp[y];
        }
    }
    return 0;
}