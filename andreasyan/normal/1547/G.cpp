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

int n, m;
vector<int> g[N], rg[N];

int c[N];

vector<int> v;
void dfs0(int x)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs0(h);
    }
    v.push_back(x);
}

int k;
void dfs1(int x)
{
    c[x] = k;
    for (int i = 0; i < rg[x].size(); ++i)
    {
        int h = rg[x][i];
        if (!c[h])
            dfs1(h);
    }
}

int ans[N];

int qk[N];
vector<int> gg[N];
int q[N];

void solv()
{
    cin >> n >> m;

    for (int x = 1; x <= n; ++x)
    {
        g[x].clear();
        rg[x].clear();
        c[x] = 0;
        ans[x] = 0;
        qk[x] = 0;
        gg[x].clear();
        q[x] = 0;
    }
    v.clear();
    k = 0;

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        rg[y].push_back(x);
    }

    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            dfs0(x);
        }
    }
    reverse(all(v));
    for (int x = 1; x <= n; ++x)
        c[x] = 0;
    for (int i = 0; i < n; ++i)
    {
        int x = v[i];
        if (!c[x])
        {
            ++k;
            dfs1(x);
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < g[x].size(); ++i)
        {
            int y = g[x][i];
            if (c[x] == c[y])
                ++qk[c[x]];
            else
            {
                gg[c[x]].push_back(c[y]);
                ++q[c[y]];
            }
        }
    }

    queue<int> qu;
    for (int x = 1; x <= k; ++x)
    {
        if (q[x] == 0)
            qu.push(x);
    }

    ans[c[1]] = 1;
    while (!qu.empty())
    {
        int x = qu.front();
        qu.pop();

        if (qk[x])
        {
            if (ans[x] > 0)
                ans[x] = -1;
        }

        for (int i = 0; i < gg[x].size(); ++i)
        {
            int h = gg[x][i];
            --q[h];
            if (ans[x] == -1)
                ans[h] = -1;
            else
            {
                if (ans[h] != -1)
                    ans[h] = min(ans[h] + ans[x], 2);
            }
            if (q[h] == 0)
                qu.push(h);
        }
    }

    for (int x = 1; x <= n; ++x)
        cout << ans[c[x]] << ' ';
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}