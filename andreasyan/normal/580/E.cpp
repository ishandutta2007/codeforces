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
const int N = 100005;
const pair<int, int> M = m_p(891641833, 716000533);
const int P = 307;

bool prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

pair<int, int> sum(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi + b.fi) % M.fi, (a.se + b.se) % M.se);
}

pair<int, int> dif(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi - b.fi + M.fi) % M.fi, (a.se - b.se + M.se) % M.se);
}

pair<int, int> pro(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi * 1LL * b.fi) % M.fi, (a.se * 1LL * b.se) % M.se);
}

int n, m, k;
char a[N];

pair<int, int> ast[N];
pair<int, int> hh[10][N];
void pre()
{
    ast[0] = m_p(1, 1);
    for (int i = 1; i <= n; ++i)
        ast[i] = pro(ast[i - 1], m_p(P, P));
    for (int k = 0; k <= 9; ++k)
    {
        for (int i = 1; i <= n; ++i)
            hh[k][i] = sum(hh[k][i - 1], pro(ast[i - 1], m_p(k + '0', k + '0')));
    }
}

struct ban
{
    pair<int, int> h;
    int s;
    ban()
    {
        h = m_p(0, 0);
        s = 0;
    }
    ban(char x)
    {
        h = m_p(x, x);
        s = 1;
    }
};

ban t[N * 4];
char laz[N * 4];

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.s = l.s + r.s;
    res.h = sum(l.h, pro(r.h, ast[l.s]));
    return res;
}

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

void shi(int tl, int tr, int pos)
{
    if (!laz[pos])
        return;
    int m = (tl + tr) / 2;
    t[pos * 2].h = hh[laz[pos] - '0'][m - tl + 1];
    t[pos * 2 + 1].h = hh[laz[pos] - '0'][tr - m];
    laz[pos * 2] = laz[pos];
    laz[pos * 2 + 1] = laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, char y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos].h = hh[y - '0'][tr - tl + 1];
        laz[pos] = y;
        return;
    }
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return ban();
    if (tl == l && tr == r)
        return t[pos];
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    return mer(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    scanf(" %s", (a + 1));
    pre();
    bil(1, n, 1);
    int qq = m + k;
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int l, r;
            char y;
            scanf("%d%d %c", &l, &r, &y);
            ubd(1, n, l, r, y, 1);
        }
        else
        {
            int l, r, d;
            scanf("%d%d%d", &l, &r, &d);
            if (qry(1, n, l, r - d, 1).h == qry(1, n, l + d, r, 1).h)
                printf("YES\n");
            else
                printf("NO\n");
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
    /*int x = 500000000 + rnd() % 500000000;
    while (!prime(x))
        ++x;
    printf("%d\n", x);
    x = 500000000 + rnd() % 500000000;
    while (!prime(x))
        ++x;
    printf("%d\n", x);*/
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}