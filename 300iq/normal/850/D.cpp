
/*
    !  !!!
   
   
   
   
   
   
   
   
   
   
   
*/

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>

using namespace std;

typedef long long ll;

mt19937 rnd(228);


const int N = 2e5 + 7;
const int M = (1 << 30);

vector <int> g[N];
int d[N];
int ptr[N];
bool used[N];

struct edge
{
    int v, to, cap, flow;
};

vector <edge> e;

void add_edge(int v, int to, int cap)
{
    g[v].push_back(e.size());
    e.push_back({v, to, cap, 0});
    g[to].push_back(e.size());
    e.push_back({to, v, 0, 0});
}

int n;
int l;

bool bfs(int s, int t)
{
    for (int i = 0; i < n; i++)
    {
        d[i] = -1;
    }
    d[s] = 0;
    queue <int> q;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int ind : g[v])
        {
            int to = e[ind].to, cap = e[ind].cap;
            if (d[to] == -1 && cap >= l)
            {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
    return d[t] != -1;
}

int dfs(int v, int t, int fl)
{
    if (v == t)
    {
        return fl;
    }
    for (; ptr[v] < (int) g[v].size(); ptr[v]++)
    {
        int ind = g[v][ptr[v]];
        int to = e[ind].to, cap = e[ind].cap;
        if (cap >= l && d[to] == d[v] + 1)
        {
            int push = dfs(to, t, min(fl, cap));
            if (push)
            {
                e[ind].cap -= push;
                e[ind].flow += push;
                e[ind ^ 1].cap += push;
                e[ind ^ 1].flow -= push;
                return push;
            }
        }
    }
    return 0;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int m;
    cin >> m;
    vector <int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    m = (int) a.size();
    for (int ans = 1; ; ans++)
    {
        vector <vector <vector <int> > > dp(ans + 1, vector <vector <int> > (ans * (ans - 1) / 2 + 1, vector <int> (m)));
        vector <vector <vector <pair <int, int> > > > pr(ans + 1, vector <vector <pair <int, int> > > (ans * (ans - 1) / 2 + 1, vector <pair <int, int> > (m)));
        dp[0][0][0] = 1;
        pr[0][0][0] = {-1, -1};
        for (int i = 0; i < ans; i++)
        {
            for (int sum = 0; sum <= ans * (ans - 1) / 2; sum++)
            {
                for (int last = 0; last < m; last++)
                {
                    if (dp[i][sum][last])
                    {
                        int l = last, r = min(m - 1, last + 1);
                        if (i == 0)
                        {
                            r = 0;
                        }
                        for (int cur = l; cur <= r; cur++)
                        {
                            if (sum + a[cur] >= i * (i + 1) / 2 && sum + a[cur] <= ans * (ans - 1) / 2)
                            {
                                dp[i + 1][sum + a[cur]][cur] = 1;
                                pr[i + 1][sum + a[cur]][cur] = {sum, last};
                            }
                        }
                    }
                }
            }
        }
        if (dp[ans][ans * (ans - 1) / 2][m - 1])
        {
            int cur = ans;
            int sum = ans * (ans - 1) / 2;
            int last = m - 1;
            vector <int> deg;
            while (cur != 0)
            {
                deg.push_back(a[last]);
                auto res = pr[cur][sum][last];
                sum = res.first;
                last = res.second;
                cur--;
            }
            int prev_sz = ans + ans * ans;
            for (int i = 0; i < ans; i++) for (int j = i + 1; j < ans; j++) prev_sz++;
            int s = prev_sz + 1;
            int t = prev_sz + 2;
            for (int i = 0; i < ans; i++)
            {
                add_edge(s, i, deg[i]);
            }
            for (int i = 0; i < ans; i++)
            {
                for (int j = 0; j < ans; j++)
                {
                    if (i != j)
                    {
                        add_edge(i, ans + (i * ans + j), 1);
                    }
                }
            }
            int sz = ans + ans * ans;
            for (int i = 0; i < ans; i++)
            {
                for (int j = i + 1; j < ans; j++)
                {
                    if (i != j)
                    {
                        add_edge(ans + i * ans + j, sz, 1);
                        add_edge(ans + j * ans + i, sz, 1);
                        add_edge(sz, t, 1);
                        sz++;
                    }
                }
            }
            n = t + 1;
            sum = 0;
            for (l = M; l > 0; l /= 2)
            {
                while (bfs(s, t))
                {
                    for (int i = 0; i < n; i++)
                    {
                        ptr[i] = 0;
                    }
                    while (int cur = dfs(s, t, M))
                    {
                        sum += cur;
                    }
                }
            }
            vector <vector <int> > g(ans, vector <int> (ans));
            for (auto c : e)
            {
                if (c.v < ans && c.flow == 1)
                {
                    g[c.v][c.to % ans] = 1;
                }
            }
            cout << ans << '\n';
            for (int i = 0; i < ans; i++)
            {
                int cnt = 0;
                for (int j = 0; j < ans; j++)
                {
                    cout << g[i][j];
                    if (g[i][j]) cnt++;
                }
                cout << '\n';
            }
            break;
        }
    }
}