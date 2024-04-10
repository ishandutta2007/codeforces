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
const int N = 1000006;

int n;
string s[N];
vector<int> g[N];

int ans[N];
void dfs(int x)
{
    if (s[x] == "IN")
    {
        ans[x] = g[x][0];
        return;
    }
    for (int i = 0; i < g[x].size(); ++i)
        dfs(g[x][i]);
    if (s[x] == "NOT")
    {
        ans[x] = (1 - ans[g[x][0]]);
    }
    else if (s[x] == "AND")
    {
        ans[x] = (ans[g[x][0]] & ans[g[x][1]]);
    }
    else if (s[x] == "OR")
    {
        ans[x] = (ans[g[x][0]] | ans[g[x][1]]);
    }
    else
    {
        ans[x] = (ans[g[x][0]] ^ ans[g[x][1]]);
    }
}

bool c[N];
void dfs1(int x)
{
    c[x] = true;
    if (s[x] == "IN")
        return;
    if (s[x] == "NOT")
    {
        dfs1(g[x][0]);
    }
    else if (s[x] == "AND")
    {
        if (ans[g[x][0]] == 0 && ans[g[x][1]] == 0)
            return;
        if (ans[g[x][0]] == 1 && ans[g[x][1]] == 1)
        {
            dfs1(g[x][0]);
            dfs1(g[x][1]);
        }
        else if (ans[g[x][0]] == 0)
            dfs1(g[x][0]);
        else if (ans[g[x][1]] == 0)
            dfs1(g[x][1]);
    }
    else if (s[x] == "OR")
    {
        if (ans[g[x][0]] == 1 && ans[g[x][1]] == 1)
            return;
        if (ans[g[x][0]] == 0 && ans[g[x][1]] == 0)
        {
            dfs1(g[x][0]);
            dfs1(g[x][1]);
        }
        else if (ans[g[x][0]] == 1)
            dfs1(g[x][0]);
        else if (ans[g[x][1]] == 1)
            dfs1(g[x][1]);
    }
    else
    {
        dfs1(g[x][0]);
        dfs1(g[x][1]);
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        if (s[i] == "NOT" || s[i] == "IN")
        {
            int x;
            cin >> x;
            g[i].push_back(x);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            g[i].push_back(x);
            g[i].push_back(y);
        }
    }

    dfs(1);
    dfs1(1);

    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == "IN")
        {
            if (c[i])
                cout << (1 - ans[1]);
            else
                cout << ans[1];
        }
    }
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