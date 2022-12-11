#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, lft, rht;
};

int N, Q, S;
Node seg[1000005];
vector<pair<int, int>> graph[1000005];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
long long dist[1000005];

void build1(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    for(int i = l; i<=r; i++){
        graph[i].push_back({idx, 0});
    }
    if(l == r){
        return;
    }
    int mid = l+r>>1;
    seg[idx].lft = ++N;
    build1(l, mid, N);
    seg[idx].rht = ++N;
    build1(mid+1, r, N);
}

void build2(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    for(int i = l; i<=r; i++){
        graph[idx].push_back({i, 0});
    }
    if(l == r){
        return;
    }
    int mid = l+r>>1;
    seg[idx].lft = ++N;
    build2(l, mid, N);
    seg[idx].rht = ++N;
    build2(mid+1, r, N);
}

void upd(int l, int r, int v, int w, int t, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        if(t){
            graph[idx].push_back({v, w});
        }
        else{
            graph[v].push_back({idx, w});
        }
        return;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        upd(l, r, v, w, t, seg[idx].lft);
    }
    else if(l > mid){
        upd(l, r, v, w, t, seg[idx].rht);
    }
    else{
        upd(l, mid, v, w, t, seg[idx].lft);
        upd(mid+1, r, v, w, t, seg[idx].rht);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q >> S;
    int K= N;
    int rt1 = ++N;
    build1(1, N, rt1);
    int rt2 = ++N;
    build2(1, N, rt2);
    while(Q--){
        int c;
        cin >> c;
        if(c == 1){
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
        }
        else if(c == 2){
            int n, l, r, w;
            cin >> n >> l >> r >> w;
            upd(l, r, n, w, 0, rt2);
        }
        else{
            int n, l, r, w;
            cin >> n >> l >> r >> w;
            upd(l, r, n, w, 1, rt1);
        }
    }
    fill(dist, dist+1+N, LLONG_MAX);
    dist[S] = 0;
    pq.push({0LL, S});
    while(pq.size()){
        auto p = pq.top();
        pq.pop();
        if(p.first != dist[p.second]){
            continue;
        }
        int n = p.second;
        for(auto e : graph[n]){
            if(dist[e.first] > dist[n] + e.second){
                dist[e.first] = dist[n] + e.second;
                pq.push({dist[e.first], e.first});
            }
        }
    }
    for(int i = 1; i<=K; i++){
        if(dist[i] == LLONG_MAX){
            cout << -1 << " ";
        }
        else{
            cout << dist[i] << " ";
        }
    }
}