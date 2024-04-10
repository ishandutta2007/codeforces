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

int n, m, k;
int a[N];
vector<int> g[N], gr[N];

int c[N];
bool dfs(int x)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h] == 1)
            return true;
        if (c[h] == 0)
        {
            if (dfs(h))
                return true;
        }
    }
    c[x] = 2;
    return false;
}

int l[N];
void dfs1(int x)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs1(h);
        l[x] = max(l[x], l[h] + 1);
    }
}

int r[N];
void dfs2(int x)
{
    c[x] = 1;
    for (int i = 0; i < gr[x].size(); ++i)
    {
        int h = gr[x][i];
        if (!c[h])
            dfs2(h);
        r[x] = min(r[x], r[h] - 1);
    }
}

vector<int> v[N];
int ans[N];

void solv()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        gr[y].push_back(x);
    }

    for (int x = 1; x <= n; ++x)
    {
        if (c[x] == 0)
        {
            if (dfs(x))
            {
                cout << "-1\n";
                return;
            }
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        l[x] = 1;
        r[x] = k;
        if (a[x])
            l[x] = r[x] = a[x];
    }

    memset(c, 0, sizeof c);
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            dfs1(x);
        }
    }

    memset(c, 0, sizeof c);
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            dfs2(x);
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        if (l[x] > r[x])
        {
            cout << "-1\n";
            return;
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        v[r[x]].push_back(x);
    }

    set<pair<int, int> > s;
    for (int i = k; i >= 1; --i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            s.insert(m_p(l[v[i][j]], v[i][j]));
        }
        while (1)
        {
            if (s.empty())
            {
                cout << "-1\n";
                return;
            }
            int x = (--s.end())->se;
            s.erase((--s.end()));
            if (l[x] > i)
            {
                ans[x] = l[x];
                continue;
            }
            ans[x] = i;
            break;
        }
    }
    while (!s.empty())
    {
        int x = (--s.end())->se;
        s.erase((--s.end()));
        ans[x] = l[x];
    }

    for (int x = 1; x <= n; ++x)
        cout << ans[x] << ' ';
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
    //scanf("%d", &tt);
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}