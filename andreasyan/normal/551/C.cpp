#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;
const long long INF = 100005000000009;

int n, m;
int a[N];
int aa[N];

bool stg(long long t)
{
    for (int i = 1; i <= n; ++i)
        a[i] = aa[i];
    int j = n;
    for (int i = 0; i < m; ++i)
    {
        while (!a[j] && j > 0)
            --j;
        long long tt = t;
        tt -= j;
        if (tt < 0)
            continue;
        while (1)
        {
            if (!j)
                return true;
            if (tt >= a[j])
            {
                tt -= a[j];
                --j;
            }
            else
            {
                a[j] -= tt;
                break;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        aa[i] = a[i];
    long long l = 0, r = INF;
    long long ans;
    while (l <= r)
    {
        long long m = l + (r - l) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    printf("%lld\n", ans);
    return 0;
}