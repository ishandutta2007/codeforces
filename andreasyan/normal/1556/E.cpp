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
    ll s;
    ll maxu;
    ll minu;
    ban()
    {
        s = maxu = minu = 0;
    }
    ban(int x)
    {
        s = x;
        maxu = max(0, x);
        minu = min(0, x);
    }
};

ban t[N * 4];

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.s = l.s + r.s;
    res.maxu = max(l.maxu, l.s + r.maxu);
    res.minu = min(l.minu, l.s + r.minu);
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
    cin >> n >> qq;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a[i] -= x;
    }

    /*for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    cout << "\n";
    return;*/

    bil(1, n, 1);

    while (qq--)
    {
        int l, r;
        cin >> l >> r;
        ban u = qry(1, n, l, r, 1);
        if (u.maxu == 0 && u.s == 0)
        {
            cout << -u.minu << "\n";
        }
        else
            cout << "-1\n";
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