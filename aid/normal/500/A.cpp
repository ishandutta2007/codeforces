#include <iostream>

using namespace std;

const int MAXN = 30 * 1000 + 5;
int g[MAXN];
char used[MAXN];

void dfs(int v) {
    used[v] = true;
    if(g[v] != -1 && !used[v + g[v]])
        dfs(v + g[v]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    t--;
    for(int i = 0; i < n - 1; i++)
        cin >> g[i];
    g[n - 1] = -1;
    dfs(0);
    cout << (used[t]? "YES" : "NO") << '\n';
    return 0;
}