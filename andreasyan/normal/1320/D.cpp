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
const int N = 200005;
const pair<int, int> M = m_p(977071049, 961949207);
const int P = 307;

int fast(int x, int n, const int M)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

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

pair<int, int> ast[N];
pair<int, int> rast1;
void pre()
{
    ast[0] = m_p(1, 1);
    for (int i = 1; i < N; ++i)
        ast[i] = pro(ast[i - 1], m_p(P, P));
    rast1 = m_p(fast(P, M.fi - 2, M.fi), fast(P, M.se - 2, M.se));
}

int n;
char a[N];

struct ban
{
    int d;
    int q;
    pair<int, int> h;
    char l, r;
    ban()
    {
        d = 0;
        q = 0;
        h = m_p(0, 0);
        l = r = 0;
    }
};

bool operator==(const ban& a, const ban& b)
{
    return (a.d == b.d && a.q == b.q && a.h == b.h && a.l == b.l && a.r == b.r);
}

ban t[N * 4];

ban mer(ban l, ban r)
{
    if (l.r == '1' && r.l == '1')
    {
        if (l.d == 1)
        {
            l.d = 0;
            l.h = m_p(0, 0);
            l.l = l.r = 0;
        }
        else
        {
            l.h = dif(l.h, pro(m_p('1', '1'), ast[l.d - 1]));
            --l.d;
            l.r = '0';
        }
        if (r.d == 1)
        {
            r.d = 0;
            r.h = m_p(0, 0);
            r.l = r.r = 0;
        }
        else
        {
            r.h = pro(dif(r.h, m_p('1', '1')), rast1);
            --r.d;
            r.l = '0';
        }
    }

    ban res;

    res.d = l.d + r.d;
    res.q = l.q + r.q;
    res.h = sum(l.h, pro(r.h, ast[l.d]));

    if (l.l)
        res.l = l.l;
    else
        res.l = r.l;
    if (r.r)
        res.r = r.r;
    else
        res.r = l.r;
    return res;
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos].d = 1;
        t[pos].q = a[tl] - '0';
        t[pos].h = m_p(a[tl], a[tl]);
        t[pos].l = a[tl];
        t[pos].r = a[tr];
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
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    bil(1, n, 1);
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int l1, l2, d;
        scanf("%d%d%d", &l1, &l2, &d);
        if (qry(1, n, l1, l1 + d - 1, 1) == qry(1, n, l2, l2 + d - 1, 1))
            printf("Yes\n");
        else
            printf("No\n");
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    /*int x = 800000000 + rnd() % 200000000;
    while (!prime(x))
        ++x;
    printf("%d, ", x);
    x = 800000000 + rnd() % 200000000;
    while (!prime(x))
        ++x;
    printf("%d\n", x);*/
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}