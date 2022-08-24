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
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 300000 + 7;

vector <int> g[N];
int c[N];

void dfs(int v)
{
    c[v] = 1;
    for (int to : g[v])
    {
        if (c[to] == 0)
        {
            dfs(to);
        }
        else if (c[to] == 1)
        {
            cout << -1 << '\n';
            exit(0);
        }
    }
    c[v] = 2;
}
            
vector <int> t;

void tsort(int v)
{
    c[v] = 1;
    for (int to : g[v])
    {
        if (c[to] == 0)
        {
            tsort(to);
        }
    }
    t.push_back(v);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }
    for (int i = 0; i < n; i++)
    {
        if (c[i] == 0) dfs(i);
    }
    for (int i = 0; i < n; i++) c[i] = 0;
    for (int i = 0; i < n; i++) if (c[i] == 0) tsort(i);
    reverse(t.begin(), t.end());
    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        vector <int> dp(n);
        for (int i : t)
        {
            dp[i] += (s[i] == c);
            for (int to : g[i])
            {
                dp[to] = max(dp[to], dp[i]);
            }
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << '\n';
}