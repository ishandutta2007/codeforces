#include <bits/stdc++.h>
using namespace std;
const int N = 2003;
 
int n, m;
int a[N];
bool c[N];
pair<int, int> b[N];
 
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * 2; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &b[i].first, &b[i].second);
    int z;
    scanf("%d", &z);
    --z;
    for (int ii = 0; ii < n * 2; ++ii)
    {
        if (z == 0)
        {
            int u = 0;
            for (int i = 1; i <= m; ++i)
            {
                if (!c[b[i].first] && c[b[i].second])
                {
                    u = b[i].first;
                }
                else if (c[b[i].first] && !c[b[i].second])
                {
                    u = b[i].second;
                }
            }
            if (!u)
            {
            for (int i = 1; i <= m; ++i)
            {
                if (!c[b[i].first])
                {
                    if (a[b[i].first] > a[b[i].second])
                    {
                        u = b[i].first;
                    }
                    else
                    {
                        u = b[i].second;
                    }
                    break;
                }
            }
            }
            if (!u)
            {
            int maxu = 0;
            for (int i = 1; i <= n * 2; ++i)
            {
                if (!c[i])
                    maxu = max(maxu, a[i]);
            }
            for (int i = 1; i <= n * 2; ++i)
            {
                if (!c[i])
                {
                    if (a[i] == maxu)
                    {
                        u = i;
                        break;
                    }
                }
            }
            }
            printf("%d\n", u);
            fflush(stdout);
            c[u] = true;
        }
        else
        {
            int x;
            scanf("%d", &x);
            c[x] = true;
        }
        z ^= 1;
    }
    return 0;
}