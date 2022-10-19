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
const int N = 400005;

int n, m, k;

struct ban
{
    int e;
    int q;
    int s;
    ban()
    {
        e = 0;
        q = 0;
        s = 0;
    }
};

ban t[N * 4];

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.e = l.e + r.e;
    res.q = l.q + r.q;
    res.s = max(r.s, r.q - r.e + l.s);
    return res;
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos].e = 1;
        t[pos].q = 0;
        t[pos].s = 0;
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
        t[pos].q += y;
        t[pos].s = max(0, t[pos].q - t[pos].e);
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
    scanf("%d%d%d", &n, &k, &m);
    bil(1, n * 2, 1);
    set<pair<int, int> > s;
    multiset<int> su;
    while (m--)
    {
        int x, y;
        scanf("%d%d", &y, &x);
        if (s.find(m_p(x, y)) == s.end())
        {
            s.insert(m_p(x, y));
            int u = x + abs(y - k);
            su.insert(u);
            ubd(1, n * 2, u, 1, 1);
        }
        else
        {
            s.erase(m_p(x, y));
            int u = x + abs(y - k);
            su.erase(su.find(u));
            ubd(1, n * 2, u, -1, 1);
        }
        if (su.empty())
            printf("0\n");
        else
        {
            int maxu = *(--su.end());
            if (maxu <= n)
                printf("%d\n", qry(1, n * 2, 1, n, 1).s);
            else
                printf("%d\n", maxu - n + qry(1, n * 2, 1, maxu, 1).s);
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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}