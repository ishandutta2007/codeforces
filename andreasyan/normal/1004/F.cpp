#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005, m = 20;

int n, qq, xx;
int a[N];

struct ban
{
    vector<pair<int, int> > l, r;
    long long ans;
    int q;
    ban()
    {
        ans = 0;
        q = 0;
    }
    ban(int x)
    {
        ans = 0;
        for (int i = 0; i < m; ++i)
        {
            if ((x & (1 << i)))
            {
                l.push_back(m_p(1, i));
                r.push_back(m_p(1, i));
            }
        }
        if (x >= xx)
            ++ans;
        q = 1;
    }
};

int gett(const vector<int>& pp, int j)
{
    if (j == -1)
        return 0;
    if (j == pp.size())
        return (1 << m) - 1;
    return pp[j];
}

bool c[m];
ban mer(const ban& l, const ban& r)
{
    ban res;
    res.l = l.l;
    memset(c, false, sizeof c);
    for (int i = 0; i < res.l.size(); ++i)
        c[res.l[i].second] = true;
    for (int i = 0; i < r.l.size(); ++i)
        if (!c[r.l[i].second])
            res.l.push_back(m_p(l.q + r.l[i].first, r.l[i].second));
    memset(c, false, sizeof c);
    res.r = r.r;
    for (int i = 0; i < res.r.size(); ++i)
        c[res.r[i].second] = true;
    for (int i = 0; i < l.r.size(); ++i)
        if (!c[l.r[i].second])
            res.r.push_back(m_p(r.q + l.r[i].first, l.r[i].second));
    res.q = l.q + r.q;
    res.ans = l.ans + r.ans;
    vector<int> pp;
    pp.assign(l.r.size(), 0);
    for (int i = 0; i < (int)l.r.size(); ++i)
    {
        if (i)
            pp[i] = pp[i - 1];
        pp[i] |= (1 << l.r[i].second);
    }
    int j = l.r.size();
    int yp = 0;
    for (int i = -1; i < (int)r.l.size(); ++i)
    {
        if (i != -1)
            yp |= (1 << r.l[i].second);
        while ((j - 1 >= -1) && (gett(pp, j - 1) | yp) >= xx)
            --j;
        int qi;
        if (i == (int)r.l.size() - 1)
        {
            if (r.l.empty())
                qi = r.q;
            else
                qi = r.q - r.l.back().first + 1;
        }
        else if (i == -1)
            qi = r.l[0].first - 1;
        else
            qi = r.l[i + 1].first - r.l[i].first;
        int qj;
        if (j == (int)l.r.size())
            qj = 0;
        else if (j == (int)l.r.size() - 1)
        {
            if (l.r.empty())
                qj = l.q;
            else
                qj = l.q - l.r.back().first + 1;
        }
        else if (j == -1)
            qj = l.q;
        else
            qj = l.q - l.r[j].first + 1;
        res.ans += (qi * 1LL * qj);
    }
    return res;
}

ban t[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(a[tl]);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}
ban qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return mer(qry(tl, m, l, m, pos * 2),
               qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

int ka()
{
    int x = 0;
    while (1)
    {
        char y;
        y = getchar();
        if ('0' <= y && y <= '9')
            x = (x * 10) + (y - '0');
        else
            return x;
    }
}

char u[20];
void tp(long long x)
{
    if (x == 0)
    {
        putchar('0');
    }
    else
    {
        int k = 0;
        while (x)
        {
            u[k++] = (x % 10) + '0';
            x /= 10;
        }
        for (int i = k - 1; i >= 0; --i)
            putchar(u[i]);
    }
    putchar('\n');
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &qq, &xx);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    bil(1, n, 1);
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            ubd(1, n, x, y, 1);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", qry(1, n, l, r, 1).ans);
        }
    }
    return 0;
}