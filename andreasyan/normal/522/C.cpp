#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, k;
int a[N];

int t[N], r[N];

char ans[N];
bool c[N];

void solv()
{
    scanf("%d%d", &n, &k);
    --n;
    for (int i = 1; i <= k; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &t[i], &r[i]);
    for (int i = 1; i <= k; ++i)
    {
        ans[i] = 0;
        c[i] = false;
    }
    int q = 0;
    bool z = false;
    for (int i = 1; i <= n; ++i)
    {
        if (r[i] == 1)
        {
            z = true;
            int qq = N;
            for (int j = i; j <= n; ++j)
                c[t[j]] = true;
            for (int j = 1; j <= k; ++j)
            {
                if (!c[j] && a[j] - q <= 0)
                {
                    ans[j] = 'Y';
                    qq = min(qq, a[j]);
                }
            }
            assert(qq != N);
            for (; i <= n; ++i)
            {
                if (t[i])
                    --a[t[i]];
                else
                    ++q;
            }
            for (int j = 1; j <= k; ++j)
            {
                if (ans[j] == 'Y')
                    continue;
                if (a[j] - (q - qq) <= 0)
                    ans[j] = 'Y';
                else
                    ans[j] = 'N';
            }
            break;
        }
        else
        {
            if (t[i])
                --a[t[i]];
            else
                ++q;
        }
    }
    if (!z)
    {
        for (int j = 1; j <= k; ++j)
        {
            if (a[j] - q <= 0)
                ans[j] = 'Y';
            else
                ans[j] = 'N';
        }
    }
    for (int i = 1; i <= k; ++i)
        putchar(ans[i]);
    putchar('\n');
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}