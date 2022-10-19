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
const int N = 102;
const pair<int, int> M = m_p(997469959, 981692099);

bool prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if ((x % i) == 0)
            return false;
    }
    return true;
}

pair<int, int> sum(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi + b.fi) % M.fi, (a.se + b.se) % M.se);
}

pair<int, int> pro(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi * 1LL * b.fi) % M.fi, (a.se * 1LL * b.se) % M.se);
}

pair<int, int> dif(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi - b.fi + M.fi) % M.fi, (a.se - b.se + M.se) % M.se);
}

int n;
int a[N];
int m;
int qq[N];

pair<int, int> dp[N][N * N];

pair<int, int> c[N][N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        m += a[i];
        ++qq[a[i]];
    }

    for (int i = 0; i < N; ++i)
    {
        c[i][0] = m_p(1, 1);
        for (int j = 1; j <= i; ++j)
            c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
    }

    dp[0][0] = m_p(1, 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int q = n; q >= 0; --q)
        {
            for (int s = 0; s <= m - a[i]; ++s)
            {
                dp[q + 1][s + a[i]] = sum(dp[q + 1][s + a[i]], dp[q][s]);
            }
        }
    }

    int ans = 0;
    for (int q = 1; q <= n; ++q)
    {
        for (int s = 0; s <= m; ++s)
        {
            if (s % q == 0 && s / q <= 100 && qq[s / q] >= q && dp[q][s] == c[qq[s / q]][q])
            {
                ans = max(ans, q);
                if (qq[s / q] == q)
                {
                    int u = -1;
                    for (int i = 1; i <= n; ++i)
                    {
                        if (a[i] == s / q)
                            continue;
                        if (u == -1)
                        {
                            u = a[i];
                        }
                        else
                        {
                            if (u != a[i])
                            {
                                u = -2;
                                break;
                            }
                        }
                    }
                    if (u != -2)
                        ans = max(ans, n);
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    /*int x = 900000000 + rnd() % 100000000;
    while (!prime(x))
        ++x;
    printf("%d\n", x);*/
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}