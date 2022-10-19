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
const int N = 300005, M = 1000000009;

struct ban
{
    vector<int> a[3];
    ban()
    {
        for (int i = 0; i < 3; ++i)
            a[i].assign(3, 0);
    }
};
ban operator*(const ban& a, const ban& b)
{
    ban res;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                res.a[i][j] = (res.a[i][j] + a.a[i][k] * 1LL * b.a[k][j]) % M;
            }
        }
    }
    return res;
}

int n;
int ss[N];

ban ast[N];

void pre()
{
    ban u;
    u.a[0] = {0, 1, 0};
    u.a[1] = {1, 1, 0};
    u.a[2] = {1, 1, 1};
    for (int i = 0; i < 3; ++i)
        ast[0].a[i][i] = 1;
    for (int i = 1; i <= n; ++i)
        ast[i] = ast[i - 1] * u;
}

struct ban1
{
    int a[3];
    ban1()
    {
        memset(a, 0, sizeof a);
    }
    ban1(vector<int> a)
    {
        for (int i = 0; i < 3; ++i)
            this->a[i] = a[i];
    }
};

int s[N * 4];
ban1 laz[N * 4];

ban1 baz(const ban1& f, int n)
{
    ban1 res;
    for (int i = 0; i < 3; ++i)
    {
        int u = 0;
        for (int j = 0; j < 3; ++j)
        {
            u = (u + f.a[j] * 1LL * ast[n].a[i][j]) % M;
        }
        res.a[i] = u;
    }
    return res;
}

void ave(int tl, int tr, int pos, ban1 f)
{
    laz[pos].a[0] = (laz[pos].a[0] + f.a[0]) % M;
    laz[pos].a[1] = (laz[pos].a[1] + f.a[1]) % M;
    f.a[2] = f.a[1];
    f = baz(f, tr - tl);
    s[pos] = (s[pos] + f.a[2]) % M;
}

void shi(int tl, int tr, int pos)
{
    if (laz[pos].a[1] == 0)
        return;
    int m = (tl + tr) / 2;
    ave(tl, m, pos * 2, laz[pos]);
    laz[pos] = baz(laz[pos], m - tl + 1);
    ave(m + 1, tr, pos * 2 + 1, laz[pos]);
    laz[pos] = ban1();
}

void bil(int tl, int tr, int pos)
{
    laz[pos] = ban1();
    if (tl == tr)
    {
        s[pos] = ss[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    s[pos] = (s[pos * 2] + s[pos * 2 + 1]) % M;
}

void ubd(int tl, int tr, int l, int r, ban1 f, int pos)
{
    if (tl == l && tr == r)
    {
        ave(tl, tr, pos, f);
        return;
    }
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd(tl, m, l, r, f, pos * 2);
    else if (l > m)
        ubd(m + 1, tr, l, r, f, pos * 2 + 1);
    else
    {
        ubd(tl, m, l, m, f, pos * 2);
        ubd(m + 1, tr, m + 1, r, baz(f, m - l + 1), pos * 2 + 1);
    }
    s[pos] = (s[pos * 2] + s[pos * 2 + 1]) % M;
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return s[pos];
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return (qry(tl, m, l, m, pos * 2) +
            qry(m + 1, tr, m + 1, r, pos * 2 + 1)) % M;
}

void solv()
{
    int qq;
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &ss[i]);
    pre();
    bil(1, n, 1);
    while (qq--)
    {
        int ty, l, r;
        scanf("%d%d%d", &ty, &l, &r);
        if (ty == 1)
            ubd(1, n, l, r, ban1({0, 1, 0}), 1);
        else
            printf("%d\n", qry(1, n, l, r, 1));
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}