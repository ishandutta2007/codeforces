#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 302, M = 1000000007;

int c[N][N];
int f[N];

void pre()
{
    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
}

int n;
int a[N];

void kar()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
}

void gen()
{
    n = 9;
    for (int i = 1; i <= n; ++i)
        a[i] = rnf() % 10 + 1;
}

bool stg(int x, int y)
{
    ll u = x * 1LL * y;
    int s = sqrt(u);
    for (int i = s - 3; i <= s + 3; ++i)
    {
        if ((i * 1LL * i) == u)
            return true;
    }
    return false;
}

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

int q[N];

int dp[N][N];

int solv()
{
    memset(dp, 0, sizeof dp);
    memset(q, 0, sizeof q);
    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (stg(a[i], a[j]))
            {
                kpc(i, j);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        q[fi(i)]++;
    }
    int qq = 0;
    dp[0][1] = 1;
    for (int i = 0; i < n; ++i)
    {
        if (q[i + 1] == 0)
        {
            for (int l = 0; l <= qq + 1; ++l)
            {
                dp[i + 1][l] = dp[i][l];
            }
            continue;
        }
        for (int l = 0; l <= qq + 1; ++l)
        {
            if (!dp[i][l])
                continue;
            int v = (qq + 1) - l;
            for (int k = 1; k <= q[i + 1]; ++k)
            {
                for (int ql = 0; ql <= l; ++ql)
                {
                    int qv = k - ql;
                    if (ql > l || qv > v || v < 0 || qv < 0)
                        continue;
                    int u = dp[i][l];
                    u = (u * 1LL * c[q[i + 1] - 1][k - 1]) % M;
                    u = (u * 1LL * f[q[i + 1]]) % M;
                    u = (u * 1LL * c[l][ql]) % M;
                    u = (u * 1LL * c[v][qv]) % M;
                    dp[i + 1][l + qv + k] = (dp[i + 1][l + qv + k] + u) % M;
                }
            }
        }
        qq += q[i + 1];
    }
    /*for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n + 1; ++j)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }*/
    return dp[n][n + 1];
}

int solv0()
{
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    int ans = 0;
    do
    {
        bool z = true;
        for (int i = 1; i < n; ++i)
        {
            if (stg(a[p[i]], a[p[i + 1]]))
            {
                z = false;
                break;
            }
        }
        ans += z;
    } while (next_permutation(p + 1, p + n + 1));
    return ans;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    pre();
    kar();
    printf("%d\n", solv());
    return 0;
    int tt;
    tt = 1000;
    while (tt--)
    {
        gen();
        if (solv() != solv0())
        {
            printf("WA\n");
            printf("%d\n", n);
            for (int i = 1; i <= n; ++i)
                printf("%d ", a[i]);
            printf("\n");
            return 0;
        }
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}