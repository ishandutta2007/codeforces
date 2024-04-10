#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];
int b[N], d[N];

int c[N];
long long dd[N];
void dfs(int x)
{
    c[x] = n + 1;
    int h = b[x];
    if (h == -1)
    {
        c[x] = x;
        return;
    }
    if (c[h] == 0)
        dfs(h);
    if (c[h] == n + 1)
        c[x] = 1;
    else
    {
        c[x] = c[h];
        dd[x] = dd[h] + d[x];
    }
}

int main()
{
    cin >> n;
    for (int i = 2; i <= n; ++i)
        cin >> a[i];

    for (int i = 2; i <= n; ++i)
    {
        int y = a[i];
        int j = i + a[i];
        if (j > n)
        {
            b[i] = -1;
            dd[i] = y;
            continue;
        }
        y = y + a[j];
        j = j - a[j];
        if (j <= 0)
        {
            b[i] = -1;
            dd[i] = y;
            continue;
        }
        b[i] = j;
        d[i] = y;
    }
    b[1] = -1;

    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
            dfs(i);
    }

    for (a[1] = 1; a[1] <= n - 1; ++a[1])
    {
        int i = 1;
        int y = a[i];
        int j = i + a[i];
        if (j > n)
        {
            cout << y << endl;
            continue;
        }
        y = y + a[j];
        j = j - a[j];
        if (j <= 0)
        {
            cout << y << endl;
            continue;
        }
        if (c[j] == 1)
        {
            cout << "-1" << endl;
            continue;
        }
        cout << y + dd[j] << endl;
    }
    return 0;
}