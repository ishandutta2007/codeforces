#include <bits/stdc++.h>

using namespace std;

int N, M, D;
vector<int> graph[200005];
int par[200005];
vector<pair<int, int>> ans;
int tkn[200005];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> D;
    for(int i = 1; i<=N; i++){
        par[i] = i;
    }
    for(int i = 1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int cnt = N-1;
    for(int i = N; i>1; i--){
        for(int n : graph[i]){
            if(n > i && i != getrt(n)){
                cnt--;
                par[getrt(n)] = i;
            }
        }
    }
    if(cnt <= D && D <= graph[1].size()){
        cout << "YES" << "\n";
        for(int i = 2; i<=N; i++){
            if(getrt(i) == i){
                tkn[i] = 1;
            }
        }
        for(int n : graph[1]){
            if(tkn[getrt(n)] == 1){
                ans.push_back({n, 1});
                D--;
                tkn[getrt(n)] = -1;
                tkn[n] = 2;
            }
        }
        for(int i = 1; i<=N; i++){
            par[i] = i;
            if(tkn[i] == 2){
                par[i] = 1;
            }
        }
        for(int n : graph[1]){
            if(getrt(n) != 1 && D){
                D--;
                ans.push_back({n, 1});
                par[getrt(n)] = 1;
            }
        }
        for(int n = 2; n<=N; n++){
            for(int e : graph[n]){
                if(e != 1 && getrt(e) != getrt(n)){
                    ans.push_back({n, e});
                    par[getrt(e)] = getrt(n);
                }
            }
        }
        for(auto p : ans){
            cout << p.first << " " << p.second << "\n";
        }
    }
    else{
        cout << "NO" << "\n";
    }
}