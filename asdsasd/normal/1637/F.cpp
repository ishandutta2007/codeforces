#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
long long H[N];
pair<long long, long long> dfs(int pos, int bpos, vector<vector<int>> &edges){
    long long tot = 0;
    long long mx1 = 0;
    long long mx2 = 0;
    for(auto npos:edges[pos]){
        if(npos == bpos) continue;
        auto tmp = dfs(npos, pos, edges);
        tot += tmp.first;
        if(tmp.second > mx2){
            mx2 = tmp.second;
            if(mx2 > mx1){
                swap(mx1, mx2);
            }
        }
    }
    if(bpos != -1){
        tot += max(0LL, H[pos] - mx1);
        mx1 = max(mx1, H[pos]);
    }
    else{
        tot += max(0LL, H[pos] - mx1) + max(0LL, H[pos] - mx2);
    }
    
    
    return {tot, mx1};
}

int main(void){
    int n;
    cin >> n;
    int root = -1;
    long long mx = -1;
    for(int i = 0; i < n; i++){
        cin >> H[i];
        if(H[i] > mx){
            mx = H[i];
            root = i;
        }
    }
    vector<vector<int>> edges(n, vector<int>());
    int u, v;
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cout << dfs(root, -1, edges).first << "\n";
    
}