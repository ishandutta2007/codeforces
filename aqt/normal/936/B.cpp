#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[100005];
bool vis[3][100005];
bool stk[100005];
pair<int, int> par[2][100005];
bool endstate[100005];

void dfs(int n, int p){
    vis[p][n] = 1;
    for(int e : graph[n]){
        if(!vis[p^1][e]){
            par[p^1][e] = {p, n};
            dfs(e, p^1);
        }
    }
}

bool iscyclic(int n){
    stk[n] = 1;
    for(int e : graph[n]){
        if(stk[e] || (!vis[2][e] && iscyclic(e))){
            return 1;
        }
    }
    stk[n] = 0;
    vis[2][n] = 1;
    return 0;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i =1; i<=N; i++){
        int k;
        cin >> k;
        if(!k){
            endstate[i] = 1;
        }
        for(int j = 0; j<k; j++){
            int n;
            cin >> n;
            graph[i].push_back(n);
        }
    }
    int S;
    cin >> S;
    dfs(S, 0);
    for(int i = 1; i<=N; i++){
        if(endstate[i] && vis[1][i]){
            cout << "Win" << "\n";
            int n = i, p = 1;
            stack<int> stk;
            while(n){
                stk.push(n);
                n = par[p][n].second;
                p ^= 1;
            }
            while(stk.size()){
                cout << stk.top() << " ";
                stk.pop();
            }
            return 0;
        }
    }
    if(iscyclic(S)){
        cout << "Draw" << "\n";
    }
    else{
        cout << "Lose" << endl;
    }
}