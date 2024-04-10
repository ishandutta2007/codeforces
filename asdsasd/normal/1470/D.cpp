#include <bits/stdc++.h>
using namespace std;

bool used[300300];

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> edges(n, vector<int>(0));
    int u, v;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 0; i < n; i++) used[i] = false;
    set<int> ans;
    ans.insert(1);
    deque<int> queue;
    used[0] = true;
    for(auto pos:edges[0]){
        queue.push_back(pos);
        used[pos] = true;
    }
    while(!queue.empty()){
        int pos = queue[0];
        queue.pop_front();
        bool flg = false;
        for(auto npos:edges[pos]){
            if(ans.count(npos + 1) >= 1){
                flg = true;
                break;
            }
        }
        if(!flg) ans.insert(pos + 1);
        for(auto npos:edges[pos]){
            if(used[npos]) continue;
            used[npos] = true;
            queue.push_back(npos);
        }
    }
    for(int i = 0; i < n; i++){
        if(!used[i]){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    printf("%d\n", ans.size());
    for(auto p:ans) printf("%d ", p);
    printf("\n");
    
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}