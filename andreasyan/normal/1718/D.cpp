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
const int N = 300005, M = 1000006;

int n, qq;
int p[N];

pair<int, int> maxu[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        maxu[pos] = m_p(p[tl], tl);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}

pair<int, int> qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return m_p(0, 0);
    if (tl == l && tr == r)
        return maxu[pos];
    int m = (tl + tr) / 2;
    return max(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int k;
int a[N];

vector<pair<int, int> > b;
bool ans0;
int rec(int l, int r, int p)
{
    if (l > r)
        return 0;
    int m = qry(1, n, l, r, 1).se;
    int maxu = 0;
    if (a[m])
    {
        maxu = max(maxu, rec(l, m - 1, min(p, a[m])));
        maxu = max(maxu, rec(m + 1, r, min(p, a[m])));
    }
    else
    {
        maxu = max(maxu, rec(l, m - 1, p));
        maxu = max(maxu, rec(m + 1, r, p));
    }
    if (a[m] == 0)
    {
        b.push_back(m_p(maxu, p));
    }
    else
    {
        if (!(maxu < a[m] && a[m] < p))
            ans0 = true;
    }
    maxu = max(maxu, a[m]);
    return maxu;
}

struct ban
{
    int p, s;
    int r;
    ban(){}
    ban(int x, int i)
    {
        s = x;
        if (x < 0)
        {
            p = x;
            r = i;
        }
        else
        {
            p = 0;
            r = i - 1;
        }
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.s = l.s + r.s;
    if (l.s + r.p < l.p)
    {
        res.p = l.s + r.p;
        res.r = r.r;
    }
    else
    {
        res.p = l.p;
        res.r = l.r;
    }
    return res;
}

ban t[M * 4];
void bil1(int tl, int tr, int pos)
{
    t[pos] = ban(0, tl);
    if (tl == tr)
        return;
    int m = (tl + tr) / 2;
    bil1(tl, m, pos * 2);
    bil1(m + 1, tr, pos * 2 + 1);
}

void ubd1(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(t[pos].s + y, tl);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd1(tl, m, x, y, pos * 2);
    else
        ubd1(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

/*ban qry1(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry1(tl, m, l, r, pos * 2);
    if (l > m)
        return qry1(m + 1, tr, l, r, pos * 2 + 1);
    return mer(qry1(tl, m, l, m, pos * 2),
               qry1(m + 1, tr, m + 1, r, pos * 2 + 1));
}*/

int s[N];

void solv()
{
    cin >> n >> qq;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    k = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] == 0)
            ++k;
    }

    bil(1, n, 1);
    b.clear();
    ans0 = false;
    rec(1, n, 1000001);
    for (int i = 0; i < sz(b); ++i)
    {
        if (b[i].se < b[i].fi)
        {
            ans0 = true;
            break;
        }
    }
    sort(all(b));

    for (int i = 1; i <= k - 1; ++i)
        cin >> s[i];
    sort(s + 1, s + k);

    int l0 = 0, r0 = 1000001;
    int j = k - 1;
    vector<int> minu;
    minu.assign(sz(b) + 1, 0);
    for (int i = sz(b) - 1; i >= 0; --i)
    {
        while (j >= 1 && s[j] > b[i].fi)
        {
            ubd1(1, M - 3, s[j], 1, 1);
            --j;
        }
        ubd1(1, M - 3, b[i].se, -1, 1);

        if (t[1].p < -1)
        {
            ans0 = true;
        }
        else if (t[1].p == -1)
        {
            l0 = max(l0, b[i].fi);
            r0 = min(r0, t[1].r);

            int i2 = lower_bound(all(b), m_p(t[1].r, M)) - b.begin();
            if (minu[i2] == -1)
            {
                ans0 = true;
            }
            minu[i] = min(minu[i + 1], -1);
        }
        else
        {
            minu[i] = minu[i + 1];
        }
    }

    for (int i = 0; i < sz(b); ++i)
        ubd1(1, M - 3, b[i].se, 1, 1);
    for (int i = j + 1; i < k; ++i)
        ubd1(1, M - 3, s[i], -1, 1);

    if (ans0)
    {
        while (qq--)
        {
            int x;
            cin >> x;
            cout << "NO\n";
        }
        return;
    }

    while (qq--)
    {
        int x;
        cin >> x;
        if (l0 < x && x < r0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    bil1(1, M - 3, 1);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}