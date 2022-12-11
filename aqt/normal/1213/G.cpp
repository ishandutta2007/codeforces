#include <bits/stdc++.h>

using namespace std;

int N, Q;
long long par[200005], sz[200005];
priority_queue<pair<int, pair<int, int>>> pq;
long long out[200005];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for(int i = 1; i<=N; i++){
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 1; i<N; i++){
        int u, v, w;
        cin >> u >> v >> w;
        pq.push({-w, {u, v}});
    }
    long long ans = 0;
    for(int m = 1; m<=200000; m++){
        while(pq.size() && -pq.top().first <= m){
            auto e = pq.top();
            pq.pop();
            int u = e.second.first, v = e.second.second;
            if(getrt(u) != getrt(v)){
                ans += sz[getrt(u)] * sz[getrt(v)];
                sz[getrt(u)] += sz[getrt(v)];
                par[getrt(v)] = getrt(u);
            }
        }
        out[m] = ans;
    }
    while(Q--){
        int n;
        cin >> n;
        cout << out[n] << " ";
    }
}