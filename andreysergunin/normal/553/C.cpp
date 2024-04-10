#include <bits/stdc++.h>
#define fs first
#define sc second

using namespace std;

const int MAXN = 200000;
const int p = 1e9 + 7;

vector<int> f[MAXN], edge[MAXN];
vector< pair<int, int> > e;
int vis[MAXN];
bool flag;

void dfs(int v, int c)
{
    vis[v] = c;
    for (int i = 0; i < (int)f[v].size(); i++)
        if (vis[f[v][i]] == 0)
            dfs(f[v][i], c);

}

void dfs1(int v, int c)
{
    vis[v] = c;
    for (int i = 0; i < (int)edge[v].size(); i++)
    {
        if (vis[edge[v][i]] == 0)
            dfs1(edge[v][i], 3 - c);
        else
            if (c + vis[edge[v][i]] != 3)
                flag = false;

    }

}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (c == 1)
        {
            f[a].push_back(b);
            f[b].push_back(a);
        }
        else
            e.push_back(make_pair(a, b));

    }
    for (int i = 0; i < n; i++)
        vis[i] = 0;
    int c = 1;
    for (int i = 0; i < n; i++)
        if (vis[i] == 0)
            dfs(i, c++);
    for (int i = 0; i < (int)e.size(); i++)
    {
        if (vis[e[i].fs] == vis[e[i].sc])
        {
            cout << 0 << endl;
            return 0;
        }
        edge[vis[e[i].fs]].push_back(vis[e[i].sc]);
        edge[vis[e[i].sc]].push_back(vis[e[i].fs]);
    }
    int t = 0;
    flag = true;
    for (int i = 1; i < c; i++)
        vis[i] = 0;
    for (int i = 1; i < c; i++)
        if (vis[i] == 0)
        {
            t++;
            dfs1(i, 1);
        }
    if (!flag)
    {
        cout << 0 << endl;
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < t - 1; i++)
        ans = ans * 2 % p;
    cout << ans << endl;
    return 0;

}