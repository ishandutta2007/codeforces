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
vector<int> g[N];
vector<int> gi[N];

vector<pair<int, int> > vk;
bool c[N];
void dfs(int x)
{
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
        {
            vk.push_back(m_p(x, h));
            dfs(h);
        }
    }
}

vector<vector<int> > ans;
vector<int> v;
bool dfs1(int x, int p, int y)
{
    v.push_back(x);
    if (x == y)
        return true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        c[gi[x][i]] ^= true;
        if (dfs1(h, x, y))
            return true;
        c[gi[x][i]] ^= true;
    }
    v.pop_back();
    return false;
}

void solv()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);
    for (int x = 1; x <= n; ++x)
        g[x].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x = vk[i].fi;
        int y = vk[i].se;
        g[x].push_back(y);
        g[y].push_back(x);
        gi[x].push_back(i);
        gi[y].push_back(i);
    }
    for (int i = 0; i < n - 1; ++i)
        c[i] = false;

    int qq;
    cin >> qq;
    while (qq--)
    {
        int x, y;
        cin >> x >> y;

        v.clear();
        dfs1(x, x, y);
        ans.push_back(v);
    }

    bool z = true;
    for (int i = 0; i < n - 1; ++i)
    {
        if (c[i])
        {
            z = false;
            break;
        }
    }

    if (z)
    {
        cout << "YES\n";
        for (int i = 0; i < sz(ans); ++i)
        {
            cout << sz(ans[i]) << "\n";
            for (int j = 0; j < sz(ans[i]); ++j)
                cout << ans[i][j] << ' ';
            cout << "\n";
        }
        return;
    }

    int yans = 0;
    for (int i = 0; i < n - 1; ++i)
        yans += c[i];

    for (int x = 1; x <= n; ++x)
    {
        int q = 0;
        for (int i = 0; i < g[x].size(); ++i)
        {
            q += c[gi[x][i]];
        }
        yans -= (q / 2);
    }

    cout << "NO\n";
    cout << yans << "\n";
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