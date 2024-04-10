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
const int N = 200005, M = 1000000007, K = 1000006;

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

int u[K];
int f[K], rf[K], r[K];
void pre()
{
    for (int i = 2; i < K; ++i)
    {
        if (u[i])
            continue;
        for (int j = i; j < K; j += i)
        {
            if (!u[j])
                u[j] = i;
        }
    }
    f[0] = 1;
    for (int i = 1; i < K; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    rf[K - 1] = ast(f[K - 1], M - 2);
    for (int i = K - 2; i >= 0; --i)
        rf[i] = (rf[i + 1] * 1LL * (i + 1)) % M;
    for (int i = 1; i < K; ++i)
        r[i] = (rf[i] * 1LL * f[i - 1]) % M;
}

int n;
int a[N];

vector<pair<int, int> > v[N];

int t[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = a[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = (t[pos * 2] * 1LL * t[pos * 2 + 1]) % M;
}

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = (t[pos] * 1LL * y) % M;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = (t[pos * 2] * 1LL * t[pos * 2 + 1]) % M;
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 1;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) * 1LL *
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1)) % M;
}

int h[K];

int ans[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int qq;
    scanf("%d", &qq);
    for (int i = 0; i < qq; ++i)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        v[r].push_back(m_p(l, i));
    }

    bil(1, n, 1);
    for (int i = 1; i <= n; ++i)
    {
        int x = a[i];
        while (x > 1)
        {
            if (h[u[x]])
                ubd(1, n, h[u[x]], (u[x] * 1LL * r[u[x] - 1]) % M, 1);
            h[u[x]] = i;
            ubd(1, n, h[u[x]], (1 - r[u[x]] + M) % M, 1);
            x /= u[x];
        }
        for (int j = 0; j < v[i].size(); ++j)
        {
            ans[v[i][j].se] = qry(1, n, v[i][j].fi, i, 1);
        }
    }
    for (int i = 0; i < qq; ++i)
        printf("%d\n", ans[i]);
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