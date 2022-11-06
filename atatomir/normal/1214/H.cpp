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

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
    cerr << "[";
    for (auto e : aux) cerr << e << ' ';
    cerr << "]";
    return cerr;
}

const int maxN = 200011;

int n, k, x, y;
vector<int> adj[maxN];
int depth[maxN], down[maxN], from[maxN], color[maxN];
int best;
vector<int> path;

void dfs(int node, int dad) {
    if (depth[best] < depth[node])
        best = node;

    for (auto to: adj[node]) {
        if (to != dad) {
            from[to] = node;
            depth[to] = depth[node] + 1;
            dfs(to, node);
        }
    }
}

void no_solution() {
    if (k == 2) return;
    printf("No");
    exit(0);
}

void dfs_color(int node, int dir) {
    down[node] = 0;
    for (auto to: adj[node]) {
        if (color[to] != -1) continue;
        color[to] = (color[node] + dir) % k;
        dfs_color(to, dir);

        if (down[node] >= 1 && down[node] + down[to] + 2 >= k)
            no_solution();
        down[node] = max(down[node], down[to] + 1);
    }
}



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        adj[x].pb(y);
        adj[y].pb(x);
    }

    best = 1;
    dfs(1, 0);

    depth[best] = 0;
    from[best] = 0;
    dfs(best, 0);

    while (best) {
        path.pb(best);
        best = from[best];
    }

    for (int i = 1; i <= n; i++) color[i] = -1;
    for (int i = 0; i < path.size(); i++)
        color[path[i]] = i % k;

    int mid = path.size() >> 1;
    for (int i = 0; i < mid; i++) { 
        dfs_color(path[i], k - 1);
        
        if (down[path[i]] > 0 && i + 1 + down[path[i]] >= k)
            no_solution();
    }
    
    for (int i = mid; i < path.size(); i++) { 
        dfs_color(path[i], 1);

        if (down[path[i]] > 0 && path.size() - i + down[path[i]] >= k)
            no_solution();
    }

    printf("Yes\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", color[i] + 1);

    return 0;
}