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
const int N = 1000006;

struct ban
{
    int s, a;
};
bool operator<(const ban& a, const ban& b)
{
    return m_p(a.a, a.s) < m_p(b.a, b.s);
}

int n, d;
ban a[N];
vector<int> v;

int t[N * 20];
int ul[N * 20], ur[N * 20];
int z;
int ubd(int tl, int tr, int x, int y, int pos)
{
    int ypos = ++z;
    t[ypos] = t[pos];
    ul[ypos] = ul[pos];
    ur[ypos] = ur[pos];

    if (tl == tr)
    {
        t[ypos] += y;
        return ypos;
    }

    int m = (tl + tr) / 2;
    if (x <= m)
        ul[ypos] = ubd(tl, m, x, y, ul[pos]);
    else
        ur[ypos] = ubd(m + 1, tr, x, y, ur[pos]);

    t[ypos] = t[ul[ypos]] + t[ur[ypos]];
    return ypos;
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];

    int m = (tl + tr) / 2;

    return (qry(tl, m, l, min(m, r), ul[pos]) +
            qry(m + 1, tr, max(m + 1, l), r, ur[pos]));
}

int p[N];
int qryy(int L, int R, int d)
{
    return qry(1, sz(v), d, sz(v), p[R]) - qry(1, sz(v), d, sz(v), p[L - 1]);
}


int minu[N * 20];
int ulm[N * 20], urm[N * 20];
int zm;
int ubdm(int tl, int tr, int x, int y, int pos)
{
    int ypos = ++zm;
    minu[ypos] = minu[pos];
    ulm[ypos] = ulm[pos];
    urm[ypos] = urm[pos];

    if (tl == tr)
    {
        minu[ypos] = min(minu[ypos], y);
        return ypos;
    }

    int m = (tl + tr) / 2;
    if (x <= m)
        ulm[ypos] = ubdm(tl, m, x, y, ulm[pos]);
    else
        urm[ypos] = ubdm(m + 1, tr, x, y, urm[pos]);

    minu[ypos] = min(minu[ulm[ypos]], minu[urm[ypos]]);
    return ypos;
}

int qrym(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return N;
    if (tl == l && tr == r)
        return minu[pos];

    int m = (tl + tr) / 2;

    return min(qrym(tl, m, l, min(m, r), ulm[pos]),
            qrym(m + 1, tr, max(m + 1, l), r, urm[pos]));
}

int s[N];

void ka()
{
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].s >> a[i].a;
}

int cd;
int cs[N], ca[N];
void gen()
{
    n = 5;
    d = rnf() % 4;
    cd = d;
    for (int i = 1; i <= n; ++i)
    {
        a[i].s = rnf() % 4;
        cs[i] = a[i].s;
        a[i].a = rnf() % 4;
        ca[i] = a[i].a;
    }
}

void cgen()
{
    d = cd;
    for (int i = 1; i <= n; ++i)
    {
        a[i].s = cs[i];
        a[i].a = ca[i];
    }
}

int solv()
{
    z = 0;
    zm = 0;
    v.clear();
    minu[0] = N;

    v.push_back(d);
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(a[i].s);
        v.push_back(a[i].a);
    }
    sort(all(v));

    d = lower_bound(all(v), d) - v.begin() + 1;
    for (int i = 1; i <= n; ++i)
    {
        a[i].s = lower_bound(all(v), a[i].s) - v.begin() + 1;
        a[i].a = lower_bound(all(v), a[i].a) - v.begin() + 1;
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i)
    {
        p[i] = ubd(1, sz(v), a[i].s, 1, p[i - 1]);
    }

    s[n + 1] = 0;
    for (int i = n; i >= 1; --i)
    {
        s[i] = ubdm(1, sz(v), a[i].s, i, s[i + 1]);
    }

    int ans = 0;

    int L = 1;
    while (1)
    {
        int l = 1, r = n;
        int R = L - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (a[m].a <= d)
            {
                R = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }

        ans += qryy(L, R, d);

        int u = qrym(1, sz(v), d, sz(v), s[R + 1]);

        if (u == N)
            break;

        int uu = qrym(1, sz(v), d, a[u].a - 1, s[u]);
        if (uu == N)
            uu = -1;

        bool z = false;
        if (uu > u)
        {
            if (qryy(R + 1, uu - 1, a[uu].a) == qryy(R + 1, uu - 1, a[u].a))
            {
                d = a[uu].a;
                ++ans;
                z = true;
            }
        }

        if (!z)
        {
            d = a[u].a;
            if (a[u].s < d)
                ++ans;
        }

        L = R + 1;
    }

    cgen();
    return ans;
}

int solv0()
{
    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);

    int ans = 0;
    do
    {
        int yans = 0;

        int dd = d;
        for (int ii = 0; ii < n; ++ii)
        {
            int i = v[ii];
            if (a[i].s >= dd)
            {
                ++yans;
                dd = max(dd, a[i].a);
            }
            else
                break;
        }

        ans = max(ans, yans);
    } while (next_permutation(all(v)));

    return ans;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*int st = 100;
    while (st--)
    {
        gen();
        if (solv() != solv0())
        {
            cout << "WA\n";
            cout << n << ' ' << d << "\n";
            for (int i = 1; i <= n; ++i)
                cout << a[i].s << ' ' << a[i].a << "\n";
            cout << "Wrong: " << solv() << "\n";
            cout << "Correct: " << solv0() << "\n";
            return 0;
        }
    }
    cout << "OK\n";
    return 0;*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        ka();
        cout << solv() << "\n";
    }
    return 0;
}