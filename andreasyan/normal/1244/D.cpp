#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N][3];
vector<int> g[N];

bool c[N];
int main()
{
    scanf("%d", &n);
    for (int j = 0; j < 3; ++j)
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i][j]);
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int x = 1; x <= n; ++x)
    {
        if (g[x].size() > 2)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    vector<int> v;
    for (int x = 1; x <= n; ++x)
    {
        if (g[x].size() == 1)
        {
            while (1)
            {
                c[x] = true;
                v.push_back(x);
                int y = -1;
                for (int i = 0; i < g[x].size(); ++i)
                {
                    int h = g[x][i];
                    if (!c[h])
                        y = h;
                }
                if (y == -1)
                    break;
                x = y;
            }
            break;
        }
    }
    long long ans = -1;
    vector<int> c;
    c.assign(n + 1, 0);
    int t[3] = {0, 1, 2};
    do
    {
        int j = 0;
        long long yans = 0;
        for (int i = 0; i < n; ++i)
        {
            yans += a[v[i]][t[j]];
            j = (j + 1) % 3;
        }
        if (ans == -1 || yans < ans)
        {
            ans = yans;
            j = 0;
            for (int i = 0; i < n; ++i)
            {
                c[v[i]] = t[j];
                j = (j + 1) % 3;
            }
        }
    } while (next_permutation(t, t + 3));
    cout << ans << endl;
    for (int i = 1; i <= n; ++i)
        cout << c[i] + 1 << ' ';
    cout << endl;
    return 0;
}