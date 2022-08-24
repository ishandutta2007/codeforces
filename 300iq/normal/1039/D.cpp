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
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 1e5 + 7;

vector <int> g[N];
pair <int, int> dp[N];
int m1[N], m2[N];
int par[N];
vector <int> e;

void zhfs(int v, int pr)
{
    par[v] = pr;
    for (int to : g[v])
    {
        if (to != pr)
        {
            zhfs(to, v);
        }
    }
    e.push_back(v);
}

int n;

int f(int k)
{
    for (int i = 0; i < n; i++) dp[i].first = dp[i].second = m1[i] = m2[i] = 0;
    for (int t : e)
    {
        if (m1[t] + m2[t] + 1 >= k)
        {
            dp[t].first = m1[t] + m2[t] + 1;
        }
        else
        {
            dp[t].first = m1[t] + 1;
        }
        if (dp[t].first >= k)
        {
            dp[t].first = 0;
            dp[t].second++;
        }
        if (par[t] != -1)
        {
            dp[par[t]].second += dp[t].second;
            int len = dp[t].first;
            if (len > m1[par[t]]) swap(len, m1[par[t]]);
            if (len > m2[par[t]]) swap(len, m2[par[t]]);
        }
    }
    return dp[0].second;
}

int ans[N];

void rec(int l, int r, int opt_l, int opt_r)
{
    if (l > r)
    {
        return;
    }
    if (opt_l == opt_r)
    {
        for (int i = l; i <= r; i++)
        {
            ans[i] = opt_l;
        }
        return;
    }
    int m = (l + r) / 2;
    int opt_m = f(m);
    ans[m] = opt_m;
    rec(l, m - 1, opt_m, opt_r);
    rec(m + 1, r, opt_l, opt_m);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    n = 100000;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a = i, b = i + 1;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    zhfs(0, -1);
    rec(1, n, 0, n);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
}