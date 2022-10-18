#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > Q;
int use[150005];
int ss[150005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, v, u;
    cin >> n;
    for (int i = 1; i <= n - 1; ++i){
        cin >> u >> v;
        if (use[u] == 1 && use[v] == 1){
            if (Q[ss[v]].size() <= Q[ss[u]].size())
            for (auto key : Q[ss[v]]) Q[ss[u]].push_back(key), ss[key] = ss[u];
            else
            for (auto key : Q[ss[u]]) Q[ss[v]].push_back(key), ss[key] = ss[v];
        }
        else if (use[v] == 1){
            Q[ss[v]].push_back(u);
            ss[u] = ss[v];
        }
        else if (use[u] == 1){
            Q[ss[u]].push_back(v);
            ss[v] = ss[u];
        }
        else{
            Q.push_back({u, v});
            ss[u] = Q.size() - 1;
            ss[v] = Q.size() - 1;
        }
        use[u] = 1;
        use[v] = 1;
    }
    for (auto key : Q[ss[1]]) cout << key << " ";
    return 0;
}