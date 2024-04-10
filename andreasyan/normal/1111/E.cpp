#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 1000000007;

int n, q;
vector<int> a[N];

vector<int> v;
int h[N];
void dfs(int x, int p)
{
    h[x] = h[p] + 1;
    v.push_back(x);
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        v.push_back(x);
    }
}

int lca_t[N * 8];
void lca_bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        lca_t[pos] = v[tl];
        return;
    }
    int m = (tl + tr) / 2;
    lca_bil(tl, m, pos * 2);
    lca_bil(m + 1, tr, pos * 2 + 1);
    if (h[lca_t[pos * 2]] < h[lca_t[pos * 2 + 1]])
        lca_t[pos] = lca_t[pos * 2];
    else
        lca_t[pos] = lca_t[pos * 2 + 1];
}

int lca_qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return lca_t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return lca_qry(tl, m, l, r, pos * 2);
    if (l > m)
        return lca_qry(m + 1, tr, l, r, pos * 2 + 1);
    int x = lca_qry(tl, m, l, m, pos * 2);
    int y = lca_qry(m + 1, tr, m + 1, r, pos * 2 + 1);
    if (h[x] < h[y])
        return x;
    return y;
}

int first[N * 2], last[N * 2];
void lca_pre()
{
    dfs(1, 1);
    lca_bil(0, v.size() - 1, 1);

    for (int i = 1; i <= n; ++i)
        first[i] = last[i] = -1;
    for (int i = 0; i < v.size(); ++i)
    {
        if (first[v[i]] == -1)
            first[v[i]] = i;
        last[v[i]] = i;
    }
}

int lca(int x, int y)
{
    return lca_qry(0, v.size() - 1, min(first[x], first[y]), max(first[x], first[y]), 1);
}

int t[N * 8];
void t_ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (tl == l && tr == r)
    {
        t[pos] += y;
        return;
    }
    int m = (tl + tr) / 2;
    if (r <= m)
        t_ubd(tl, m, l, r, y, pos * 2);
    else if (l > m)
        t_ubd(m + 1, tr, l, r, y, pos * 2 + 1);
    else
    {
        t_ubd(tl, m, l, m, y, pos * 2);
        t_ubd(m + 1, tr, m + 1, r, y, pos * 2 + 1);
    }
}

int t_qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return t[pos];
    int m = (tl + tr) / 2;
    if (x <= m)
        return t[pos] + t_qry(tl, m, x, pos * 2);
    return t[pos] + t_qry(m + 1, tr, x, pos * 2 + 1);
}

int k, m, r;
int b[N];

bool c[N];

int d[N];

void qry()
{
    cin >> k >> m >> r;
    for (int i = 1; i <= k; ++i)
        cin >> b[i];

    for (int i = 1; i <= k; ++i)
    {
        c[b[i]] = true;
        t_ubd(0, v.size() - 1, first[b[i]], last[b[i]], 1, 1);
    }

    for (int i = 1; i <= k; ++i)
    {
        int x = lca(b[i], r);
        d[i] = t_qry(0, v.size() - 1, first[b[i]], 1) + t_qry(0, v.size() - 1, first[r], 1) - 2 * t_qry(0, v.size() - 1, first[x], 1) + c[x] - 1;
    }

    sort(d + 1, d + k + 1);
    int dp[302] = {}, dpn[302] = {};
    dp[0] = 1;
    dpn[0] = 1;
    for (int i = 1; i <= k; ++i)
    {
        memset(dp, 0, sizeof dp);
        for (int j = 0; j <= m; ++j)
        {
            if (j + 1 <= m)
            {
                dp[j + 1] += dpn[j];
                dp[j + 1] %= M;
            }
            if (j - d[i] >= 0)
            {
                dp[j] += ((1LL * dpn[j] * (j - d[i])) % M);
                dp[j] %= M;
            }
        }
        memcpy(dpn, dp, sizeof dp);
    }

    int ans = 0;
    for (int j = 0; j <= m; ++j)
    {
        ans += dp[j];
        ans %= M;
    }
    cout << ans << endl;

    for (int i = 1; i <= k; ++i)
    {
        c[b[i]] = false;
        t_ubd(0, v.size() - 1, first[b[i]], last[b[i]], -1, 1);
    }
}

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    lca_pre();
    while (q--)
        qry();
    return 0;
}