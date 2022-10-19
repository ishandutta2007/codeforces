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

int n, m;
int xx[N], yy[N];
vector<int> g[N];

vector<vector<int> > vv;
bool so(const vector<int>& a, const vector<int>& b)
{
    for (int i = 0; ; ++i)
    {
        if (a[i] < b[i])
            return true;
        if (a[i] > b[i])
            return false;
    }
    assert(false);
}

map<pair<int, int>, pair<int, int> > mp;

bool c[N];

int q[N];
void dfs0(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (c[h])
            continue;
        dfs0(h, x);
        q[x] += q[h];
    }
}

int dfsc(int x, int p, int xx)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (c[h])
            continue;
        if (q[h] > q[xx] / 2)
            return dfsc(h, x, xx);
    }
    return x;
}

int ans[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> xx[i] >> yy[i];
        g[xx[i]].push_back(yy[i]);
        g[yy[i]].push_back(xx[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        sort(all(g[i]));
        reverse(all(g[i]));
    }

    set<int> s;
    for (int i = 1; i <= n; ++i)
        s.insert(i);
    set<int> u;
    while (!s.empty())
    {
        int x = *s.begin();
        s.erase(x);

        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (u.find(h) != u.end())
            {
                vector<int> v;
                for (auto it = u.find(h); it != u.end(); ++it)
                {
                    v.push_back(*it);
                }
                v.push_back(x);
                vv.push_back(v);
                for (int i = 1; i < sz(v) - 1; ++i)
                    u.erase(v[i]);
            }
        }
        u.insert(x);
    }

    vector<int> v;
    for (auto it = u.begin(); it != u.end(); ++it)
        v.push_back(*it);
    vv.push_back(v);
    u.clear();

    for (int i = 0; i < sz(vv); ++i)
    {
        sort(all(vv[i]));
        reverse(all(vv[i]));
    }
    sort(all(vv), so);

    /*for (int i = 0; i < sz(vv); ++i)
    {
        for (int j = 0; j < sz(vv[i]); ++j)
            cout << vv[i][j] << ' ';
        cout << "\n";
    }*/

    for (int i = 0; i < sz(vv); ++i)
    {
        for (int j = 0; j < sz(vv[i]); ++j)
        {
            int minu = min(vv[i][j], vv[i][(j + 1) % sz(vv[i])]);
            int maxu = max(vv[i][j], vv[i][(j + 1) % sz(vv[i])]);
            if (mp[m_p(minu, maxu)].fi == 0)
                mp[m_p(minu, maxu)].fi = i + 1;
            else
                mp[m_p(minu, maxu)].se = i + 1;
        }
    }

    for (int i = 1; i <= sz(vv); ++i)
        g[i].clear();
    for (int i = 1; i <= m; ++i)
    {
        if (xx[i] > yy[i])
            swap(xx[i], yy[i]);
        if (mp.find(m_p(xx[i], yy[i])) != mp.end())
        {
            if (mp[m_p(xx[i], yy[i])].se != 0)
            {
                g[mp[m_p(xx[i], yy[i])].fi].push_back(mp[m_p(xx[i], yy[i])].se);
                g[mp[m_p(xx[i], yy[i])].se].push_back(mp[m_p(xx[i], yy[i])].fi);
            }
        }
    }

    queue<pair<int, int> > q;
    q.push(m_p(1, 1));
    while (!q.empty())
    {
        int x = q.front().fi;
        int d = q.front().se;
        q.pop();
        dfs0(x, x);
        x = dfsc(x, x, x);

        ans[x] = d;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (!c[h])
                q.push(m_p(h, d + 1));
        }
        c[x] = true;
    }

    for (int i = 1; i <= sz(vv); ++i)
        cout << ans[i] << ' ';
    cout << "\n";
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