#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006, INF = 1000000009;

int n, t, u;
int a[N];

bool c[N];

void solv()
{
    scanf("%d", &n);
    int q = n;
    while (q > 1)
    {
        ++t;
        q /= 2;
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == -1)
        {
            u = i;
            break;
        }
    }
    q = u - 1;
    int tt = t;
    while (q)
    {
        --tt;
        q = (q - 1) / 2;
    }
    long long ans = 0;
    int x = 0;
    while (tt--)
    {
        int minu = INF, mini;
        for (int i = n - x; i <= n; ++i)
        {
            if (c[i])
                continue;
            if (a[i] < minu)
            {
                minu = a[i];
                mini = i;
            }
        }
        c[mini] = true;
        ans += minu;
        --t;
        x += (1 << t);
    }
    printf("%lld\n", ans);
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