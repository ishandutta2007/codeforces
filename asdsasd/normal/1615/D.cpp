#include <bits/stdc++.h>
using namespace std;

int pc(int x){
    int ret = 0;
    while(x > 0){
        if(x & 1) ret++;
        x >>= 1;
    }
    return ret;
}

void solve(){
    int n, m, x, y, v;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edges(n, vector<pair<int, int>>());
    vector<vector<pair<int, int>>> edges_bi(n, vector<pair<int, int>>());
    for(int i = 0; i < n - 1; i++){
        cin >> x >> y >> v;
        x--; y--;
        edges[x].push_back({y, v});
        edges[y].push_back({x, v});
        if(v != -1){
            int p = pc(v) % 2;
            edges_bi[x].push_back({y, p});
            edges_bi[y].push_back({x, p});
        }
    }
    for(int i = 0; i < m; i++){
        cin >> x >> y >> v;
        x--; y--;
        edges_bi[x].push_back({y, v});
        edges_bi[y].push_back({x, v});
    }
    
    vector<int> bi(n, -1);
    int pos, npos;
    for(int i = 0; i < n; i++){
        if(bi[i] != -1) continue;
        bi[i] = 0;
        vector<int> stack;
        stack.push_back(i);
        while(!stack.empty()){
            pos = stack.back();
            stack.pop_back();
            for(auto nv: edges_bi[pos]){
                npos = nv.first;
                v = nv.second;
                int nb = bi[pos] ^ v;
                if(bi[npos] == -1){
                    bi[npos] = bi[pos] ^ v;
                    stack.push_back(npos);
                }
                else if(bi[npos] != nb){
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
    
    vector<bool> used(n, false);
    vector<int> stack;
    stack.push_back(0);
    used[0] = true;
    while(!stack.empty()){
        pos = stack.back();
        stack.pop_back();
        for(auto nv: edges[pos]){
            npos = nv.first;
            v = nv.second;
            if(used[npos]) continue;
            used[npos] = true;
            stack.push_back(npos);
            int nb = (bi[pos] ^ bi[npos]);
            if(v != -1) cout << pos + 1 << " " << npos + 1 << " " << v << "\n";
            else cout << pos + 1 << " " << npos + 1 << " " << nb << "\n";
        }
    }
    
    
}

int main(void){
    int t;
    cin >> t;
    while(t--) solve();
    
}