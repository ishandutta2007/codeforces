#include <bits/stdc++.h>

using namespace std;

struct obj{
    int n;
    long long v, id;
    bool operator < (obj o) const{
        return v > o.v;
    }
};

int N, M, K;
vector<obj> graph[300005];
priority_queue<obj> pq;
long long dist[300005], par[300005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int i = 1; i<=M; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w, i});
        graph[b].push_back({a, w, i});
    }
    K = min(K, N-1);
    fill(dist, dist+N+1, LLONG_MAX);
    dist[1] = 0;
    pq.push({1, 0, 0});
    int cnt = 0;
    cout << K << "\n";
    while(pq.size() && cnt <= K){
        if(pq.top().v != dist[pq.top().n]){
            pq.pop();
            continue;
        }
        int n = pq.top().n;
        pq.pop();
        if(par[n]){
            cout << par[n] << " ";
        }
        cnt++;
        for(auto e : graph[n]){
            if(dist[e.n] > dist[n] + e.v){
                dist[e.n] = dist[n] + e.v;
                par[e.n] = e.id;
                pq.push({e.n, dist[e.n], 0});
            }
        }
    }
}