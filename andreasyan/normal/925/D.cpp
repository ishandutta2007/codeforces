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
const int N = 300005, INF = 1000000009;

int n, m;
vector<int> g[N];

int d[N];
int pb[N];
void bfs()
{
    for (int x = 1; x <= n; ++x)
        d[x] = INF;
    queue<int> q;
    q.push(1);
    d[1] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (d[h] == INF)
            {
                pb[h] = x;
                d[h] = d[x] + 1;
                q.push(h);
            }
        }
    }
}

int k;
int c[N];
int q[N];
void dfs(int x)
{
    c[x] = k;
    ++q[k];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == 1)
            continue;
        if (!c[h])
            dfs(h);
    }
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

    bfs();

    int ans2 = INF;
    int qq = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (d[x] != INF)
            ++qq;
    }
    if (sz(g[1]) + 1 != qq)
    {
        ans2 = 4;
    }
    else
    {
        for (int i = 0; i < g[1].size(); ++i)
        {
            int x = g[1][i];
            if (!c[x])
            {
                ++k;
                dfs(x);
            }
        }
        for (int i = 0; i < g[1].size(); ++i)
        {
            int x = g[1][i];
            if (sz(g[x]) != q[c[x]])
            {
                ans2 = 5;
                break;
            }
        }
    }

    if (min(d[n], ans2) == INF)
    {
        cout << "-1\n";
        return;
    }

    if (d[n] <= ans2)
    {
        vector<int> ans;
        int x = n;
        while (x != 1)
        {
            ans.push_back(x);
            x = pb[x];
        }
        ans.push_back(1);
        reverse(all(ans));

        cout << d[n] << "\n";
        for (int i = 0; i < sz(ans); ++i)
            cout << ans[i] << ' ';
        cout << "\n";
    }
    else
    {
        if (sz(g[1]) + 1 != qq)
        {
            sort(all(g[1]));
            for (int i = 0; i < g[1].size(); ++i)
            {
                int h = g[1][i];
                for (int j = 0; j < g[h].size(); ++j)
                {
                    int hh = g[h][j];
                    if (!binary_search(all(g[1]), hh) && hh != 1)
                    {
                        cout << "4\n";
                        cout << 1 << ' ' << h << ' ' << hh << ' ' << 1 << ' ' << n << "\n";
                        return;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < g[1].size(); ++i)
            {
                int x = g[1][i];
                if (sz(g[x]) != q[c[x]])
                {
                    sort(all(g[x]));
                    for (int i = 0; i < g[x].size(); ++i)
                    {
                        int h = g[x][i];
                        if (h == 1)
                            continue;
                        for (int j = 0; j < g[h].size(); ++j)
                        {
                            int hh = g[h][j];
                            if (!binary_search(all(g[x]), hh) && hh != 1 && hh != x)
                            {
                                cout << "5\n";
                                cout << 1 << ' ' << x << ' ' << h << ' ' << hh << ' ' << x << ' ' << n << "\n";
                                return;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}