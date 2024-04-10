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

int n, m, k;
int a[N];
pair<int, int> b[N];

vector<int> v[N];

vector<int> g[N];

int c[N];

vector<int> dv;
void dfs(int x, pair<int, int> u)
{
    dv.push_back(x);
    c[x] = u.fi;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs(h, m_p(u.se, u.fi));
    }
}

set<int> vat;

int nn;
vector<int> gg[N];

int qq;
map<pair<int, int>, int> mp;
vector<pair<int, int> > vv[N];

int cc[N];
vector<int> dv1;
bool dfs1(int x, int u)
{
    dv1.push_back(x);
    cc[x] = u;
    for (int i = 0; i < gg[x].size(); ++i)
    {
        int h = gg[x][i];
        if (!cc[h])
        {
            if (!dfs1(h, 3 - u))
                return false;
        }
        else
        {
            if (cc[x] == cc[h])
                return false;
        }
    }
    return true;
}

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int x = 1; x <= n; ++x)
        scanf("%d", &a[x]);
    for (int i = 0; i < m; ++i)
        scanf("%d%d", &b[i].fi, &b[i].se);

    for (int x = 1; x <= n; ++x)
        v[a[x]].push_back(x);

    for (int i = 0; i < m; ++i)
    {
        int x = b[i].fi;
        int y = b[i].se;
        if (a[x] == a[y])
        {
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }

    for (int i = 1; i <= k; ++i)
    {
        bool z = true;

        for (int j = 0; j < v[i].size(); ++j)
        {
            int x = v[i][j];
            c[x] = 0;
        }
        for (int j = 0; j < v[i].size(); ++j)
        {
            int x = v[i][j];
            if (!c[x])
            {
                dv.clear();
                dfs(x, m_p(nn + 1, nn + 2));
                nn += 2;

                for (int i = 0; i < dv.size(); ++i)
                {
                    int x = dv[i];
                    for (int j = 0; j < g[x].size(); ++j)
                    {
                        int h = g[x][j];
                        if (c[x] == c[h])
                        {
                            z = false;
                            break;
                        }
                    }
                    if (!z)
                        break;
                }
                if (!z)
                    break;

                if (sz(dv) > 1)
                {
                    gg[nn - 1].push_back(nn);
                    gg[nn].push_back(nn - 1);
                }
            }
        }
        if (!z)
        {
            vat.insert(i);
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int x = b[i].fi;
        int y = b[i].se;
        if (a[x] != a[y])
        {
            if (vat.find(a[x]) != vat.end())
                continue;
            if (vat.find(a[y]) != vat.end())
                continue;
            if (mp.find(m_p(min(a[x], a[y]), max(a[x], a[y]))) == mp.end())
                mp[m_p(min(a[x], a[y]), max(a[x], a[y]))] = ++qq;
            vv[mp[m_p(min(a[x], a[y]), max(a[x], a[y]))]].push_back(m_p(c[x], c[y]));
        }
    }

    ll ans = (k - sz(vat)) * 1LL * (k - sz(vat) - 1) / 2;
    for (int i = 1; i <= qq; ++i)
    {
        for (int j = 0; j < sz(vv[i]); ++j)
        {
            int x = vv[i][j].fi;
            int y = vv[i][j].se;
            gg[x].push_back(y);
            gg[y].push_back(x);
        }

        dv1.clear();
        bool z = true;
        for (int j = 0; j < sz(vv[i]); ++j)
        {
            int x = vv[i][j].fi;
            if (!cc[x])
            {
                if (!dfs1(x, 1))
                {
                    z = false;
                    break;
                }
            }
        }
        if (!z)
            --ans;

        for (int j = 0; j < sz(vv[i]); ++j)
        {
            int x = vv[i][j].fi;
            int y = vv[i][j].se;
            gg[x].pop_back();
            gg[y].pop_back();
        }
        for (int j = 0; j < sz(dv1); ++j)
        {
            int x = dv1[j];
            cc[x] = 0;
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
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}