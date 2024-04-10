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
const int N = 1000006, M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int f[N], rf[N];

void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    rf[N - 1] = ast(f[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
        rf[i] = (rf[i + 1] * 1LL * (i + 1)) % M;
}

int c(int n, int k)
{
    if (n < k)
        return 0;
    return (((f[n] * 1LL * rf[k]) % M) * 1LL * rf[n - k]) % M;
}

int n, k;

int dp[N];

int t[N * 4];
int laz[N * 4];

void shi(int pos)
{
    if (laz[pos] == 1)
        return;
    t[pos * 2] = (t[pos * 2] * 1LL * laz[pos]) % M;
    t[pos * 2 + 1] = (t[pos * 2 + 1] * 1LL * laz[pos]) % M;
    laz[pos * 2] = (laz[pos * 2] * 1LL * laz[pos]) % M;
    laz[pos * 2 + 1] = (laz[pos * 2 + 1] * 1LL * laz[pos]) % M;
    laz[pos] = 1;
}

void ubd0(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd0(tl, m, x, y, pos * 2);
    else
        ubd0(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = (t[pos * 2] + t[pos * 2 + 1]) % M;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos] = (t[pos] * 1LL * y) % M;
        laz[pos] = (laz[pos] * 1LL * y) % M;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    t[pos] = (t[pos * 2] + t[pos * 2 + 1]) % M;
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1)) % M;
}

void solv()
{
    for (int i = 0; i < N * 4; ++i)
        laz[i] = 1;
    scanf("%d%d", &n, &k);
    dp[0] = 1;
    ubd0(0, n, 0, dp[0], 1);
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = qry(0, n, max(i - k, 0), i, 1);
        ubd0(0, n, i, dp[i], 1);
        ubd(0, n, 0, i - 1, i - 1, 1);
        //printf("%d ", dp[i]);
    }
    //printf("\n");
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = (ans + (((c(n - 1, i - 1) * 1LL * dp[i]) % M) * 1LL * f[n - i]) % M) % M;
    }
    ans = (f[n] - ans + M) % M;
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}