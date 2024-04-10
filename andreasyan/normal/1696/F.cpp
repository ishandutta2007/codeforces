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
const int N = 102;

int n;
bool t[N][N][N];
vector<pair<int, int> > v[N];

vector<pair<int, int> > yans;
vector<int> ans[N];

int d[N];
void dfs(int x, int p)
{
    if (x == p)
        d[x] = 0;
    else
        d[x] = d[p] + 1;
    for (int i = 0; i < ans[x].size(); ++i)
    {
        int h = ans[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
}

void solv()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        v[i].clear();
        ans[i].clear();
    }
    memset(t, false, sizeof t);
    yans.clear();

    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            char z[N];
            cin >> (z + 1);
            for (int k = 1; k <= n; ++k)
            {
                if (z[k] == '1')
                {
                    v[k].push_back(m_p(i, j));
                    t[k][i][j] = true;
                }
            }
        }
    }

    vector<int> g;
    for (int x = 1; x <= n; ++x)
        g.push_back(x);
    while (sz(g) > 2)
    {
        vector<int> t, tc;
        int minu = N * N * N;
        for (int i = 0; i < sz(g); ++i)
        {
            int x = g[i];
            minu = min(minu, sz(v[x]));
        }
        for (int i = 0; i < sz(g); ++i)
        {
            int x = g[i];
            if (sz(v[x]) == minu)
                t.push_back(x);
            else
                tc.push_back(x);
        }

        for (int i = 0; i < sz(t); ++i)
        {
            int x = t[i];

            bool z = false;
            for (int j = 0; j < sz(tc); ++j)
            {
                int p = tc[j];

                bool zz = true;
                for (int k = 0; k < sz(v[x]); ++k)
                {
                    if (!binary_search(all(v[p]), v[x][k]))
                    {
                        zz = false;
                        break;
                    }
                }
                if (!zz)
                    continue;
                assert(zz);

                for (int k = 0; k < sz(v[p]); ++k)
                {
                    if (!binary_search(all(v[x]), v[p][k]))
                    {
                        if (v[p][k].fi != x && v[p][k].se != x)
                        {
                            zz = false;
                            break;
                        }
                    }
                }
                if (!zz)
                    continue;

                ans[x].push_back(p);
                ans[p].push_back(x);
                yans.push_back(m_p(p, x));
                z = true;
                break;
            }

            if (!z)
            {
                cout << "No\n";
                return;
            }
        }

        g = tc;
        for (int i = 0; i < sz(g); ++i)
        {
            int x = g[i];
            vector<pair<int, int> > vv;
            for (int j = 0; j < sz(v[x]); ++j)
            {
                if (!binary_search(all(g), v[x][j].fi))
                    continue;
                if (!binary_search(all(g), v[x][j].se))
                    continue;
                vv.push_back(v[x][j]);
            }
            v[x] = vv;
        }
    }

    if (sz(g) == 2)
    {
        ans[g[0]].push_back(g[1]);
        ans[g[1]].push_back(g[0]);
        yans.push_back(m_p(g[0], g[1]));
    }

    for (int x = 1; x <= n; ++x)
    {
        dfs(x, x);
        for (int y = 1; y <= n; ++y)
        {
            for (int z = y + 1; z <= n; ++z)
            {
                if (d[y] == d[z] && !t[x][y][z])
                {
                    cout << "No\n";
                    return;
                }
                if (d[y] != d[z] && t[x][y][z])
                {
                    cout << "No\n";
                    return;
                }
            }
        }
    }

    cout << "Yes\n";
    assert(sz(yans) == n - 1);
    for (int i = 0; i < n - 1; ++i)
        cout << yans[i].fi << ' ' << yans[i].se << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}