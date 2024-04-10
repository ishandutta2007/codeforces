#include <bits/stdc++.h>

using namespace std;

struct edge{
    int u, v;
    long long w;
    bool operator < (edge e) const{
        return w > e.w;
    }
};

int N, M, K;
priority_queue<edge> pq;
vector<edge> graph[100005];
bool sp[100005];
int par[100005];
int typ[100005];
long long dist[100005];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

void dijkstra(){
    while(pq.size()){
        auto p = pq.top();
        pq.pop();
        if(dist[p.v] != p.w){
            continue;
        }
        int n = p.v;
        for(auto e: graph[n]){
            if(dist[e.v] > dist[n] + e.w){
                dist[e.v] = dist[n] + e.w;
                typ[e.v] = typ[n];
                pq.push({0, e.v, dist[e.v]});
            }
        }
    }
}

long long kruskal(){
    long long ret = 0;
    while(pq.size()){
        int u = pq.top().u, v = pq.top().v;
        long long w = pq.top().w;
        pq.pop();
        if(getrt(u) != getrt(v)){
            ret += w;
            par[getrt(u)] = getrt(v);
        }
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({a, b, c});
        graph[b].push_back({b, a, c});
    }
    cin >> K;
    fill(dist, dist+1+N, LLONG_MAX);
    for(int i = 1; i<=K; i++){
        int n;
        cin >> n;
        sp[n] = 1;
        dist[n] = 0;
        typ[n] = n;
        pq.push({0 ,n, 0});
        par[n] = n;
    }
    dijkstra();
    for(int n = 1; n<=N; n++){
        for(auto e : graph[n]){
            if(typ[e.v] != typ[e.u]){
                pq.push({typ[e.v], typ[e.u], dist[e.v] + dist[e.u] + e.w});
            }
        }
    }
    long long ans = kruskal();
    if(!sp[1]){
        fill(dist, dist+1+N, LLONG_MAX);
        dist[1] = 0;
        pq.push({0, 1, 0});
        dijkstra();
        long long mini = LLONG_MAX;
        for(int n = 1; n<=N; n++){
            if(sp[n]){
                mini = min(mini, dist[n]);
            }
        }
        ans += mini;
    }
    cout << ans << endl;
}