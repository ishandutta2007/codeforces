#include <bits/stdc++.h>

using namespace std;

int N, M, S, T;
vector<pair<int, int>> graph[2][100005];
long long dist[2][100005];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
bool def[100005];
pair<pair<int, int>, int> edge[100005];

void dijkstra(int s, int t){
    for(int i = 1; i<=N; i++){
        dist[t][i] = LLONG_MAX/3;
    }
    dist[t][s] = 0;
    pq.push({0, s});
    while(pq.size()){
        auto p = pq.top();
        pq.pop();
        if(p.first != dist[t][p.second]){
            continue;
        }
        int n = p.second;
        for(auto e : graph[t][n]){
            if(dist[t][e.first] > dist[t][n] + e.second){
                dist[t][e.first] = dist[t][n] + e.second;
                pq.push({dist[t][e.first], e.first});
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> S >> T;
    for(int i = 1; i<=M; i++){
        int a, b, w;
        cin >> a >>b >> w;
        graph[0][a].push_back({b, w});
        graph[1][b].push_back({a, w});
        edge[i].first.first = a;
        edge[i].first.second = b;
        edge[i].second = w;
    }
    dijkstra(S, 0);
    dijkstra(T, 1);
    long long len = dist[0][T];
    for(int i = 1; i<=M; i++){
        int a = edge[i].first.first, b = edge[i].first.second, w = edge[i].second;
        if(w + dist[0][a] + dist[1][b] == len){
            def[i] = 1;
            pq.push({dist[0][a], i});
        }
    }
    int cnt = 0;
    while(pq.size()){
        auto p = pq.top();
        pq.pop();
        if(p.second < 0){
            cnt--;
        }
        else{
            if(cnt || (pq.size() && pq.top().first == p.first)){
                def[p.second] = 0;
            }
            pq.push({dist[0][edge[p.second].first.second], -p.second});
            cnt++;
        }
    }
    for(int i = 1; i<=M; i++){
        int a = edge[i].first.first, b = edge[i].first.second, w = edge[i].second;
        if(def[i]){
            cout << "YES" << "\n";
        }
        else {
            if(len-dist[0][a]-dist[1][b]-1 <= w && len-dist[0][a]-dist[1][b]-1 > 0){
                cout << "CAN " << w-(len-dist[0][a]-dist[1][b]-1) << "\n";
            }
            else{
                cout << "NO" << "\n";
            }
        }
    }
}