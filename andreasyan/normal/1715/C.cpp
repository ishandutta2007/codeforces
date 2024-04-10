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

int n, qq;
int a[N];

struct ban
{
    ll ans, pans, sans, t;
    int l, r;
    int q;
    ban(){}
    ban(int x)
    {
        ans = pans = sans = t = 1;
        l = r = x;
        q = 1;
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.l = l.l;
    res.r = r.r;
    res.q = l.q + r.q;

    res.t = l.t + r.t;

    res.pans = l.pans + r.pans;
    res.pans += l.t * r.q;

    res.sans = r.sans + l.sans;
    res.sans += r.t * l.q;

    res.ans = l.ans + r.ans;
    res.ans += l.sans * r.q;
    res.ans += r.pans * l.q;

    if (l.r == r.l)
    {
        res.t--;
        res.pans -= r.q;
        res.sans -= l.q;
        res.ans -= l.q * 1LL * r.q;
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

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void solv()
{
    cin >> n >> qq;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    bil(1, n, 1);
    while (qq--)
    {
        int x, y;
        cin >> x >> y;
        ubd(1, n, x, y, 1);
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