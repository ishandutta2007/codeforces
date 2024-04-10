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

const int n = 200000;
int qq, d;

bool c[N];
bool C(int x)
{
    if (x <= 0)
        return false;
    return c[x];
}

int t0[N];
void ubd0(int x, int y)
{
    while (x <= n)
    {
        t0[x] += y;
        x += (x & (-x));
    }
}
int qry0(int l, int r)
{
    if (l > r)
        return 0;
    int ans = 0;
    while (r)
    {
        ans += t0[r];
        r -= (r & (-r));
    }
    --l;
    while (l)
    {
        ans -= t0[l];
        l -= (l & (-l));
    }
    return ans;
}

int qrys(int x)
{
    if (C(x - 1) == C(x - d - 1))
        return 0;
    else if (C(x - 1))
        return 1;
    else
        return -1;
}

int qryt(int x)
{
    return qry0(max(x - d, 1), x - 2);
}

struct ban
{
    ll ans;
    ll s, anss;
    ll st;
    int q;
    ban()
    {
        ans = 0;
        s = 0;
        q = 0;
    }
    ban(bool z, int ss, int tt)
    {
        q = z;
        s = ss;
        anss = ss * z;
        st = ss * tt;
        ans = st * z;
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.q = l.q + r.q;
    res.s = l.s + r.s;
    res.anss = l.anss + r.anss + l.s * r.q;
    res.st = l.st + r.st;
    res.ans = l.ans + r.ans + l.st * r.q;
    return res;
}

ban t[N * 4];
ll laz[N * 4];

void ave(int pos, ll y)
{
    laz[pos] += y;
    t[pos].st += y * t[pos].s;
    t[pos].ans += y * t[pos].anss;
}

void shi(int pos)
{
    ave(pos * 2, laz[pos]);
    ave(pos * 2 + 1, laz[pos]);
    laz[pos] = 0;
}

void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(c[x], qrys(x), qryt(x));
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void ubd1(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        ave(pos, y);
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd1(tl, m, l, min(m, r), y, pos * 2);
    ubd1(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void solv()
{
    cin >> qq >> d;
    while (qq--)
    {
        int x;
        cin >> x;

        c[x] ^= true;
        if (c[x])
            ubd0(x, 1);
        else
            ubd0(x, -1);

        ubd(1, n, x, 1);
        if (x + 1 <= n)
            ubd(1, n, x + 1, 1);
        if (x + d + 1 <= n)
            ubd(1, n, x + d + 1, 1);

        if (c[x])
            ubd1(1, n, x + 2, min(n, x + d), 1, 1);
        else
            ubd1(1, n, x + 2, min(n, x + d), -1, 1);

        cout << t[1].ans << "\n";
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}