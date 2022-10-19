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

int n;
int a[N];
vector<int> g[N];

int tin[N], tout[N], ti;
void dfs0(int x, int p)
{
    tin[x] = ++ti;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
    }
    tout[x] = ti;
}

vector<int> v[N];

bool dp[N];
bool stg(int x, int h)
{
    if (!dp[h])
        return false;
    auto it = lower_bound(all(v[a[x]]), tin[h]);
    if (it != v[a[x]].end() && *it <= tout[h])
        return false;
    return true;
}
void dfs1(int x, int p)
{
    dp[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs1(h, x);
        dp[x] = (dp[x] && stg(x, h));
    }
}

int ans;
void dfs2(int x, int p)
{
    if (dp[x])
    {
        if (sz(v[a[x]]) == 1)
            ++ans;
    }
    vector<int> t;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (!stg(x, h))
            t.push_back(h);
    }
    auto it = upper_bound(all(v[a[x]]), tout[x]);
    if (it != v[a[x]].end())
        return;
    if (v[a[x]][0] != tin[x])
        return;
    if (sz(t) >= 2)
        return;
    if (sz(t) == 1)
    {
        dfs2(t[0], x);
        return;
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs2(h, x);
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs0(1, 1);

    vector<int> xt;
    for (int x = 1; x <= n; ++x)
        xt.push_back(a[x]);
    sort(all(xt));
    for (int x = 1; x <= n; ++x)
        a[x] = lower_bound(all(xt), a[x]) - xt.begin() + 1;

    for (int x = 1; x <= n; ++x)
        v[a[x]].push_back(tin[x]);
    for (int i = 1; i <= n; ++i)
        sort(all(v[i]));

    dfs1(1, 1);

    dfs2(1, 1);

    cout << ans << endl;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}