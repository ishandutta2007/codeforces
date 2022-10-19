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
const double INF = 1000000009000000009;

int n, m;
vector<pair<int, int> > g[N];

double ans;
double ansa[N];

double a[N];

int c[N];
vector<int> v;
bool dvd;
int st, en;
int p[N];
void dfs0(int x, int gg)
{
    c[x] = gg;
    v.push_back(x);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (!c[h])
        {
            p[h] = x;
            dfs0(h, 3 - gg);
        }
        else
        {
            if (c[h] == c[x] && dvd)
            {
                dvd = false;
                st = h;
                en = x;
            }
        }
    }
}

void dfs1(int x)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        a[h] = g[x][i].se - a[x];
        if (!c[h])
            dfs1(h);
    }
}

double stg(int x, double u)
{
    a[x] = u;
    for (int i = 0; i < v.size(); ++i)
        c[v[i]] = 0;
    dfs1(x);

    bool z = true;
    for (int i = 0; i < v.size(); ++i)
    {
        int x = v[i];
        for (int i = 0; i < g[x].size(); ++i)
        {
            int y = g[x][i].fi;
            if (a[x] + a[y] != g[x][i].se)
            {
                z = false;
                break;
            }
        }
    }
    if (!z)
        return INF;
    double yyans = 0;
    for (int i = 0; i < v.size(); ++i)
        yyans += abs(a[v[i]]);
    return yyans;
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x].push_back(m_p(y, z));
        g[y].push_back(m_p(x, z));
    }

    vector<double> t;
    for (double x = -N * 4; x <= N * 4; x += 0.5)
        t.push_back(x);

    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            v.clear();
            dvd = true;
            dfs0(x, 1);

            double yans = INF;
            if (!dvd)
            {
                vector<int> vv;
                for (int x = en; x != st; x = p[x])
                    vv.push_back(x);
                vv.push_back(st);
                assert(sz(vv) % 2 == 1);
                reverse(all(vv));
                vector<double> vz;
                for (int i = 0; i < sz(vv); ++i)
                {
                    int x = vv[i];
                    int y = vv[(i + 1) % sz(vv)];
                    for (int i = 0; i < g[x].size(); ++i)
                    {
                        int h = g[x][i].fi;
                        if (h == y)
                        {
                            vz.push_back(g[x][i].se);
                            break;
                        }
                    }
                }
                double u = 0;
                u = vz[0] - vz.back();
                for (int i = 1; i < sz(vz) - 1; ++i)
                    u = vz[i] - u;
                u /= 2;
                if (sz(vv) == 1)
                    u = vz[0] / 2;
                double yyans = stg(vv.back(), u);
                if (yyans < yans)
                {
                    yans = yyans;
                    for (int i = 0; i < v.size(); ++i)
                        ansa[v[i]] = a[v[i]];
                }
            }
            else
            {
                /*for (double u = -1000; u <= 1000; u += 0.5)
                {
                    double yyans = stg(x, u);
                    if (yyans < yans)
                    {
                        yans = yyans;
                        for (int i = 0; i < v.size(); ++i)
                            ansa[v[i]] = a[v[i]];
                    }
                }*/
                int l = 0, r = sz(t) - 1;
                while ((r - l) > 20)
                {
                    int m = (l + r) / 2;
                    if (stg(x, t[m]) < stg(x, t[m + 1]))
                        r = m + 1;
                    else
                        l = m;
                }
                for (int i = max(0, l - 10); i <= min(sz(t) - 1, r + 10); ++i)
                {
                    double yyans = stg(x, t[i]);
                    if (yyans < yans)
                    {
                        yans = yyans;
                        for (int i = 0; i < v.size(); ++i)
                            ansa[v[i]] = a[v[i]];
                    }
                }
            }
            if (yans == INF)
            {
                printf("NO\n");
                return;
            }
            ans += yans;
        }
    }

    printf("YES\n");
    for (int x = 1; x <= n; ++x)
        printf("%.9f ", ansa[x]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}