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
vector<int> g[N];

int c[N];
bool dfs(int x)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h] == 0)
        {
            if (dfs(h))
                return true;
        }
        else if (c[h] == 1)
            return true;
    }
    c[x] = 2;
    return false;
}

int ans[N];
void dfs1(int x)
{
    if (g[x].empty())
    {
        ans[x] = 1;
        return;
    }

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!ans[h])
            dfs1(h);
        if (x > h)
            ans[x] = max(ans[x], ans[h]);
        else
            ans[x] = max(ans[x], ans[h] + 1);
    }
}

void solv()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        c[i] = 0;
        ans[i] = 0;
    }

    for (int x = 1; x <= n; ++x)
    {
        int q;
        cin >> q;
        while (q--)
        {
            int y;
            cin >> y;
            g[x].push_back(y);
        }
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
        if (!ans[x])
            dfs1(x);
    }

    int yans = 0;
    for (int x = 1; x <= n; ++x)
        yans = max(yans, ans[x]);

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
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}