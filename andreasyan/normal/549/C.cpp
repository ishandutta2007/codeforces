#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2003;

int n, z, k, qq;

void k1()
{
    scanf("%d%d%d", &z, &k, &qq);
    n = z + k;
}

void k2()
{
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        if (x % 2 == 0)
            ++z;
        else
            ++k;
    }
}

int dp[N][N][3];

int rec(int z, int k, int u)
{
    if (dp[z][k][u])
        return dp[z][k][u];
    if (z + k == qq)
    {
        if (k % 2 == 1)
            return dp[z][k][u] = 1;
        else
            return dp[z][k][u] = 2;
    }
    if (z - 1 >= 0 && rec(z - 1, k, 3 - u) == u)
        return dp[z][k][u] = u;
    if (k - 1 >= 0 && rec(z, k - 1, 3 - u) == u)
        return dp[z][k][u] = u;
    return dp[z][k][u] = 3 - u;
}

int recc()
{
    if (qq % 2 == 0)
    {
        if (z + k == qq)
        {
            if (z % 2 == 0)
                return 2;
            else
                return 1;
        }
        if ((z - k) % 2 == 0)
            return 2;
        if (-(qq - 1) <= (z - k) && (z - k) <= (qq - 1))
            return 1;
        return 2;
    }
    else
    {
        if (z + k == qq)
        {
            if (z % 2 == 0)
                return 1;
            else
                return 2;
        }
        if ((z - k) <= -qq)
            return 1;
        if ((z - k) >= qq)
            return 2;
        if ((z - k) % 2 == 0)
            return 1;
        else
            return 2;
    }
}

int main()
{
    k2();
    if (recc() == 1)
        printf("Stannis\n");
    else
        printf("Daenerys\n");
    return 0;
    for (qq = 0; qq <= 15; ++qq)
    {
        printf("%d\n", qq);
        for (z = 0; z <= 20; ++z)
        {
            for (k = 0; k <= 20; ++k)
            {
                memset(dp, 0, sizeof dp);
                if (z + k < qq)
                    printf("0");
                else
                {
                    printf("%d", rec(z, k, 1));
                    assert(rec(z, k, 1) == recc());
                }
            }
            printf("\n");
        }
    }
    return 0;
    freopen("input.txt", "r", stdin);
    k1();
    if (rec(z, k, 1) == 1)
        printf("Stannis\n");
    else
        printf("Daenerys\n");
    return 0;
}