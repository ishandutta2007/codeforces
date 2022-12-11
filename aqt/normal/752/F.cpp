#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> graph[200005];
bool tkn[200005];
int sz[200005];
vector<int> v;

void dfs(int n, int p){
    if(tkn[n]){
        sz[n] = 1;
        v.push_back(n);
    }
    for(int e : graph[n]){
        if(e != p){
            dfs(e, n);
            sz[n] += sz[e];
        }
    }
}

int main(){
    cin >> N >> K;
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i<=2*K; i++){
        int n;
        cin >> n;
        tkn[n] = 1;
    }
    dfs(1, 0);
    int crnt = 1, p = 0;
    bool b = 1;
    while(b){
        b = 0;
        for(int e : graph[crnt]){
            if(e != p){
                if(sz[e] > K){
                    b = 1;
                    p = crnt;
                    crnt = e;
                    break;
                }
            }
        }
    }
    v.clear();
    dfs(crnt, 0);
    cout << 1 << "\n";
    cout << crnt << "\n";
    for(int i = 0; i<K; i++){
        cout << v[i] << " " << v[i+K] << " " << crnt << "\n";
    }
}