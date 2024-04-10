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
const int N = 2003, M = 1000000007;

int n, k, L;
int x[N], y[N], c[N];

vector<int> vx;
vector<int> vy;

vector<pair<int, int> > v[N];
multiset<int> ss[N];

int maxu[N * 4];
int minu[N * 4];
int s[N * 4];

vector<int> gg[N];
int g[N];
int q[N], qq;

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        minu[pos] = maxu[pos] = g[tl];
        if (tl == 0)
            s[pos] = (vy[tr]) * 1LL * (L - vy[g[tl]] + 1) % M;
        else
            s[pos] = (vy[tr] - vy[tl - 1]) * 1LL * (L - vy[g[tl]] + 1) % M;
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
    minu[pos] = min(minu[pos * 2], minu[pos * 2 + 1]);
    s[pos] = (s[pos * 2] + s[pos * 2 + 1]) % M;
}

void shi(int tl, int tr, int pos)
{
    if (minu[pos] != maxu[pos])
        return;
    int m = (tl + tr) / 2;
    minu[pos * 2] = maxu[pos * 2] = minu[pos * 2 + 1] = maxu[pos * 2 + 1] = minu[pos];
    if (tl == 0)
        s[pos * 2] = (vy[m]) * 1LL * (L - vy[minu[pos]] + 1) % M;
    else
        s[pos * 2] = (vy[m] - vy[tl - 1]) * 1LL * (L - vy[minu[pos]] + 1) % M;
    s[pos * 2 + 1] = (vy[tr] - vy[m]) * 1LL * (L - vy[minu[pos]] + 1) % M;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (minu[pos] >= y)
        return;
    if (tl == l && tr == r)
    {
        if (maxu[pos] <= y)
        {
            maxu[pos] = minu[pos] = y;
            if (l == 0)
                s[pos] = (vy[r]) * 1LL * (L - vy[y] + 1) % M;
            else
                s[pos] = (vy[r] - vy[l - 1]) * 1LL * (L - vy[y] + 1) % M;
            return;
        }
        if (tl == tr)
            return;
    }
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
    minu[pos] = min(minu[pos * 2], minu[pos * 2 + 1]);
    s[pos] = (s[pos * 2] + s[pos * 2 + 1]) % M;
}

void solv()
{
    cin >> n >> k >> L;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y[i] >> c[i];
        ++x[i];
        ++y[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        vx.push_back(x[i]);
        vy.push_back(y[i]);
    }
    sort(all(vx));
    sort(all(vy));
    vy.push_back(L + 1);
    vx.push_back(L + 1);

    vector<int> vv;
    for (int i = 0; i < vx.size(); ++i)
    {
        if (!i || vx[i] != vx[i - 1])
            vv.push_back(vx[i]);
    }
    vx = vv;
    vv.clear();
    for (int i = 0; i < vy.size(); ++i)
    {
        if (!i || vy[i] != vy[i - 1])
            vv.push_back(vy[i]);
    }
    vy = vv;

    for (int i = 1; i <= n; ++i)
    {
        int xx = lower_bound(all(vx), x[i]) - vx.begin();
        int yy = lower_bound(all(vy), y[i]) - vy.begin();
        v[xx].push_back(m_p(yy, c[i]));
    }

    int ans = 0;
    for (int l = 0; l < sz(vx) - 1; ++l)
    {
        for (int i = 0; i < sz(vy) - 1; ++i)
            gg[i].clear();
        for (int i = 1; i <= k; ++i)
            ss[i].clear();
        for (int i = l; i < sz(vx) - 1; ++i)
        {
            for (int j = 0; j < v[i].size(); ++j)
            {
                ss[v[i][j].se].insert(v[i][j].fi);
                gg[v[i][j].fi].push_back(v[i][j].se);
            }
        }
        bool ff = true;
        for (int i = 1; i <= k; ++i)
        {
            if (ss[i].empty())
            {
                ff = false;
                break;
            }
        }
        if (!ff)
            continue;
        qq = 0;
        for (int i = 0; i < sz(vy) - 1; ++i)
        {
            g[i] = -1;
            if (i)
                g[i] = g[i - 1];
            while (1)
            {
                if (qq == k)
                    break;
                if (g[i] == sz(vy) - 1)
                    break;
                ++g[i];
                if (g[i] == sz(vy) - 1)
                    break;
                for (int j = 0; j < gg[g[i]].size(); ++j)
                {
                    ++q[gg[g[i]][j]];
                    if (q[gg[g[i]][j]] == 1)
                        ++qq;
                }
            }
            for (int j = 0; j < gg[i].size(); ++j)
            {
                --q[gg[i][j]];
                if (q[gg[i][j]] == 0)
                    --qq;
            }
        }
        bil(0, sz(vy) - 2, 1);
        int la;
        if (l == 0)
            la = vx[l];
        else
            la = (vx[l] - vx[l - 1]);
        for (int i = sz(vx) - 2; i >= l; --i)
        {
            ans = (ans + s[1] * 1LL * (vx[i + 1] - vx[i]) % M * 1LL * la % M) % M;
            for (int j = 0; j < v[i].size(); ++j)
            {
                ss[v[i][j].se].erase(ss[v[i][j].se].find(v[i][j].fi));
                if (ss[v[i][j].se].empty())
                {
                    s[1] = -1;
                    break;
                }
                auto it = ss[v[i][j].se].lower_bound(v[i][j].fi);
                if (it == ss[v[i][j].se].end())
                {
                    --it;
                    ubd(0, sz(vy) - 2, *it + 1, sz(vy) - 2, sz(vy) - 1, 1);
                }
                else
                {
                    if (*it == v[i][j].fi)
                        continue;
                    if (it == ss[v[i][j].se].begin())
                    {
                        int u = *it;
                        ubd(0, sz(vy) - 2, 0, sz(vy) - 2, u, 1);
                    }
                    else
                    {
                        int u = *it;
                        --it;
                        ubd(0, sz(vy) - 2, *it + 1, sz(vy) - 2, u, 1);
                    }
                }
            }
            if (s[1] == -1)
                break;
        }
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
        solv();
    return 0;
}