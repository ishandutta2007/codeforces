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
const int N = 200005;

int n;
int a[N];

int u[N];

int dp[N];
int p[N];

pair<int, int> t[N * 4];

void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos] = m_p(a[x], x);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

pair<int, int> qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return m_p(N, 0);
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return min(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int ans[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i - 1] > a[i])
            u[i] = u[i - 1];
        else
            u[i] = i;
    }
    for (int i = 0; i < N * 4; ++i)
        t[i] = m_p(N, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (i > 1)
        {
            if (dp[i - 1] > a[i])
            {
                ubd(1, n, i - 1, 1);
            }
        }
        dp[i] = -1;
        if (i == 1)
        {
            dp[i] = N;
            p[i] = 0;
            continue;
        }
        if (a[i - 1] < a[i])
        {
            dp[i] = dp[i - 1];
            p[i] = i - 1;
        }
        if (u[i - 1] == 1)
        {
            if (a[i - 1] > dp[i])
            {
                dp[i] = a[i - 1];
                p[i] = 0;
            }
            continue;
        }
        pair<int, int> t = qry(1, n, u[i - 1] - 1, i - 2, 1);
        if (t.fi < a[i])
        {
            if (a[i - 1] > dp[i])
            {
                dp[i] = a[i - 1];
                p[i] = t.se;
            }
        }
    }
    /*for (int i = 1; i <= n; ++i)
        printf("%d ", dp[i]);
    printf("\n");*/
    for (int i = 1; i <= n; ++i)
    {
        if (dp[i] != -1 && (i == n || dp[i] > a[i + 1]) && u[n] <= i + 1)
        {
            printf("YES\n");
            for (int i = 1; i <= n; ++i)
                ans[i] = 1;
            while (i)
            {
                ans[i] = 0;
                i = p[i];
            }
            for (int i = 1; i <= n; ++i)
                printf("%d ", ans[i]);
            printf("\n");
            return;
        }
    }
    printf("NO\n");
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