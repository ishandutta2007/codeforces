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
const int N = 100005, INF = 1000000009;

struct ban
{
    ll l, r;
    ll d;
    ban(){}
    ban(ll x)
    {
        l = r = x;
        d = 0;
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.l = l.l;
    res.r = r.r;
    res.d = l.d + r.d;
    if (r.l - l.r > 0)
        res.d += (r.l - l.r);
    return res;
}

int n;
int a[N];

ll laz[N * 4];
ban t[N * 4];

void shi(int pos)
{
    t[pos * 2].l += laz[pos];
    t[pos * 2].r += laz[pos];

    t[pos * 2 + 1].l += laz[pos];
    t[pos * 2 + 1].r += laz[pos];

    laz[pos * 2] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
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

void ubd(int tl, int tr, int l, int r, ll y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos].l += y;
        t[pos].r += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    bil(1, n, 1);
    if (t[1].l + t[1].d < 0)
        printf("%lld\n", (t[1].l + t[1].d) / 2);
    else
        printf("%lld\n", (t[1].l + t[1].d) / 2 + (t[1].l + t[1].d) % 2);
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int l, r, y;
        scanf("%d%d%d", &l, &r, &y);
        ubd(1, n, l, r, y, 1);
        if (t[1].l + t[1].d < 0)
            printf("%lld\n", (t[1].l + t[1].d) / 2);
        else
            printf("%lld\n", (t[1].l + t[1].d) / 2 + (t[1].l + t[1].d) % 2);
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