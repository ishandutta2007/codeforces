#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005, INF = 1000000009;

int n;
long long a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    int ans = 0;
    long long d;
    int u;
    int l;
    if (a[1] == -1)
    {
        ++ans;
        d = -INF;
        u = -1;
        l = 1;
    }
    else
    {
        ++ans;
        d = -INF;
        u = 1;
        l = 1;
    }
    for (int i = 2; i <= n; ++i)
    {
        long long x = a[i];
        if (x == -1)
        {
            if (u == -1)
                continue;
            if (d == -INF)
                continue;
            if (a[u] + (i - u) * d <= 0)
            {
                ++ans;
                u = -1;
                d = -INF;
                l = i;
            }
        }
        else
        {
            if (u == -1)
            {
                u = i;
                continue;
            }
            if (d == -INF)
            {
                if ((a[i] - a[u]) % (i - u) == 0)
                {
                    long long dd = (a[i] - a[u]) / (i - u);
                    if (a[i] - dd * (i - l) > 0)
                    {
                        d = dd;
                    }
                    else
                    {
                        ++ans;
                        d = -INF;
                        u = i;
                        l = i;
                    }
                }
                else
                {
                    ++ans;
                    d = -INF;
                    u = i;
                    l = i;
                }
                continue;
            }
            if (a[u] + (i - u) * d == a[i])
                continue;
            ++ans;
            d = -INF;
            u = i;
            l = i;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}