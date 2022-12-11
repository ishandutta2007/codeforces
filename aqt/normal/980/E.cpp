#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> graph[1000005];
int par[20][1000005];
bool tkn[1000005];
vector<int> ans;

void dfs(int n){
    for(int e : graph[n]){
        if(e != par[0][n]){
            par[0][e] = n;
            dfs(e);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(N);
    tkn[0] = tkn[N] = 1;
    K = N-K-1;
    for(int d = 1; d<20; d++){
        for(int n = 1; n<=N; n++){
            par[d][n] = par[d-1][par[d-1][n]];
        }
    }
    for(int n = N-1; n; n--){
        if(tkn[n]){
            continue;
        }
        int k = n, x = 1;
        for(int d = 19; d>=0; d--){
            if(!tkn[par[d][k]]){
                k = par[d][k];
                x += (1<<d);
            }
        }
        if(x <= K){
            k = n;
            K -= x;
            while(x--){
                tkn[k] = 1;
                k = par[0][k];
            }
        }
        else{
            ans.push_back(n);
        }
    }
    sort(ans.begin(), ans.end());
    for(int n : ans){
        cout << n << " ";
    }
}