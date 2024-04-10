#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011
#define mod 1000000007
#define base 31

int n, i, x, y;
vector<int> list[maxN];
ll dp[maxN];
vector<ll> sol;

int cnt;
map< vector<int>, int > M;


ll compute(int node, int deny) {
    static ll ans;
    static vector<int> aux;

    aux.clear();

    for (auto to : list[node])
        if (deny != to)
            aux.pb(dp[to]);

    sort(aux.begin(), aux.end());
    reverse(aux.begin(), aux.end());

    if (M[aux] == 0) M[aux] = ++cnt;

    return M[aux];
}

void dfs(int node, int root) {

    for (auto to : list[node])
        if (to != root)
            dfs(to, node);

    dp[node] = compute(node, root);
}

void solve(int node, int root) {
    if (list[node].size() < 4)
        sol.pb(compute(node, 0));

    for (auto to : list[node]) {
        if (to == root) continue;
        dp[node] = compute(node, to);
        solve(to, node);
    }

    dp[node] = compute(node, root);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    dfs(1, 0);
    solve(1, 0);

    sort(sol.begin(), sol.end());
    sol.resize(unique(sol.begin(), sol.end()) - sol.begin());

    printf("%d\n", sol.size());

    return 0;
}