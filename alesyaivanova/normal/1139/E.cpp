#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<long long, long long>
#define pb emplace_back
#define mp make_pair

const int MAXN = 5009;
multiset<int> g[MAXN][2];
int mt[MAXN][2];
int p[MAXN];
int c[MAXN];
int n, m;
bool used[MAXN];

bool dfs(int v)
{
    used[v] = true;
    for (int to : g[v][0])
    {
        if (to != mt[v][0] && mt[to][1] == -1)
        {
            mt[to][1] = v;
            mt[v][0] = to;
            return true;
        }
    }
    for (int to : g[v][0])
    {
        if (!used[mt[to][1]] && dfs(mt[to][1]))
        {
            mt[to][1] = v;
            mt[v][0] = to;
            return true;
        }
    }
    return false;
}

int dfs1(int v)
{
    used[v] = true;
    int ans = v;
    for (int to : g[v][0])
    {
        if (!used[mt[to][1]])
             ans = max(ans, dfs1(mt[to][1]));
    }
    return ans;
}

bool dfs2(int v, int t)
{
    used[v] = true;
    if (v == t)
    {
        mt[v][0] = -1;
        return true;
    }
    for (int to : g[v][0])
    {
        if (!used[mt[to][1]] && dfs2(mt[to][1], t))
        {
            mt[to][1] = v;
            mt[v][0] = to;
            return true;
        }
    }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        c[i]--;
        g[p[i]][0].insert(c[i]);
        g[c[i]][1].insert(p[i]);
    }
    for (int i = 0; i < MAXN; i++)
    {
        mt[i][0] = -1;
        mt[i][1] = -1;
    }
    int mex;
    for (int i = 0; i < MAXN; i++)
    {
        if (mt[i][0] == -1)
        {
            for (int e = 0; e < MAXN; e++)
                used[e] = false;
            dfs(i);
        }
        if (mt[i][0] == -1)
        {
            mex = i;
            break;
        }
    }
    int q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        /*for (int i = 0; i < 3; i++)
            cout << mt[i][0] << " " << mt[i][1] << "\n";*/
        int e;
        cin >> e;
        e--;
        int y = mt[c[e]][1];
        g[p[e]][0].erase(g[p[e]][0].find(c[e]));
        g[c[e]][1].erase(g[c[e]][1].find(p[e]));
        if (y == p[e] && g[c[e]][1].find(p[e]) == g[c[e]][1].end())
        {
            mt[p[e]][0] = -1;
            mt[c[e]][1] = -1;
            if (p[e] >= mex)
            {
                cout << mex << "\n";
                continue;
            }
            for (int j = 0; j < MAXN; j++)
                used[j] = false;
            dfs(p[e]);
            if (mt[p[e]][0] != -1)
                cout << mex << "\n";
            else
            {
                for (int j = 0; j < MAXN; j++)
                    used[j] = false;
                int x = dfs1(p[e]);
                if (x > p[e])
                {
                    for (int j = 0; j < MAXN; j++)
                        used[j] = false;
                    dfs2(p[e], x);
                    mex = min(mex, x);
                }
                else
                    mex = p[e];
                cout << mex << "\n";
            }
        }
        else
            cout << mex << "\n";
    }
}