#include <bits/stdc++.h>

using namespace std;

int N, K, M;
vector<int> graph[500005];
int u[500005], v[500005], w[500005];
int par[500005];
bool tree[500005];
int parg[500005];
bool edge[500005];
int dep[500005];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

void dfs(int n){
    for(int e : graph[n]){
        if(abs(e) != parg[n]){
            parg[abs(e)] = n;
            dep[abs(e)] = dep[n] + 1;
            dfs(abs(e));
            if(e > 0){
                edge[e] = 1;
            }
        }
    }
}

long long clmb(int u, int v, int w){
    long long ret = 0;
    u = getrt(u), v = getrt(v);
    while(u != v){
        if(dep[u] < dep[v]){
            swap(u, v);
        }
        if(edge[u]){
            ret += w;
            K--;
        }
        par[u] = getrt(parg[u]);
        u = getrt(parg[u]);
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K >> M;
    for(int i = 1; i<=N; i++){
        par[i] = i;
    }
    for(int i= 1; i<=K; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        par[getrt(a)] = getrt(b);
    }
    for(int i = 1; i<=M; i++){
        cin >> u[i] >> v[i] >> w[i];
        if(getrt(u[i]) != getrt(v[i])){
            graph[u[i]].push_back(-v[i]);
            graph[v[i]].push_back(-u[i]);
            par[getrt(u[i])] = getrt(v[i]);
            tree[i] = 1;
        }
    }
    for(int i = 1; i<=N; i++){
        par[i] = i;
    }
    dfs(1);
    long long ans = 0;
    for(int i = 1; i<=M; i++){
        if(!tree[i] && getrt(u[i]) != getrt(v[i])){
            ans += clmb(u[i], v[i], w[i]);
        }
    }
    if(K){
        ans = -1;
    }
    cout << ans << endl;
}