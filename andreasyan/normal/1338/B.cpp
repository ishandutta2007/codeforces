#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;
vector<int> a[N];
bool c[N];
bool cc[N];

int d[N];

void dfs(int x, int p)
{
    d[x] = d[p] + 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int x = 1; x <= n; ++x)
    {
        if (a[x].size() == 1)
            c[x] = true;
    }
    int ans1 = 1, ans2 = n - 1;
    for (int x = 1; x <= n; ++x)
    {
        if (a[x].size() > 1)
        {
            int q = 0;
            for (int i = 0; i < a[x].size(); ++i)
            {
                int h = a[x][i];
                if (c[h])
                    ++q;
            }
            if (q >= 1)
            {
                cc[x] = true;
                ans2 -= (q - 1);
            }
        }
    }
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            dfs(x, x);
            break;
        }
    }
    bool u[2] = {};
    for (int x = 1; x <= n; ++x)
    {
        if (c[x])
        {
            u[d[x] % 2] = true;
        }
    }
    if (u[0] && u[1])
        ans1 = 3;
    printf("%d %d\n", ans1, ans2);
    return 0;
}