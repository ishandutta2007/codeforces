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
const int N = 300005;

int n, m;
int d[N];
vector<int> g[N], gi[N];

vector<int> v;
bool c[N];
void dfsv(int x)
{
    c[x] = true;
    v.push_back(x);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfsv(h);
    }
}

vector<int> ans;
int q[N];
void dfs(int x, int pk)
{
    c[x] = true;
    if (d[x] == 1)
        q[x] = 1;
    else
        q[x] = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
        {
            dfs(h, gi[x][i]);
            q[x] += q[h];
        }
    }
    if (q[x] % 2 == 1)
        ans.push_back(pk);
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);

        gi[x].push_back(i);
        gi[y].push_back(i);
    }

    for (int x = 1; x <= n; ++x)
    {
        if (c[x])
            continue;

        v.clear();
        dfsv(x);

        int q = 0;
        int u = 0;
        for (int i = 0; i < sz(v); ++i)
        {
            int x = v[i];
            if (d[x] == 1)
                ++q;
            else if (d[x] == -1)
                u = x;
        }

        if (q % 2 == 1 && u == 0)
        {
            cout << "-1\n";
            return;
        }

        if (q % 2 == 1)
            d[u] = 1;

        for (int i = 0; i < sz(v); ++i)
            c[v[i]] = false;
        dfs(v[0], -1);
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
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