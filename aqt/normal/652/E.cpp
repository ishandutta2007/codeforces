#include <bits/stdc++.h>

using namespace std;

int N, M, a, b, v;
vector<pair<int, int>> graph[300005], cgraph[300005];
bool bri[300005], hasart[300005], chasart[300005], ok[300005];
int low[300005], dfn[300005], t = 0;
int par[300005];

void dfs1(int n, int p){
    dfn[n] = low[n] = ++t;
    for(auto e : graph[n]){
        if(!low[e.first]){
            dfs1(e.first, n);
            low[n] = min(low[n], low[e.first]);
            if(low[e.first] > dfn[n]){
                bri[e.second] = 1;
            }
        }
        else if(e.first != p){
            low[n] = min(low[n], dfn[e.first]);
        }
    }
}

void dfs2(int n, int t){
    par[n] = t;
    dfn[n] = 1;
    for(auto e : graph[n]){
        if(!dfn[e.first] && !bri[e.second]){
            dfs2(e.first, t);
        }
        if(hasart[e.second] && !bri[e.second]){
            chasart[t] = 1;
        }
    }
}

void dfs3(int n, int p){
    if(chasart[n]){
        ok[n] = 1;
    }
    for(auto e : cgraph[n]){
        if(e.first != p){
            ok[e.first] = ok[n];
            if(hasart[e.second]){
                ok[e.first] = 1;
            }
            dfs3(e.first, n);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=M; i++){
        cin >> a >> b >> v;
        graph[a].push_back({b, i});
        graph[b].push_back({a, i});
        hasart[i] = v;
    }
    dfs1(1, 0);
    fill(dfn, dfn+1+N, 0);
    int cnt = 0;
    for(int i = 1; i<=N; i++){
        if(!dfn[i]){
            dfs2(i, ++cnt);
        }
    }
    for(int i= 1; i<=N; i++){
        for(auto e : graph[i]){
            if(bri[e.second]){
                cgraph[par[i]].push_back({par[e.first], e.second});
            }
        }
    }
    cin >> a;
    dfs3(par[a], 0);
    cin >> b;
    if(ok[par[b]]){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}