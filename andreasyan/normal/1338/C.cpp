#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102;

int ans[3][N];

void ubd(int i, int j)
{
    if (j == 1)
    {
        ans[0][i] = 1;
        ans[1][i + 1] = 1;
        ans[2][i] = ans[2][i + 1] = 1;
    }
    else if (j == 2)
    {
        ans[0][i + 1] = 1;
        ans[1][i] = ans[1][i + 1] = 1;
        ans[2][i] = 1;
    }
    else if (j == 3)
    {
        ans[0][i] = ans[0][i + 1] = 1;
        ans[1][i] = 1;
        ans[2][i + 1] = 1;
    }
}

long long solv(long long n)
{
    memset(ans, 0, sizeof ans);
    long long nn;
    --n;
    nn = n;
    n /= 3;
    long long uu = 1;
    long long u = 1;
    int q = 2;
    while (!(n < uu))
    {
        u *= 4;
        uu += u;
        q += 2;
    }
    ubd(q - 2, 1);
    q -= 2;
    n -= (uu - u);
    while (1)
    {
        if (q == 0)
            break;
        ubd(q - 2, (n / (u / 4)));
        q -= 2;
        n %= (u / 4);
        u /= 4;
    }
    long long yans = 0;
    for (long long i = N - 1; i >= 0; --i)
    {
        if (ans[nn % 3][i])
            yans |= (1LL << i);
    }
    return yans;
}

bool c[N * N * N];

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        long long n;
        scanf("%I64d", &n);
        printf("%I64d\n", solv(n));
    }
    return 0;
    int t = 0;
    for (int i = 0; i < 1 + 4 + 16 + 64 + 1; ++i)
    {
        bool f = false;
        int xx, yy, zz;
        for (int x = 1; ; ++x)
        {
            if (c[x])
                continue;
            for (int y = x + 1; y <= 2000; ++y)
            {
                if (c[y])
                    continue;
                for (int z = y + 1; z <= 2000; ++z)
                {
                    if(c[z])
                        continue;
                    if ((x ^ y ^ z) == 0)
                    {
                        xx = x;
                        yy = y;
                        zz = z;
                        f = true;
                        break;
                    }
                }
                if (f)
                    break;
            }
            if (f)
                break;
        }
        /*for (int i = 0; i < 10; ++i)
        {
            if ((xx & (1 << i)))
                printf("1");
            else
                printf("0");
        }
        printf("\n");
        for (int i = 0; i < 10; ++i)
        {
            if ((yy & (1 << i)))
                printf("1");
            else
                printf("0");
        }
        printf("\n");
        for (int i = 0; i < 10; ++i)
        {
            if ((zz & (1 << i)))
                printf("1");
            else
                printf("0");
        }
        printf("\n");
        printf("\n");*/
        if (solv(t + 1) != xx)
            printf("WA\n");
        if (solv(t + 2) != yy)
            printf("WA\n");
        if (solv(t + 3) != zz)
            printf("WA\n");
        c[xx] = c[yy] = c[zz] = true;
        t += 3;
    }
    return 0;
}