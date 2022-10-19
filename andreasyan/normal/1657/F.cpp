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
const int N = 400005, m = 20;

int n, qq;
vector<int> g[N];

int p[N][m];
int tin[N], tout[N], ti;
void dfs0(int x, int p0)
{
    tin[x] = ++ti;
    p[x][0] = p0;
    for (int i = 1; i < m; ++i)
        p[x][i] = p[p[x][i - 1]][i - 1];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p0)
            continue;
        dfs0(h, x);
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tin[y] <= tout[x]);
}

int go(int x, int y)
{
    if (!isp(x, y))
        return p[x][0];
    for (int i = m - 1; i >= 0; --i)
    {
        if (!isp(p[y][i], x))
            y = p[y][i];
    }
    return y;
}

vector<int> gg[N * 26];
bool cc[N * 26];

char ans[N];
vector<int> v;
bool dfs(int x, char y)
{
    if (cc[x * 26 + y - 'a'])
        return false;
    v.push_back(x);
    ans[x] = y;
    for (int i = 0; i < gg[x * 26 + y - 'a'].size(); ++i)
    {
        int h = gg[x * 26 + y - 'a'][i];
        if (ans[h / 26])
        {
            if (ans[h / 26] != h % 26 + 'a')
                return false;
        }
        else
        {
            if (!dfs(h / 26, h % 26 + 'a'))
                return false;
        }
    }
    return true;
}

void solv()
{
    cin >> n >> qq;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs0(1, 1);

    while (qq--)
    {
        string s;
        int x, y;
        cin >> x >> y >> s;

        vector<int> v;
        while (x != y)
        {
            v.push_back(x);
            x = go(x, y);
        }
        v.push_back(x);

        assert(sz(v) == sz(s));

        int u = -1;
        for (int i = 0; i < sz(v); ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                if (j != s[i] - 'a' && j != s[sz(v) - i - 1] - 'a')
                    cc[v[i] * 26 + j] = true;
            }
            if (s[i] != s[sz(v) - i - 1])
            {
                if (u == -1)
                    u = i;
                else
                {
                    gg[v[u] * 26 + s[u] - 'a'].push_back(v[i] * 26 + s[i] - 'a');
                    gg[v[i] * 26 + s[i] - 'a'].push_back(v[u] * 26 + s[u] - 'a');

                    gg[v[u] * 26 + s[sz(v) - u - 1] - 'a'].push_back(v[i] * 26 + s[sz(v) - i - 1] - 'a');
                    gg[v[i] * 26 + s[sz(v) - i - 1] - 'a'].push_back(v[u] * 26 + s[sz(v) - u - 1] - 'a');
                }
            }
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        if (ans[x])
            continue;
        bool z = false;
        for (int j = 0; j < 26; ++j)
        {
            if (cc[x * 26 + j])
                continue;
            v.clear();
            if (!dfs(x, j + 'a'))
            {
                for (int i = 0; i < sz(v); ++i)
                    ans[v[i]] = 0;
            }
            else
            {
                z = true;
                break;
            }
        }
        if (!z)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
        cout << ans[i];
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