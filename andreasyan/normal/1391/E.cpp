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
const int N = 500005;

int n, m;
vector<int> g[N];

bool c[N];

vector<int> t[N];
void dfs0(int x)
{
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
        {
            t[x].push_back(h);
            t[h].push_back(x);
            dfs0(h);
        }
    }
}

int d[N];
void dfsd(int x, int p)
{
    d[x] = 1;
    for (int i = 0; i < t[x].size(); ++i)
    {
        int h = t[x][i];
        if (h == p)
            continue;
        dfsd(h, x);
        d[x] = max(d[x], d[h] + 1);
    }
}

bool stgpath()
{
    dfsd(1, 1);
    int x = 1;
    while (1)
    {
        int hh;
        int maxu = -1;
        for (int i = 0; i < t[x].size(); ++i)
        {
            int h = t[x][i];
            if (d[h] < d[x])
            {
                if (d[h] > maxu)
                {
                    maxu = d[h];
                    hh = h;
                }
            }
        }
        if (maxu == -1)
            break;
        x = hh;
    }
    dfsd(x, x);
    if (d[x] >= n / 2 + n % 2)
    {
        vector<int> v;
        while (1)
        {
            v.push_back(x);
            int hh;
            int maxu = -1;
            for (int i = 0; i < t[x].size(); ++i)
            {
                int h = t[x][i];
                if (d[h] < d[x])
                {
                    if (d[h] > maxu)
                    {
                        maxu = d[h];
                        hh = h;
                    }
                }
            }
            if (maxu == -1)
                break;
            x = hh;
        }
        printf("PATH\n");
        printf("%d\n", sz(v));
        for (int i = 0; i < sz(v); ++i)
            printf("%d ", v[i]);
        printf("\n");
        return true;
    }
    return false;
}

int q[N];
vector<pair<int, int> > ans;
void sar()
{
    set<pair<int, int> > s;
    for (int x = 1; x <= n; ++x)
    {
        if (x == 1)
            q[x] = sz(t[x]);
        else
            q[x] = sz(t[x]) - 1;
        s.insert(m_p(q[x], x));
    }
    while (sz(s) > 1)
    {
        int x = s.begin()->se;
        s.erase(s.begin());
        int y = s.begin()->se;
        s.erase(s.begin());
        if (q[x] || q[y])
            break;
        ans.push_back(m_p(x, y));
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (q[h])
            {
                s.erase(m_p(q[h], h));
                --q[h];
                s.insert(m_p(q[h], h));
            }
        }
        for (int i = 0; i < g[y].size(); ++i)
        {
            int h = t[y][i];
            if (q[h])
            {
                s.erase(m_p(q[h], h));
                --q[h];
                s.insert(m_p(q[h], h));
            }
        }
    }
}

void solv()
{
    scanf("%d%d", &n, &m);

    for (int x = 1; x <= n; ++x)
    {
        g[x].clear();
        t[x].clear();
        c[x] = false;
    }

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs0(1);
    for (int x = 1; x <= n; ++x)
        g[x] = t[x];
    if (stgpath())
        return;
    ans.clear();
    sar();
    printf("PAIRING\n");
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); ++i)
        printf("%d %d\n", ans[i].fi, ans[i].se);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}