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
const int N = 100005, m = 60;
int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int lca(int x, int y)
{
    return x / gcd(x, y) * y;
}

struct ban
{
    int a[m];
    ban()
    {
        memset(a, 0, sizeof a);
    }
    ban(int x)
    {
        for (int i = 0; i < m; ++i)
        {
            if (i % x == 0)
                a[i] = 2;
            else
                a[i] = 1;
        }
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    for (int i = 0; i < m; ++i)
    {
        res.a[i] = l.a[i] + r.a[(i + l.a[i]) % m];
    }
    return res;
}

int n;
int a[N];
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
        t[pos] = y;
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

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    /*int t = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (t % a[i] == 0)
            t += 2;
        else
            t += 1;
        printf("%d\n", t);
    }
    return;*/
    bil(1, n, 1);
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        char ty;
        scanf(" %c", &ty);
        if (ty == 'A')
        {
            int l, r;
            scanf("%d%d", &l, &r);
            --r;
            printf("%d\n", qry(1, n, l, r, 1).a[0]);
        }
        else
        {
            int x, y;
            scanf("%d%d", &x, &y);
            ubd(1, n, x, y, 1);
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}