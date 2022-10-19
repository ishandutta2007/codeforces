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

int n, q;
char a[N];

struct ban
{
    int bl, br;
    int pl, pr;
    int ansl, ansr;
    int ans;
    int s;
    ban()
    {
        bl = br = 0;
        pl = pr = 0;
        ansl = ansr = 0;
        ans = 0;
        s = 0;
    }
    ban(char x)
    {
        if (x == '>')
        {
            pl = pr = 1;
            bl = br = 0;
        }
        else
        {
            pl = pr = 0;
            bl = br = 1;
        }
        ansl = ansr = 1;
        ans = 1;
        s = 1;
    }
};

ban t[N * 4], rt[N * 4];

ban mer(const ban& l, const ban& r)
{
    ban res;

    if (l.bl == l.s)
        res.bl = l.bl + r.bl;
    else
        res.bl = l.bl;

    if (l.pl == l.s)
        res.pl = l.pl + r.pl;
    else
        res.pl = l.pl;

    if (r.br == r.s)
        res.br = r.br + l.br;
    else
        res.br = r.br;

    if (r.pr == r.s)
        res.pr = r.pr + l.pr;
    else
        res.pr = r.pr;


    if (l.ansl == l.s)
    {
        if (l.pl == l.s)
        {
            res.ansl = l.s + r.ansl;
        }
        else
        {
            res.ansl = l.s + r.bl;
        }
    }
    else
    {
        res.ansl = l.ansl;
    }

    if (r.ansr == r.s)
    {
        if (r.br == r.s)
        {
            res.ansr = r.s + l.ansr;
        }
        else
        {
            res.ansr = r.s + l.pr;
        }
    }
    else
    {
        res.ansr = r.ansr;
    }

    res.ans = max(l.ans, r.ans);
    res.ans = max(res.ans, l.ansr + r.bl);
    res.ans = max(res.ans, r.ansl + l.pr);

    res.s = l.s + r.s;
    return res;
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(a[tl]);
        if (a[tl] == '<')
            rt[pos] = ban('>');
        else
            rt[pos] = ban('<');
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
    rt[pos] = mer(rt[pos * 2], rt[pos * 2 + 1]);
}

bool laz[N * 4];
void shi(int pos)
{
    if (!laz[pos])
        return;
    laz[pos * 2] ^= true;
    laz[pos * 2 + 1] ^= true;
    swap(t[pos * 2], rt[pos * 2]);
    swap(t[pos * 2 + 1], rt[pos * 2 + 1]);
    laz[pos] = false;
}

void ubd(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        laz[pos] ^= true;
        swap(t[pos], rt[pos]);
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
    rt[pos] = mer(rt[pos * 2], rt[pos * 2 + 1]);
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
    {
        return ban();
    }
    if (tl == l && tr == r)
        return t[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    return mer(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    scanf("%d%d", &n, &q);
    scanf(" %s", (a + 1));
    bil(1, n, 1);
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        ubd(1, n, l, r, 1);
        printf("%d\n", qry(1, n, l, r, 1).ans);
    }
}

void por()
{
    int n;
    n = 11;
    for (int x = 0; x < (1 << n); ++x)
    {
        for (int i = 1; i <= n; ++i)
        {
            if ((x & (1 << (i - 1))))
                a[i] = '>';
            else
                a[i] = '<';
        }
        vector<pair<char, int> > v;
        int q = 1;
        for (int i = 2; i <= n; ++i)
        {
            if (a[i] == a[i - 1])
            {
                ++q;
            }
            else
            {
                v.push_back(m_p(a[i - 1], q));
                q = 1;
            }
        }
        v.push_back(m_p(a[n], q));
        int ans = 0;
        for (int i = 0; i < sz(v); ++i)
        {
            ans = max(ans, v[i].se);
            if (i < sz(v) - 1 && v[i].fi == '>' && v[i + 1].fi == '<')
                ans = max(ans, v[i].se + v[i + 1].se);
        }

        bil(1, n, 1);
        if (ans != t[1].ans)
        {
            for (int i = 1; i <= n; ++i)
                printf("%c", a[i]);
            printf("\n");
            printf("%d\n", t[1].ans);
            bil(1, n, 1);
            return;
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    //por();
    //return 0;
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}