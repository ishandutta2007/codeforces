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
const int N = 100005, M = 1000000007;

int dp0[2];

void ave0(int dp1[2])
{
    int ndp0[2];
    ndp0[0] = (dp0[0] * 1LL * dp1[0] + dp0[1] * 1LL * dp1[1]) % M;
    ndp0[1] = (dp0[0] * 1LL * dp1[1] + dp0[1] * 1LL * dp1[0]) % M;
    dp0[0] = ndp0[0];
    dp0[1] = ndp0[1];
}

int n, m;
int k[N];
int a[N][2];

int u[N][2];
int uu[N][2];

bool c[N];

vector<int> v;
void dfs0(int x)
{
    c[x] = true;
    v.push_back(x);
    for (int j = 0; j < k[x]; ++j)
    {
        if (u[abs(a[x][j])][1])
        {
            if (!c[u[abs(a[x][j])][(uu[x][j] ^ 1)]])
            {
                dfs0(u[abs(a[x][j])][(uu[x][j] ^ 1)]);
            }
        }
    }
}

int dp[2][2][2];
void ave(int x)
{
    int ndp[2][2][2] = {};
    for (int s = 0; s < 2; ++s)
    {
        for (int q = 0; q < 2; ++q)
        {
            for (int v = 0; v < 2; ++v)
            {
                if (x == 0)
                {
                    ndp[s][q][0] = (ndp[s][q][0] + dp[s][q][v]) % M;
                    if (v == 0)
                        ndp[s][(q + 2) % 2][1] = (ndp[s][(q + 2) % 2][1] + dp[s][q][v]) % M;
                    else
                        ndp[s][(q + 1) % 2][1] = (ndp[s][(q + 1) % 2][1] + dp[s][q][v]) % M;
                }
                else
                {
                    ndp[s][(q + 1) % 2][1] = (ndp[s][(q + 1) % 2][1] + dp[s][q][v]) % M;
                    if (v == 0)
                        ndp[s][(q + 1) % 2][0] = (ndp[s][(q + 1) % 2][0] + dp[s][q][v]) % M;
                    else
                        ndp[s][q][0] = (ndp[s][q][0] + dp[s][q][v]) % M;
                }
            }
        }
    }
    memcpy(dp, ndp, sizeof ndp);
}

void ave1()
{
    int ndp[2][2][2] = {};
    for (int s = 0; s < 2; ++s)
    {
        for (int q = 0; q < 2; ++q)
        {
            for (int v = 0; v < 2; ++v)
            {
                if (v == 0)
                {
                    ndp[s][q][0] = (ndp[s][q][0] + dp[s][q][v]) % M;
                    ndp[s][(q + 1) % 2][1] = (ndp[s][(q + 1) % 2][1] + dp[s][q][v]) % M;
                }
                else
                {
                    ndp[s][q][0] = (ndp[s][q][0] + dp[s][q][v]) % M;
                    ndp[s][q][1] = (ndp[s][q][1] + dp[s][q][v]) % M;
                }
            }
        }
    }
    memcpy(dp, ndp, sizeof ndp);
}

int hat(int i, int j)
{
    for (int ii = 0; ii < 2; ++ii)
    {
        for (int jj = 0; jj < 2; ++jj)
        {
            if (abs(a[i][ii]) == abs(a[j][jj]))
            {
                if (a[i][ii] != a[j][jj])
                    return 1;
                return 0;
            }
        }
    }
    assert(false);
}

int hat1(int i, int j)
{
    for (int ii = 1; ii >= 0; --ii)
    {
        for (int jj = 0; jj < 2; ++jj)
        {
            if (abs(a[i][ii]) == abs(a[j][jj]))
            {
                if (a[i][ii] != a[j][jj])
                    return 1;
                return 0;
            }
        }
    }
    assert(false);
}

void pro0()
{
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    if (k[v[0]] == 2)
        ave1();
    for (int i = 0; i < v.size() - 1; ++i)
    {
        ave(hat(v[i], v[i + 1]));
    }
    if (k[v.back()] == 2)
    {
        ave1();
    }
    int dp1[2] = {};
    for (int s = 0; s < 2; ++s)
    {
        for (int q = 0; q < 2; ++q)
        {
            for (int v = 0; v < 2; ++v)
            {
                dp1[q] = (dp1[q] + dp[s][q][v]) % M;
            }
        }
    }
    ave0(dp1);
}

void pro1()
{
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    dp[1][1][1] = 1;
    for (int i = 0; i < v.size() - 1; ++i)
    {
        ave(hat(v[i], v[i + 1]));
    }
    ave1();
    int dp1[2] = {};
    for (int s = 0; s < 2; ++s)
    {
        for (int q = 0; q < 2; ++q)
        {
            for (int vv = 0; vv < 2; ++vv)
            {
                if ((s ^ vv) == hat1(v[0], v.back()))
                {
                    dp1[q] = (dp1[q] + dp[s][q][vv]) % M;
                }
            }
        }
    }
    ave0(dp1);
}

void solv()
{
    dp0[0] = 1;
    dp0[1] = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &k[i]);
        for (int j = 0; j < k[i]; ++j)
        {
            scanf("%d", &a[i][j]);
            if (!u[abs(a[i][j])][0])
            {
                u[abs(a[i][j])][0] = i;
                uu[i][j] = 0;
            }
            else
            {
                u[abs(a[i][j])][1] = i;
                uu[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (k[i] == 1)
        {
            if (!u[abs(a[i][0])][1])
            {
                c[i] = true;
                int dp1[2] = {};
                dp1[0] = 1;
                dp1[1] = 1;
                ave0(dp1);
            }
        }
        else
        {
            if (!u[abs(a[i][0])][1] && !u[abs(a[i][1])][1])
            {
                c[i] = true;
                int dp1[2] = {};
                dp1[0] = 1;
                dp1[1] = 3;
                ave0(dp1);
            }
            if (abs(a[i][0]) == abs(a[i][1]))
            {
                c[i] = true;
                int dp1[2] = {};
                if (a[i][0] == a[i][1])
                {
                    dp1[0] = 1;
                    dp1[1] = 1;
                }
                else
                {
                    dp1[0] = 0;
                    dp1[1] = 2;
                }
                ave0(dp1);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;
        if (k[i] == 1)
        {
            v.clear();
            dfs0(i);
            pro0();
        }
        else
        {
            if (!u[abs(a[i][0])][1] && u[abs(a[i][1])][1])
            {
                v.clear();
                dfs0(i);
                pro0();
            }
            else if (u[abs(a[i][0])][1] && !u[abs(a[i][1])][1])
            {
                v.clear();
                dfs0(i);
                pro0();
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;
        v.clear();
        dfs0(i);
        pro1();
    }

    memset(c, false, sizeof c);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < k[i]; ++j)
        {
            c[abs(a[i][j])] = true;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        if (!c[i])
        {
            int dp1[2] = {};
            dp1[0] = 2;
            ave0(dp1);
        }
    }

    printf("%d\n", dp0[1]);
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