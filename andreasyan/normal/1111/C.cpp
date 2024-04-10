#include <bits/stdc++.h>
using namespace std;

long long n, k, A, B;

struct ban
{
    long long ans, q;
    ban *l, *r;
    ban()
    {
        ans = A;
        q = 0;
        l = r = 0;
    }
};

void ave(ban* pos)
{
    if (pos->l == 0)
        pos->l = new ban;
    if (pos->r == 0)
        pos->r = new ban;
}

void ubd(long long tl, long long tr, long long x, ban* pos)
{
    if (tl == tr)
    {
        pos->q++;
        pos->ans = B * pos->q;
        return;
    }
    ave(pos);
    long long m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos->l);
    else
        ubd(m + 1, tr, x, pos->r);
    pos->q = pos->l->q + pos->r->q;
    pos->ans = min(pos->l->ans + pos->r->ans, B * pos->q * (tr - tl + 1));
}

ban* t;

int main()
{
    cin >> n >> k >> A >> B;
    t = new ban;
    while (k--)
    {
        long long x;
        cin >> x;
        ubd(1, (1LL << n), x, t);
    }
    cout << t->ans << endl;
    return 0;
}