#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;

int n, d;
long long h[N];

long long hh[N];
int z;
map<long long, int> mp;

pair<int, int> t[N * 4];

pair<int, int> mer(const pair<int, int>& l, const pair<int, int>& r)
{
    if (l.first > r.first)
        return l;
    return r;
}

void ubd(int tl, int tr, int x, pair<int, int> y, int pos)
{
    if (tl == tr)
    {
        t[pos] = mer(t[pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

pair<int, int> qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return m_p(0, 0);
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return mer(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int dp[N];
int p[N];

int main()
{
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &h[i]);
        hh[i] = h[i];
    }
    sort(hh + 1, hh + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (hh[i] != hh[i - 1])
            mp[hh[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        int l = 1, r = n;
        int ll = n + 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (hh[m] >= h[i] + d)
            {
                ll = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        l = 1, r = n;
        int rr = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (hh[m] <= h[i] - d)
            {
                rr = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        pair<int, int> u = mer(qry(1, n, 1, rr, 1), qry(1, n, ll, n, 1));
        dp[i] = u.first + 1;
        p[i] = u.second;
        ubd(1, n, mp[h[i]], m_p(dp[i], i), 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i)
    {
        if (dp[i] == ans)
        {
            vector<int> ans;
            while (i)
            {
                ans.push_back(i);
                i = p[i];
            }
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); ++i)
                printf("%d ", ans[i]);
            printf("\n");
            return 0;
        }
    }
    return 0;
}