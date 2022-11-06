#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>


using namespace std;


#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011
#define inf (1LL << 60)

int n, i, x, y;
int v[maxN];
vector< pair<int, int> > list[maxN];
bool bad[maxN];
int ans;

void dfs(int node, ll deep, ll lower) {
    lower = min(lower, deep);
    
    bad[node] = (v[node] < deep - lower);
    for (auto to : list[node])
        dfs(to.first, deep + to.second, lower);
}

void dfs2(int node) {
    if (bad[node]) return;
    
    ans++;
    for (auto to : list[node])
        dfs2(to.first);
}

int main() {
    
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &v[i]);
    for (i = 2; i <= n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(mp(i, y));        
    }
    
    dfs(1, 0, 0);
    dfs2(1);

    printf("%d", n - ans);
    
    return 0;
}