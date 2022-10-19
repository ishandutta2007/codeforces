#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 300005;

int n, m, c;
int x[N], d[N];
long double p[N];
int q[N];

struct ban
{
    long double l, r, s, ans;
    ban()
    {
        l = r = s = ans = 0;
    }
    ban(long double x)
    {
        if (x < 0)
        {
            l = r = ans = 0;
            s = x;
        }
        else
        {
            l = r = ans = s = x;
        }
    }
};

ban t[N * 4];

ban mer(const ban& l, const ban& r)
{
    ban ans;
    ans.s = l.s + r.s;
    ans.l = max(l.l, l.s + r.l);
    ans.r = max(r.r, r.s + l.r);
    ans.ans = max(max(l.ans, r.ans), l.r + r.l);
    return ans;
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban((d[tl] / 2.0 - p[tl] * c));
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return ban();
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return mer(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    scanf("%d%d%d", &n, &m, &c);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);
    for (int i = 1; i < n; ++i)
        d[i] = x[i + 1] - x[i];
    for (int i = 1; i < n; ++i)
    {
        int pp;
        scanf("%d", &pp);
        p[i] = (pp / 100.0);
    }
    bil(1, n - 1, 1);
    long double ans = 0;
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        --y;
        ans += qry(1, n - 1, x, y, 1).ans;
    }
    cout << ans << endl;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    solv();
    return 0;
}