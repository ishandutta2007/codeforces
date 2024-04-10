#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1000006, M = 1000000007;

int n, k;
long long l;
int a[N];

int dp[N];

int t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = (t[pos] + y) % M;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = (t[pos * 2] + t[pos * 2 + 1]) % M;
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1)) % M;
}

int main()
{
    scanf("%d%lld%d", &n, &l, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    vector<int> v;
    int z = 0;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i)
    {
        if (!i || v[i] != v[i - 1])
            mp[v[i]] = ++z;
    }
    for (int i = 1; i <= n; ++i)
        a[i] = mp[a[i]];
    int ans = 0;
    for (int i = 1; i <= k; ++i)
    {
        for (int i = 0; i <= (z + 5) * 4; ++i)
            t[i] = 0;
        if (i == 1)
            ubd(1, z, 1, 1, 1);
        for (int i = 1; i <= n; ++i)
            ubd(1, z, a[i], dp[i], 1);
        for (int i = 1; i <= n; ++i)
            dp[i] = qry(1, z, 1, a[i], 1);
        if (i > (l / n) + !!(l % n))
            break;
        if (i <= (l / n))
        {
            int s = 0;
            for (int i = 1; i <= n; ++i)
                s = (s + dp[i]) % M;
            ans = (ans + ((((l / n) - i + 1) % M) * 1LL * s) % M) % M;
        }
        for (int i = 1; i <= (l % n); ++i)
            ans = (ans + dp[i]) % M;
    }
    printf("%d\n", ans);
    return 0;
}