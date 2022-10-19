#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n, k;
char a[N];

vector<pair<int, int> > v[N];

long long t[N * 4];
void ubd(int tl, int tr, int x, long long y, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}
long long qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return min(qry(tl, m, l, m, pos * 2),
               qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

long long dp[N];
int main()
{
    scanf("%d%d %s", &n, &k, a + 1);
    for (int i = 1; i <= n; ++i)
    {
        v[i].push_back(m_p(i, i));
        if (a[i] == '1')
            v[min(n, i + k)].push_back(m_p(max(1, i - k), i));
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = (N * 1LL * N);
        for (int j = 0; j < v[i].size(); ++j)
        {
            int l = v[i][j].first;
            int g = v[i][j].second;
            dp[i] = min(dp[i], qry(0, n, l - 1, i - 1, 1) + g);
        }
        ubd(0, n, i, dp[i], 1);
    }
    cout << dp[n] << endl;
    return 0;
}