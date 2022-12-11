#include <bits/stdc++.h>

using namespace std;

struct edge{
    int u, v;
    long long w;
    bool operator < (edge e) const{
        return w > e.w;
    }
};

int N, M;
int par[200005];
long long arr[200005];
priority_queue<edge> pq;

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int minidx = 1;
    for(int i = 1; i<=N; i++){
        par[i] = i;
        cin >> arr[i];
        if(arr[minidx] > arr[i]){
            minidx = i;
        }
    }
    for(int i =1 ; i<=M; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        pq.push({u, v, w});
    }
    for(int i = 1; i<=N; i++){
        if(i != minidx){
            pq.push({i, minidx, arr[minidx] + arr[i]});
        }
    }
    long long ans= 0;
    while(pq.size()){
        auto e  = pq.top();
        pq.pop();
        if(getrt(e.u) != getrt(e.v)){
            ans += e.w;
            par[getrt(e.u)] = e.v;
        }
    }
    cout << ans << endl;
}