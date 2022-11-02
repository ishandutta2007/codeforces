#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<long long, long long>
#define pb emplace_back
#define mp make_pair

struct point
{
    int tin, tout, x, y;
    point(int tin = 0, int tout = 0, int x = 0, int y = 0): tin(tin), tout(tout), x(x), y(y) {};
};

struct kek
{
    int v, t, sz, cntx, cnty;
    kek(int v = 0, int t = 0, int sz = 0, int cntx = 0, int cnty = 0): v(v), t(t), sz(sz), cntx(cntx), cnty(cnty) {};
};

const int MAXN = 300009;
pii p[MAXN][2];
int sz[MAXN][2];
int cntx[MAXN][2];
int cnty[MAXN][2];
int n;
int ans[MAXN];

pii find_p(int x, int t)
{
    pii cur(x, t);
    while (p[cur.ff][cur.ss] != cur)
        cur = p[cur.ff][cur.ss];
    return cur;
}

void f(int left, int right, vector<point>& q, int cur_ans)
{
    vector<point> q1;
    vector<pii> st;
    for (auto x : q)
    {
        if (x.tin <= left && x.tout >= right)
        {
            pii a = find_p(x.x, 0);
            pii b = find_p(x.y, 1);
            if (a == b)
                continue;
            cur_ans -= cntx[a.ff][a.ss] * cnty[a.ff][a.ss];
            cur_ans -= cntx[b.ff][b.ss] * cnty[b.ff][b.ss];
            if (sz[a.ff][a.ss] < sz[b.ff][b.ss])
            {
                st.pb(a.ff, a.ss);
                p[a.ff][a.ss] = b;
                sz[b.ff][b.ss] += sz[a.ff][a.ss];
                cntx[b.ff][b.ss] += cntx[a.ff][a.ss];
                cnty[b.ff][b.ss] += cnty[a.ff][a.ss];
                cur_ans += cntx[b.ff][b.ss] * cnty[b.ff][b.ss];
            }
            else
            {
                st.pb(b.ff, b.ss);
                p[b.ff][b.ss] = a;
                sz[a.ff][a.ss] += sz[b.ff][b.ss];
                cntx[a.ff][a.ss] += cntx[b.ff][b.ss];
                cnty[a.ff][a.ss] += cnty[b.ff][b.ss];
                cur_ans += cntx[a.ff][a.ss] * cnty[a.ff][a.ss];
            }
        }
        else if (x.tin >= right || x.tout <= left)
            continue;
        else
            q1.pb(x);
    }
    if (left == right - 1)
        ans[left] = cur_ans;
    else
    {
        f(left, (left + right) / 2, q1, cur_ans);
        f((left + right) / 2, right, q1, cur_ans);
    }
    for (int j = (int)st.size() - 1; j >= 0; j--)
    {
        pii a = st[j];
        pii b = p[a.ff][a.ss];
        sz[b.ff][b.ss] -= sz[a.ff][a.ss];
        cntx[b.ff][b.ss] -= cntx[a.ff][a.ss];
        cnty[b.ff][b.ss] -= cnty[a.ff][a.ss];
        p[a.ff][a.ss] = a;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    map<pii, int> m;
    int tm = 0;
    vector<point> q;
    for (int i = 0; i < n; i++)
    {
        pii cur;
        cin >> cur.ff >> cur.ss;
        auto j = m.find(cur);
        if (j == m.end())
        {
            m.emplace(cur, tm);
            tm++;
        }
        else
        {
            q.pb((*j).ss, tm, cur.ff, cur.ss);
            tm++;
            m.erase(j);
        }
    }
    for (auto j = m.begin(); j != m.end(); j++)
        q.pb((*j).ss, tm, (*j).ff.ff, (*j).ff.ss);
    for (int i = 0; i < MAXN; i++)
    {
        p[i][0] = mp(i, 0);
        p[i][1] = mp(i, 1);
        cntx[i][0] = 1;
        cnty[i][1] = 1;
        sz[i][0] = 1;
        sz[i][1] = 1;
    }
    f(0, tm, q, 0);
    for (int i = 0; i < tm; i++)
        cout << ans[i] << " ";
}