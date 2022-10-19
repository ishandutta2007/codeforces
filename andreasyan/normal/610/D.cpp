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

int n;
map<int, vector<pair<int, int> > > vx, vy;

vector<pair<int, pair<int, int> > > bil(map<int, vector<pair<int, int> > > v)
{
    vector<pair<int, pair<int, int> > > ans;
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        sort(all(it->se));
        int p = 0;
        for (int i = 0; i < sz(it->se); ++i)
        {
            p += it->se[i].se;
            if (p > 0)
            {
                if (it->se[i].fi != it->se[i + 1].fi)
                {
                    ans.push_back(m_p(it->fi, m_p(it->se[i].fi, it->se[i + 1].fi - 1)));
                }
            }
        }
    }
    return ans;
}

ll ans;

bool so(const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b)
{
    if (a.fi < b.fi)
        return true;
    if (a.fi > b.fi)
        return false;
    if (abs(a.se.se) != N)
        return true;
    return false;
}

int xit(const vector<int>& v, int x)
{
    return lower_bound(all(v), x) - v.begin();
}

int t[N * 4];

void ubd(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        ++t[pos];
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
}

int qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return t[pos];
    int m = (tl + tr) / 2;
    if (x <= m)
        return qry(tl, m, x, pos * 2) + t[pos];
    return qry(m + 1, tr, x, pos * 2 + 1) + t[pos];
}

void solv()
{
    scanf("%d", &n);
    while (n--)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
        if (x1 == x2)
        {
            vx[x1].push_back(m_p(y1, 1));
            vx[x1].push_back(m_p(y2 + 1, -1));
        }
        else
        {
            vy[y1].push_back(m_p(x1, 1));
            vy[y1].push_back(m_p(x2 + 1, -1));
        }
    }
    vector<pair<int, pair<int, int> > > ux = bil(vx), uy = bil(vy);
    for (int i = 0; i < ux.size(); ++i)
    {
        ans += (ux[i].se.se - ux[i].se.fi + 1);
    }
    for (int i = 0; i < uy.size(); ++i)
    {
        ans += (uy[i].se.se - uy[i].se.fi + 1);
    }
    vector<int> v;
    for (int i = 0; i < ux.size(); ++i)
    {
        v.push_back(ux[i].se.fi);
        v.push_back(ux[i].se.se);
    }
    for (int i = 0; i < uy.size(); ++i)
    {
        v.push_back(uy[i].fi);
    }
    sort(v.begin(), v.end());
    vector<pair<int, pair<int, int> > > qv;
    for (int i = 0; i < ux.size(); ++i)
    {
        ux[i].se.fi = xit(v, ux[i].se.fi);
        ux[i].se.se = xit(v, ux[i].se.se);
        qv.push_back(ux[i]);
    }
    for (int i = 0; i < uy.size(); ++i)
    {
        uy[i].fi = xit(v, uy[i].fi);
        qv.push_back(m_p(uy[i].se.fi - 1, m_p(uy[i].fi, N)));
        qv.push_back(m_p(uy[i].se.se, m_p(uy[i].fi, -N)));
    }
    sort(all(qv), so);
    for (int i = 0; i < qv.size(); ++i)
    {
        pair<int, pair<int, int> > t = qv[i];
        if (t.se.se == N)
        {
            ans += qry(0, sz(v), t.se.fi, 1);
        }
        else if (t.se.se == -N)
        {
            ans -= qry(0, sz(v), t.se.fi, 1);
        }
        else
        {
            ubd(0, sz(v), t.se.fi, t.se.se, 1);
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}