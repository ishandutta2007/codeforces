#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[200005];
int dist[200005][2];
queue<int> qu;
int dgr[200005];
vector<pair<int, int>> v;

void dfs(int n, int p, int t){
    for(int e : graph[n]){
        if(e != p){
            dist[e][t] = dist[n][t] + 1;
            dfs(e, n, t);
        }
    }
}

int getidx(int t){
    int idx = 0;
    for(int i =1 ; i<=N; i++){
        idx = (dist[idx][t] < dist[i][t] ? i : idx);
    }
    return idx;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0, 0);
    int d1 = getidx(0);
    dist[d1][0] = 0;
    dfs(d1, 0, 0);
    int d2 = getidx(0);
    dfs(d2, 0, 1);
    for(int n = 1; n<=N; n++){
        dgr[n] = graph[n].size();
        if(graph[n].size() == 1 && n != d1 && n != d2){
            qu.push(n);
            dgr[n]--;
        }
    }
    long long ans = 0;
    while(qu.size()){
        int n = qu.front();
        qu.pop();
        if(dist[n][0] > dist[n][1]){
            ans += dist[n][0];
            v.push_back({d1, n});
        }
        else{
            ans += dist[n][1];
            v.push_back({d2, n});
        }
        for(int e : graph[n]){
            if(dgr[e]){
                dgr[e]--;
                if(dgr[e] == 1){
                    qu.push(e);
                }
            }
        }
    }
    ans += 1LL*dist[d1][1]*(dist[d1][1]+1)/2;
    qu.push(d1);
    while(qu.size()){
        int n = qu.front();
        qu.pop();
        v.push_back({d2, n});
        for(int e : graph[n]){
            if(dgr[e]){
                dgr[e]--;
                if(dgr[e] == 1){
                    qu.push(e);
                }
            }
        }
    }
    cout << ans << "\n";
    for(int i = 0; i<N-1; i++){
        cout << v[i].first << " " << v[i].second << " " << v[i].second << "\n";
    }
}