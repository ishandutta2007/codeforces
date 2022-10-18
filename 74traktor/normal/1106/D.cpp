#include <bits/stdc++.h>

using namespace std;

vector < int > g[100005];
int use[100005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, v, u;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    use[1] = 1;
    set < int > Q;
    cout << 1 << " ";
    for (auto key : g[1]) Q.insert(key);
    while (Q.size() != 0){
        auto p = (*Q.begin());
        Q.erase(p);
        if (use[p] == 1) continue;
        use[p] = 1;
        cout << p << " ";
        for (auto key : g[p]){
            if (use[key] == 0) Q.insert(key);
        }
    }
    return 0;
}