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

const int N = 1e5 + 7;

int ans[N];
int par[N];
bool used[N];
int depth[N];

int n;
vector <int> g[N];

void dfs(int v, int pr)
{
    par[v] = pr;
    for (int to : g[v])
    {
        if (to != pr)
        {
            depth[to] = depth[v] + 1;
            dfs(to, v);
        }
    }
}

void solve_rooted(int v)
{
    depth[v] = 0;
    dfs(v, -1);
    vector <int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
        used[i] =0 ;
    }
    sort(arr.begin(), arr.end(), [] (int a, int b)
    {
        return depth[a] > depth[b];
    });
    vector <int> res;
    for (int x : arr)
    {
        int sum = 0;
        while (!used[x] && x != -1)
        {
            sum++;
            used[x] = true;
            x = par[x];
        }
        res.push_back(sum);
    }
    sort(res.rbegin(), res.rend());
    int sum = 0;
    for (int i = 0; i < (int) res.size(); i++)
    {
        sum += res[i];
        ans[max(2, i + 1)] = max(ans[max(2, i + 1)], sum);
    }
}

int best = -1e9;
int best_v = -1;

void go(int v, int pr, int len)
{
    if (len > best)
    {
        best = len;
        best_v = v;
    }
    for (int to : g[v])
    {
        if (to != pr)
        {
            go(to, v, len + 1);
        }
    }
}

vector <int> pth;
vector <int> cur;

void then(int v, int pr, int len)
{
    cur.push_back(v);
    if (len == best && pth.empty())
    {
        pth = cur;
    }
    for (int to : g[v])
    {
        if (to != pr)
        {
            then(to, v, len + 1);
        }
    }
    cur.pop_back();
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    best = -1e9;
    best_v = -1;
    go(0, -1, 0);
    int my_v = best_v;
    best = -1e9;
    best_v = -1;
    go(my_v, -1, 0);
    then(my_v, -1, 0);
    int ind = (int) pth.size() / 2;
    solve_rooted(pth[ind]);
    ans[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}