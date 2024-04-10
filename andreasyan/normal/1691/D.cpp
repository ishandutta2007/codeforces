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

int n;
int a[N];

struct ban
{
    ll s;
    ll l, r;
    int maxu, maxi;
    ban()
    {
        s = 0;
        l = r = 0;
        maxu = -1000000009;
        maxi = -1;
    }
    ban(int i, int x)
    {
        s = x;
        if (x > 0)
            l = r = x;
        else
            l = r = 0;
        maxu = x;
        maxi = i;
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.s = l.s + r.s;
    res.l = max(l.l, l.s + r.l);
    res.r = max(r.r, r.s + l.r);
    if (l.maxu > r.maxu)
    {
        res.maxu = l.maxu;
        res.maxi = l.maxi;
    }
    else
    {
        res.maxu = r.maxu;
        res.maxi = r.maxi;
    }
    return res;
}

ban t[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(tl, a[tl]);
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

bool rec(int l, int r)
{
    if (l > r)
        return true;

    int m = qry(1, n, l, r, 1).maxi;
    if (a[m] < a[m] + qry(1, n, l, m - 1, 1).r + qry(1, n, m + 1, r, 1).l)
        return false;

    if (!rec(l, m - 1))
        return false;
    if (!rec(m + 1, r))
        return false;

    return true;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    bil(1, n, 1);
    if (rec(1, n))
        cout << "YES\n";
    else
        cout << "NO\n";
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