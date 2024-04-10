#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

int n, k, i, x, y, R;
vector<int> list[maxN];
int cnt[maxN];
int team[maxN];
vector<int> ord;

void dfs(int node, int root) {
    bool good = true;

    for (auto to : list[node]) {
        if (to == root) continue;
        dfs(to, node);
        cnt[node] += cnt[to];
        if (cnt[to] > k / 2) good = false;
    }

    if (k - cnt[node] > k / 2) good = false;
    if (good) R = node;
}

void dfs2(int node, int root) {
    if (team[node]) ord.pb(node);
    for (auto to : list[node]) {
        if (to == root) continue;
        dfs2(to, node);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    k *= 2;
    for (i = 1; i <= k; i++) {
        scanf("%d", &x);
        cnt[x] = 1;
        team[x] = i;
    }

    dfs(1, 0);
    dfs2(R, 0);

    printf("%d\n%d\n", 1, R);
    for (i = 0; i < k / 2; i++)
        printf("%d %d %d\n", ord[i], ord[i + (k / 2)], R);


    return 0;
}