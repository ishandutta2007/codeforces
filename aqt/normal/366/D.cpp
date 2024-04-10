#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> vec;
vector<pair<int, pair<int, int>>> graph[1005];
priority_queue<pair<int, int>> pq;
int dist[1005];

int main(){
    cin>> N >> M;
    for(int i = 1; i<=M; i++){
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        graph[u].push_back({v, {l, r}});
        graph[v].push_back({u, {l, r}});
        vec.push_back(l);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int ans = 0;
    for(int x : vec){
        fill(dist, dist+N+1, 0);
        dist[1] = INT_MAX;
        pq.push({INT_MAX, 1});
        while(pq.size()){
            if(pq.top().first != dist[pq.top().second]){
                pq.pop();
                continue;
            }
            int n = pq.top().second;
            pq.pop();
            for(auto e : graph[n]){
                if(e.second.first <= x && dist[e.first] < min(e.second.second, dist[n])){
                    dist[e.first] = min(e.second.second, dist[n]);
                    pq.push({dist[e.first], e.first});
                }
            }
        }
        ans = max(ans, dist[N]-x+1);
    }
    if(ans){
        cout << ans << endl;
    }
    else{
        cout << "Nice work, Dima!" << endl;
    }
}