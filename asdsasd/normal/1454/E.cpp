#include <bits/stdc++.h>
using namespace std;

bool used[200200];
int loop_pos;
long long ans;

bool loop_find(int pos, int bpos, vector<vector<int>> &edges, set<int> &loop_Vs){
    if(used[pos]){
        loop_pos = pos;
        loop_Vs.insert(pos);
        return true;
    }
    used[pos] = true;
    for(auto npos: edges[pos]){
        if(npos == bpos) continue;
        if(loop_find(npos, pos, edges, loop_Vs)){
            if(loop_pos == -1) return true;
            else if(loop_pos == pos){
                loop_pos = -1;
                return true;
            }
            else{
                loop_Vs.insert(pos);
                return true;
            }
        }
    }
    return false;
}

int ans_dfs(int pos, vector<vector<int>> &edges, set<int> &loop_Vs){
    used[pos] = true;
    int ret = 1;
    for(auto npos: edges[pos]){
        if(used[npos]) continue;
        ret += ans_dfs(npos, edges, loop_Vs);
    }
    if(loop_Vs.count(pos)){
        ans -= (long long)(ret) * (long long)(ret - 1) / 2;
        return 0;
    }
    else{
        return ret;
    }
}

void solve(){
    int n;
    scanf("%d", &n);
    vector<vector<int>> edges(n, vector<int>());
    int x, y;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        x--; y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    loop_pos = -1;
    for(int i = 0; i < n; i++) used[i] = false;
    set<int> loop_Vs;
    loop_find(0, -1, edges, loop_Vs);
    ans = (long long)(n) * (long long)(n - 1);
    for(int i = 0; i < n; i++) used[i] = false;
    int s = -1;
    for(auto V: loop_Vs){
        s = V;
        break;
    }
    ans_dfs(s, edges, loop_Vs);
    cout << ans << "\n";
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}