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
const int N = 20010, M = 1000000007;

int n;
char a[N];
int m;
char b[N];

char c[N];
int d[N];

int dp[N];
int ndp[N];

int solv()
{
    int q;
    scanf("%d", &q);

    scanf(" %s", a);
    n = strlen(a);
    n++;
    for (int i = 0; i < n; ++i)
        dp[i] = 1;

    q--;
    while (q--)
    {
        scanf(" %s", b);
        m = strlen(b);
        m++;
        for (int i = 0; i < m; ++i)
            ndp[i] = 0;
        for (int i = n; i < m; ++i)
            a[i] = 0;
        for (int i = m; i < n; ++i)
            b[i] = 0;
        for (int i = 0; i < max(n, m); ++i)
            c[i] = 0;

        for (int i = 0; i < n; ++i)
        {
            int k = 0;
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                c[k++] = a[j];
            }
            int u = N;
            for (int i = 0; i < max(n, m); ++i)
            {
                if (c[i] != b[i])
                {
                    u = i;
                    break;
                }
            }
            d[m] = N;
            for (int i = m - 1; i >= 0; --i)
            {
                if (c[i] != b[i + 1])
                    d[i] = i;
                else
                    d[i] = d[i + 1];
            }

            if (u != N && c[u] < b[u])
            {
                for (int j = u + 1; j < m; ++j)
                {
                    ndp[j] = (ndp[j] + dp[i]) % M;
                }
            }
            for (int j = 0; j <= u; ++j)
            {
                if (d[j] == N || c[d[j]] < b[d[j] + 1])
                    ndp[j] = (ndp[j] + dp[i]) % M;
            }
        }

        n = m;
        for (int i = 0; i < n; ++i)
            a[i] = b[i];
        a[n] = 0;
        for (int i = 0; i < n; ++i)
            dp[i] = ndp[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = (ans + dp[i]) % M;
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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}