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

int n, L;
int a[N], b[N];

int qryy(int l1, int r1, int l2, int r2)
{
    int l = max(l1, l2);
    int r = min(r1, r2);
    if (l > r)
        return 0;
    return upper_bound(b, b + n, r) - lower_bound(b, b + n, l);
}

int qry(int l1, int r1, int l2, int r2)
{
    int l3 = 0, r3 = -1;
    if (l1 > r1)
    {
        r3 = r1;
        r1 = L - 1;
    }

    int l4 = 0, r4 = -1;
    if (l2 > r2)
    {
        r4 = r2;
        r2 = L - 1;
    }

    return qryy(l1, r1, l2, r2) + qryy(l1, r1, l4, r4) +
            qryy(l3, r3, l2, r2) + qryy(l3, r3, l4, r4);
}

int q[N];
int u[N];

struct ban
{
    int minu;
    int s;
    ban()
    {
        minu = s = 0;
    }
    ban(int x)
    {
        s = x;
        if (x < 0)
            minu = x;
        else
            minu = 0;
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.s = l.s + r.s;
    res.minu = min(l.minu, l.s + r.minu);
    return res;
}

ban t[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(u[tl]);
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

int l[N], r[N];
bool stg(int x)
{
    for (int i = 0; i < n; ++i)
    {
        l[i] = (a[i] - x + L) % L;
        r[i] = (a[i] + x) % L;
    }

    for (int i = 0; i < n; ++i)
    {
        q[i] = qry(l[i], r[i], l[i], r[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        int j = (i - 1 + n) % n;
        u[i] = q[i] - qry(l[j], r[j], l[i], r[i]) - 1;
    }

    bil(0, n - 1, 1);

    for (int i = 0; i < n; ++i)
    {
        ban u = mer(qry(0, n - 1, i + 1, n - 1, 1),
                    qry(0, n - 1, 0, i - 1, 1));

        if (q[i] + u.minu - 1 < 0)
            return false;
    }
    return true;
}

void solv()
{
    cin >> n >> L;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    int l = 0, r = L / 2;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    cout << ans << "\n";
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