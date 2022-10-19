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
const int N = 500005;

int n;
char a[3][N];

struct ban
{
    int ans;
    int l[3], r[3];
    ban()
    {
        ans = 0;
        for (int i = 0; i < 3; ++i)
            l[i] = r[i] = 0;
    }
    ban(char x1, char x2, char x3)
    {
        ans = 0;
        if (x1 == '0')
            l[0] = 0;
        else
            l[0] = ++ans;
        if (x2 == '0')
            l[1] = 0;
        else
        {
            if (l[0])
                l[1] = ans;
            else
                l[1] = ++ans;
        }
        if (x3 == '0')
            l[2] = 0;
        else
        {
            if (l[1])
                l[2] = ans;
            else
                l[2] = ++ans;
        }
        for (int i = 0; i < 3; ++i)
            r[i] = l[i];
    }
};

ban mer(ban l, ban r)
{
    bool c[9] = {};
    int cc[9] = {};

    ban res;
    res.ans = l.ans + r.ans;

    int ql = 0;
    for (int i = 0; i < 3; ++i)
    {
        ql = max(ql, l.l[i]);
        ql = max(ql, l.r[i]);
    }
    res.ans -= ql;

    int qr = 0;
    for (int i = 0; i < 3; ++i)
    {
        qr = max(qr, r.l[i]);
        qr = max(qr, r.r[i]);
        if (r.l[i])
            r.l[i] += ql;
        if (r.r[i])
            r.r[i] += ql;
    }
    res.ans -= qr;

    for (int i = 0; i < 3; ++i)
    {
        if (l.r[i] && r.l[i] && l.r[i] != r.l[i])
        {
            int x = r.l[i];
            int y = l.r[i];
            for (int i = 0; i < 3; ++i)
            {
                if (l.l[i] == x)
                    l.l[i] = y;
                if (l.r[i] == x)
                    l.r[i] = y;
                if (r.l[i] == x)
                    r.l[i] = y;
                if (r.r[i] == x)
                    r.r[i] = y;
            }
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        c[l.l[i]] = true;
        c[l.r[i]] = true;
        c[r.l[i]] = true;
        c[r.r[i]] = true;
    }
    for (int i = 1; i < 16; ++i)
        res.ans += c[i];

    int k = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (l.l[i])
        {
            if (!cc[l.l[i]])
                cc[l.l[i]] = ++k;
            res.l[i] = cc[l.l[i]];
        }
        if (r.r[i])
        {
            if (!cc[r.r[i]])
                cc[r.r[i]] = ++k;
            res.r[i] = cc[r.r[i]];
        }
    }

    return res;
}

ban t[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(a[0][tl], a[1][tl], a[2][tl]);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
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

void solv()
{
    cin >> n;
    for (int i = 0; i < 3; ++i)
        cin >> (a[i] + 1);

    bil(1, n, 1);

    int qq;
    cin >> qq;
    while (qq--)
    {
        int l, r;
        cin >> l >> r;
        cout << qry(1, n, l, r, 1).ans << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}