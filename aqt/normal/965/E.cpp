#include <bits/stdc++.h>

using namespace std;

int N;
int adj[26][100005];
bool tkn[100005];
int dep[100005];
string s;
priority_queue<int> pq[100005];

void dfs(int n){
    if(tkn[n]){
        pq[n].push(dep[n]);
    }
    for(int k = 0; k<26; k++){
        if(adj[k][n]){
            dfs(adj[k][n]);
            if(pq[n].size() < pq[adj[k][n]].size()){
                swap(pq[n], pq[adj[k][n]]);
            }
            while(pq[adj[k][n]].size()){
                pq[n].push(pq[adj[k][n]].top());
                pq[adj[k][n]].pop();
            }
        }
    }
    if(!tkn[n]){
        pq[n].pop();
        pq[n].push(dep[n]);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    tkn[0] = 1;
    int idx = 0;
    for(int i =1 ; i<=N; i++){
        cin >> s;
        int crnt = 0;
        for(int c : s){
            if(!adj[c-'a'][crnt]){
                adj[c-'a'][crnt] = ++idx;
                dep[idx] = dep[crnt] + 1;
            }
            crnt = adj[c-'a'][crnt];
        }
        tkn[crnt] = 1;
    }
    dfs(0);
    int ans = 0;
    while(pq[0].size()){
        ans += pq[0].top();
        pq[0].pop();
    }
    cout << ans << endl;
}