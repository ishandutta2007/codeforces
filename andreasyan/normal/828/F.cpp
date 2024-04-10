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

struct ban
{
    int x, y, d;
    int i;
};
bool operator<(const ban& a, const ban& b)
{
    return a.d < b.d;
}

int n, m;
ban b[N];

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

bool in[N];
vector<pair<int, int> > g[N];
vector<int> gi[N];

const int l = 20;
int maxu[N][l];
int pp[N][l];
int tin[N], tout[N], ti;
int pi[N];
void dfs(int x, int p, int k)
{
    tin[x] = ++ti;
    pp[x][0] = p;
    maxu[x][0] = k;
    for (int i = 1; i < l; ++i)
    {
        pp[x][i] = pp[pp[x][i - 1]][i - 1];
        maxu[x][i] = max(maxu[x][i - 1], maxu[pp[x][i - 1]][i - 1]);
    }

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        int hd = g[x][i].se;
        if (h == p)
            continue;
        pi[h] = gi[x][i];
        dfs(h, x, hd);
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tin[y] <= tout[x]);
}

int qry(int x, int y)
{
    if (isp(x, y))
        return 0;

    int ans = 0;
    for (int i = l - 1; i >= 0; --i)
    {
        if (!isp(pp[x][i], y))
        {
            ans = max(ans, maxu[x][i]);
            x = pp[x][i];
        }
    }

    ans = max(ans, maxu[x][0]);
    return ans;
}

int ans[N];

void solv()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i].x >> b[i].y >> b[i].d;
        b[i].i = i;
    }
    sort(b, b + m);

    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 0; i < m; ++i)
    {
        if (fi(b[i].x) != fi(b[i].y))
        {
            g[b[i].x].push_back(m_p(b[i].y, b[i].d));
            g[b[i].y].push_back(m_p(b[i].x, b[i].d));
            gi[b[i].x].push_back(b[i].i);
            gi[b[i].y].push_back(b[i].i);
            kpc(b[i].x, b[i].y);
            in[i] = true;
        }
    }

    dfs(1, 1, 0);

    for (int i = 0; i < m; ++i)
        ans[i] = -1;

    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 0; i < m; ++i)
    {
        if (!in[i])
        {
            ans[b[i].i] = max(qry(b[i].x, b[i].y), qry(b[i].y, b[i].x)) - 1;

            {
                int x = b[i].x;
                int y = b[i].y;

                while (1)
                {
                    x = fi(x);
                    if (isp(x, y))
                        break;
                    ans[pi[x]] = b[i].d - 1;
                    p[x] = pp[x][0];
                    x = p[x];
                }
            }
            {
                int x = b[i].y;
                int y = b[i].x;

                while (1)
                {
                    x = fi(x);
                    if (isp(x, y))
                        break;
                    ans[pi[x]] = b[i].d - 1;
                    p[x] = pp[x][0];
                    x = p[x];
                }
            }
        }
    }

    for (int i = 0; i < m; ++i)
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