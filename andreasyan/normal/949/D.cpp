#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, d, b;
int a[N];

long long ll[N], rr[N];

int q[N];
bool stg(int x)
{
    for (int i = 1; i <= n; ++i)
        q[i] = a[i];
    int j = 1;
    for (int i = 1 + x; i <= n - x; ++i)
    {
        int bb = b;
        while (1)
        {
            if (!bb)
                break;
            while (j <= n && !(ll[j] <= i && i <= rr[j] && q[j]))
                ++j;
            if (j == n + 1)
                return false;
            if (q[j] >= bb)
            {
                q[j] -= bb;
                bb = 0;
            }
            else
            {
                bb -= q[j];
                q[j] = 0;
            }
        }
    }
    return true;
}

int solv()
{
    scanf("%d%d%d", &n, &d, &b);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        ll[i] = i / (d + 1);
        if (i % (d + 1))
            ++ll[i];
        rr[i] = (i + n * 1LL * d + d) / (d + 1);
    }
    int ans = n / 2 + 1;
    int l = 0, r = n / 2;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}