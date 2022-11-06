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

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
    cerr << "[";
    for (auto e : aux) cerr << e << ' ';
    cerr << "]";
    return cerr;
}

const int maxN = 5055;

int n, m, x, y;
vector<int> adj[maxN], inv[maxN];
bool ascending[maxN], used[maxN];
vector<int> order;

void dfs(int node) {
    used[node] = true;
    for (auto to: adj[node]) {
        if (!used[to])
            dfs(to);
    }
    order.pb(node);
}

void need_two() {
    printf("2\n");
    for (int i = 1; i <= m; i++)
        printf("%d ", (ascending[i] ? 1 : 2));

    exit(0);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        ascending[i] = (x < y);
        adj[x].pb(y);
        inv[y].pb(x);
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        dfs(i);
    }

    memset(used, 0, sizeof(used));
    reverse(order.begin(), order.end());
    for (auto node: order) {
        if (used[node]) continue;
        used[node] = true;

        for (auto to: inv[node]) 
            if (!used[to])
                need_two();
    }

    printf("1\n");
    for (int i = 1; i <= m; i++)
        printf("1 ");


    return 0;
}