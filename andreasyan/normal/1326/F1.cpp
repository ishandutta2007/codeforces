#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 15;

int n;
char a[N][N];

int dp[(1 << N)][(1 << (N / 2))][N];

int r[(1 << N)];

long long ans[(1 << N)];

void solv0()
{
    memset(ans, 0, sizeof ans);
    int u[N];
    for (int i = 0; i < n; ++i)
        u[i] = i;
    do
    {
        int x = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (a[u[i]][u[i + 1]] == '1')
                x |= (1 << i);
        }
        ans[x]++;
    } while (next_permutation(u, u + n));
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf(" %s", a[i]);
    vector<int> v;
    for (int x = 1; x < (1 << n); ++x)
    {
        int q = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
            {
                ++q;
            }
        }
        if (q == 1)
        {
            for (int i = 0; i < n; ++i)
            {
                if ((x & (1 << i)))
                    dp[x][0][i] = 1;
            }
        }
        if (q == (n / 2) + (n % 2))
            v.push_back(x);
        if (q >= (n / 2) + (n % 2))
            continue;
        for (int y = 0; y < (1 << (q - 1)); ++y)
        {
            for (int i = 0; i < n; ++i)
            {
                if (!dp[x][y][i])
                    continue;
                for (int j = 0; j < n; ++j)
                {
                    if ((x & (1 << j)))
                        continue;
                    if (a[i][j] == '1')
                        dp[(x | (1 << j))][(y | (1 << (q - 1)))][j] += dp[x][y][i];
                    else
                        dp[(x | (1 << j))][y][j] += dp[x][y][i];
                }
            }
        }
    }
    int q = (n / 2);
    for (int x = 0; x < (1 << (q - 1)); ++x)
    {
        for (int i = 0; i < (q - 1); ++i)
        {
            if ((x & (1 << i)))
                r[x] |= (1 << (q - 1 - i - 1));
        }
    }
    for (int ii = 0; ii < v.size(); ++ii)
    {
        int q = (n / 2) + (n % 2);
        int x = v[ii];
        int y = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!(x & (1 << i)))
                y |= (1 << i);
        }
        for (int i = 0; i < n; ++i)
        {
            if (!(x & (1 << i)))
                continue;
            for (int j = 0; j < n; ++j)
            {
                if (!(y & (1 << j)))
                    continue;
                for (int zx = 0; zx < (1 << (q - 1)); ++zx)
                {
                    if (!dp[x][zx][i])
                        continue;
                    for (int zy = 0; zy < (1 << ((n - q) - 1)); ++zy)
                    {
                        if (!dp[y][zy][j])
                            continue;
                        if (a[i][j] == '1')
                        {
                            ans[(zx | (1 << (q - 1)) | (r[zy] << q))] += (dp[x][zx][i] * 1LL * dp[y][zy][j]);
                        }
                        else
                        {
                            ans[(zx | (r[zy] << q))] += (dp[x][zx][i] * 1LL * dp[y][zy][j]);
                        }
                    }
                }
            }
        }
    }
    for (int x = 0; x < (1 << (n - 1)); ++x)
    {
        printf("%I64d ", ans[x]);
    }
    printf("\n");
    return 0;
    solv0();
    for (int x = 0; x < (1 << (n - 1)); ++x)
    {
        printf("%I64d ", ans[x]);
    }
    printf("\n");
    return 0;
}