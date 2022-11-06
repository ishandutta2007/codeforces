#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int ipow(int a, int b)
{
    if(!b)
        return 1;
    if(b % 2)
        return 1LL * ipow(a, b - 1) * a % mod;
    int t = ipow(a, b / 2);
    return 1LL * t * t % mod;
}
int inv(int a)
{
    assert(a != 0);
    return ipow(a, mod - 2);
}

int like[200010];
int arr[200010];
int res[200010];
int mem[3010][3010];
int acnt[3010][3010];
int bcnt[3010];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &like[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    int sa = 0, sb = 0;
    for(int i = 1; i <= n; i++)
    {
        if(like[i])
            sa += arr[i];
        else
            sb += arr[i];
    }
    int sum = sa + sb;

    mem[0][0] = 1;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(mem[i][j] == 0)
                continue;

            int p = 1LL * (sa + j) * inv(sum + j - (i - j)) % mod;
            mem[i + 1][j + 1] = (mem[i + 1][j + 1] + 1LL * mem[i][j] * p) % mod;
            mem[i + 1][j] = (mem[i + 1][j] + 1LL * mem[i][j] * (1 - p + mod)) % mod;
        }
    }

    acnt[0][1] = 1;
    for(int i = 0; i < m; i++)
    {
        for(int j = 1; j <= i + 1; j++)
        {
            int p = 1LL * j * inv(sa + i) % mod;
            acnt[i + 1][j + 1] = (acnt[i + 1][j + 1] + 1LL * acnt[i][j] * p) % mod;
            acnt[i + 1][j] = (acnt[i + 1][j] + 1LL * acnt[i][j] * (1 - p + mod)) % mod;
        }
    }

    int ap = 0;
    for(int i = 0; i <= m; i++)
        for(int j = 1; j <= i + 1; j++)
            ap = (ap + 1LL * j * mem[m][i] % mod * acnt[i][j]) % mod;

    bcnt[0] = 1;
    for(int i = 0; i < m; i++)
    {
        if(i >= sb)
            break;

        int p = (1 - inv(sb - i) + mod) % mod;
        bcnt[i + 1] = 1LL * bcnt[i] * p % mod;
    }

    int bp = 0;
    for(int i = 0; i <= m; i++)
        bp = (bp + 1LL * mem[m][m - i] * bcnt[i]) % mod;

    for(int i = 1; i <= n; i++)
    {
        if(like[i])
            res[i] = 1LL * arr[i] * ap % mod;
        else
            res[i] = 1LL * arr[i] * bp % mod;
    }

    for(int i = 1; i <= n; i++)
        printf("%d\n", res[i]);
    return 0;
}