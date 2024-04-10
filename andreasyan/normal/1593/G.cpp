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
const int N = 1000006;

int n;
char a[N];

struct ban
{
    int e;
    int ty;
    ban()
    {
        e = ty = 0;
    }
    ban(char x)
    {
        e = 1;
        if (x == '(' || x == ')')
            ty = 0;
        else
            ty = 1;
    }
};

ban mer(const ban& l, const ban& r)
{
    if (l.e == 0)
        return r;
    if (r.e == 0)
        return l;

    ban res;
    if ((l.ty + l.e - 1) % 2 != r.ty)
    {
        res.e = l.e + r.e;
        res.ty = l.ty;
    }
    else
    {
        if (l.e != r.e)
        {
            if (l.e > r.e)
            {
                res.e = l.e - r.e;
                res.ty = l.ty;
            }
            else
            {
                res.e = r.e - l.e;
                res.ty = (r.ty + l.e) % 2;
            }
        }
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
    cin >> (a + 1);
    for (n = 1; a[n]; ++n){}
    --n;

    bil(1, n, 1);

    int qq;
    cin >> qq;
    while (qq--)
    {
        int l, r;
        cin >> l >> r;
        cout << qry(1, n, l, r, 1).e / 2 << "\n";
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}