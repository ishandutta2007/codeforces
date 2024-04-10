#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 3000006;

int n, m;
char a[N], b[N], c[N];

int k;
char u[N];
int z[N];
void solv()
{
    memset(z, 0, sizeof z);
    int j = 0;
    int r = 0;
    for (int i = 1; i < k; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - j]);
        while (u[i + z[i]] == u[z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            j = i;
        }
    }
}

int da[N], db[N];

pair<int, long long> t[N * 4];
pair<int, long long> mer(const pair<int, long long>& a, const pair<int, long long>& b)
{
    return m_p(a.first + b.first, a.second + b.second);
}
void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos].first++;
        t[pos].second += x;
        if (x == m)
            --t[pos].second;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

pair<int, long long> qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return m_p(0, 0);
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return mer(qry(tl, m, l, min(m, r), pos * 2),
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

vector<int> v[N];
map<int, pair<int, long long> > mp[N];

int main()
{
    scanf("%d%d", &n, &m);
    scanf(" %s %s %s", (a + 1), (b + 1), (c + 1));
    k = 0;
    for (int i = 1; i <= m; ++i)
        u[k++] = c[i];
    u[k++] = '#';
    for (int i = 1; i <= n; ++i)
        u[k++] = a[i];
    u[k] = 0;
    solv();
    for (int i = 1; i <= n; ++i)
        da[i] = z[i + m];
    k = 0;
    for (int i = m; i >= 1; --i)
        u[k++] = c[i];
    u[k++] = '#';
    for (int i = n; i >= 1; --i)
        u[k++] = b[i];
    u[k] = 0;
    solv();
    for (int i = n; i >= 1; --i)
        db[i] = z[(n - i) + m + 1];
    long long ans = 0;
    for (int i = n; i >= 1; --i)
        v[i + m - 1].push_back(m - da[i]);
    for (int i = n; i >= 1; --i)
    {
        ubd(0, m, db[i], 1);
        for (int j = 0; j < v[i].size(); ++j)
        {
            mp[i][v[i][j]] = qry(0, m, max(1, v[i][j]), m, 1);
        }
        if (da[i])
        {
            pair<int, long long> u = qry(0, m, max(1, m - da[i]), m, 1);
            u.first -= mp[i + m - 1][m - da[i]].first;
            u.second -= mp[i + m - 1][m - da[i]].second;
            ans += u.first * 1LL * da[i];
            ans += u.second;
            ans -= u.first * 1LL * m;
            ans += u.first;
            if (da[i] == m)
                ans -= u.first;
        }
    }
    printf("%lld\n", ans);
    return 0;
}