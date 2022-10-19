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

int n, m;
vector<pair<int, int> > g[N];

int c[N];
bool f;
int q[3];
void dfs(int x, int gg)
{
    if (c[x])
    {
        if (gg != c[x])
            f = false;
        return;
    }
    ++q[gg];
    c[x] = gg;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (g[x][i].se == 0)
            dfs(h, gg);
        else
            dfs(h, 3 - gg);
    }
}

void solv()
{
    cin >> n >> m;
    f = true;
    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        c[i] = 0;
    }
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        string s;
        cin >> x >> y >> s;
        if (s[0] == 'i')
        {
            g[x].push_back(m_p(y, 1));
            g[y].push_back(m_p(x, 1));
        }
        else
        {
            g[x].push_back(m_p(y, 0));
            g[y].push_back(m_p(x, 0));
        }
    }

    int ans = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (c[x])
            continue;
        q[1] = q[2] = 0;
        dfs(x, 1);
        if (!f)
        {
            cout << "-1\n";
            return;
        }
        ans += max(q[1], q[2]);
    }

    cout << ans << "\n";
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
        solv();
    return 0;
}