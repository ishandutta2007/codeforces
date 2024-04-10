#include <bits/stdc++.h>

using namespace std;

vector < int > answ[200005];
int use[200005];

void dfs(int v){
    use[v] = 1;
    cout << v << " ";
    int p = answ[v][0], h = answ[v][1];
    for (auto u : answ[v]){
        if (use[u] == 1) continue;
        if ((u == p && (answ[u][0] == h || answ[u][1] == h)) || (u == h && (answ[u][0]== p || answ[u][1] == p))) dfs(u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x >> y;
        answ[i] = {min(x, y), max(x, y)};
    }
    dfs(1);
    return 0;
}