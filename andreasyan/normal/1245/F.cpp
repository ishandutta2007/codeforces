#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);

void por()
{
    for (int x = 0; x < 1000; ++x)
    {
        for (int y = 0; y < 1000; ++y)
        {
            if ((x ^ y) == (x + y) && (x & y) != 0)
                printf("We don't do that.\n");
        }
    }
}

long long dp[32][2][2];

void solv()
{
    int l, r;
    scanf("%d%d", &l, &r);
    memset(dp, 0, sizeof dp);
    int z = 1;
    for (int i = 31; i > 0; --i)
    {
        int bl = 0, br = 0;
        if ((l & (1 << (i - 1))))
            bl = 1;
        if ((r & (1 << (i - 1))))
            br = 1;
        dp[i - 1][0][0] += dp[i][0][0] * 3;
        for (int zl = 0; zl < 2; ++zl)
        {
            for (int zr = 0; zr < 2; ++zr)
            {
                if (zl && zr)
                    continue;
                if (!(bl <= zl))
                    continue;
                dp[i - 1][(zl == bl)][0] += dp[i][1][0];
            }
        }
        for (int zl = 0; zl < 2; ++zl)
        {
            for (int zr = 0; zr < 2; ++zr)
            {
                if (zl && zr)
                    continue;
                if (!(zr <= br))
                    continue;
                dp[i - 1][0][(zr == br)] += dp[i][0][1];
            }
        }
        for (int zl = 0; zl < 2; ++zl)
        {
            for (int zr = 0; zr < 2; ++zr)
            {
                if (zl && zr)
                    continue;
                if (!(bl <= zl))
                    continue;
                if (!(zr <= br))
                    continue;
                dp[i - 1][(zl == bl)][(zr == br)] += dp[i][1][1];
            }
        }
        if (z == 1)
        {
            if (!bl && br)
            {
                dp[i - 1][1][1] += 2;
                z = 2;
            }
        }
        else if (z == 2)
        {
            if (bl <= 0)
            {
                dp[i - 1][1][0] += 2;
            }
        }
        if (bl)
            z = false;
    }
    printf("%lld\n", (dp[0][0][1] + dp[0][1][0] + dp[0][0][0] + dp[0][1][1] + (l == 0)));
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    por();
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}