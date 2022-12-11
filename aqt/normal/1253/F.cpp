#include <bits/stdc++.h>

using namespace std;

int N, M, K, Q;
vector<pair<int, long long>> graph[100005], cgraph[100005];
long long dist[100005];
int typ[100005], par[100005], dep[100005];
priority_queue<pair<long long, int>,
vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
pair<long long, pair<int, int>> edge[600005];
int tbl[20][100005];
long long mx[20][100005];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

void dfs(int n){
    for(auto e : cgraph[n]){
        if(e.first != tbl[0][n]){
            tbl[0][e.first] = n;
            mx[0][e.first] = e.second;
            dep[e.first] = dep[n] + 1;
            dfs(e.first);
        }
    }
}

long long query(int x, int y){
    if(dep[x] < dep[y]){
        swap(x, y);
    }
    long long ret = 0;
    for(int d = 19; d>=0; d--){
        if(dep[tbl[d][x]] >= dep[y]){
            ret = max(mx[d][x], ret);
            x = tbl[d][x];
        }
    }
    if(x == y){
        return ret;
    }
    for(int d = 19; d>=0; d--){
        if(tbl[d][x] != tbl[d][y]){
            ret = max(ret, max(mx[d][x], mx[d][y]));
            x = tbl[d][x];
            y = tbl[d][y];
        }
    }
    ret = max(ret, max(mx[0][x], mx[0][y]));
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K >> Q;
    for(int i = 1; i<=M; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    fill(dist+K+1, dist+1+N, LLONG_MAX>>1);
    for(int k = 1; k<=K; k++){
        pq.push({0, k});
        typ[k] = k;
        par[k] = k;
    }
    while(pq.size()){
        auto p = pq.top();
        pq.pop();
        if(dist[p.second] != p.first){
            continue;
        }
        int n = p.second;
        for(auto e : graph[n]){
            if(dist[e.first] > e.second + dist[n]){
                dist[e.first] = dist[n] + e.second;
                typ[e.first] = typ[n];
                pq.push({dist[e.first], e.first});
            }
        }
    }
    M = 0;
    for(int n = 1; n<=N; n++){
        for(auto e : graph[n]){
            if(typ[n] != typ[e.first]){
                edge[++M] = {dist[n] + dist[e.first] + e.second, {typ[n], typ[e.first]}};
            }
        }
    }
    sort(edge+1, edge+1+M);
    for(int m = 1; m<=M; m++){
        if(getrt(edge[m].second.second) != getrt(edge[m].second.first)){
            int a = edge[m].second.second, b = edge[m].second.first;
            long long w = edge[m].first;
            cgraph[a].push_back({b, w});
            cgraph[b].push_back({a, w});
            par[getrt(a)] = getrt(b);
        }
    }
    //assert(N != 100);
    dfs(1);
    N = K;
    for(int d = 1; d<20; d++){
        for(int n = 1; n<=N; n++){
            tbl[d][n] = tbl[d-1][tbl[d-1][n]];
            mx[d][n] = max(mx[d-1][n], mx[d-1][tbl[d-1][n]]);
        }
    }
    while(Q--){
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << "\n";
    }
}