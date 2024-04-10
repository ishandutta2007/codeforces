#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 2014

int n;
vector<int> g[M],r[M];
bool u[M], uu[M];

void read(void){
    scanf("%d", &n);
    for (int i = 0, x; i < n; ++i)
    for (int j = 0; j < n; ++j){
        scanf("%d", &x);
        if (x>0)
            g[i].push_back(j),
            r[j].push_back(i);
    }
}

int dfs1(int v){
    int ans = 1;
    u[v] = 1;
    for (auto &to : g[v])
    if (!u[to])
        ans+=dfs1(to);
    return ans;
}

int dfs2(int v){
    int ans = 1;
    uu[v] = 1;
    for (auto &to : r[v])
    if (!uu[to])
        ans += dfs2(to);
    return ans;
}

int main(){
#ifdef HINDI
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    //ios_base::sync_with_stdio(0);
#endif

    read();

    if (dfs1(1) == n && dfs2(1) == n)
        cout << "YES\n";
    else
        cout << "NO\n";
    

    return 0;
}