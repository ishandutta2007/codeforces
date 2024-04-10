#include <bits/stdc++.h>

using namespace std;

int N;
int sz[100005], dist[100005], temp[100005], another[100005];
vector<int> graph[100005];

void dfs(int n, int p){
    sz[n] = 1;
    for(int e : graph[n]){
        if(e != p){
            dist[e] = dist[n] + 1;
            dfs(e, n);
            sz[n] += sz[e];
        }
    }
}

bool chk(int n){
    dist[n] = 0;
    dfs(n, 0);
    fill(sz, sz+1+N, -1);
    for(int i =1 ; i<=N; i++){
        if(sz[dist[i]] == -1){
            sz[dist[i]] = (int) (graph[i].size());
        }
        else if(sz[dist[i]] != (int) (graph[i].size())){
            return 0;
        }
    }
    return 1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i =1 ; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    int d1 = 1, d2 = 0, c = 0;
    for(int i = 1; i<=N; i++){
        d1 = (dist[i] > dist[d1] ? i : d1);
    }
    int p = 0;
    c = 1;
    while(true){
        int hvy = 0;
        for(int e : graph[c]){
            if(e != p){
                hvy = (sz[hvy] < sz[e] ? e : hvy);
            }
        }
        if(2*sz[hvy] > N){
            p = c;
            c = hvy;
        }
        else{
            break;
        }
    }
    if(chk(c)){
        cout << c << endl;
        return 0;
    }
    if(chk(d1)){
        cout << d1 << endl;
        return 0;
    }
    dist[d1] = 0;
    dfs(d1, 0);
    for(int i = 1; i<=N; i++){
        d2 = (dist[d2] < dist[i] ? i : d2);
        temp[i] = dist[i];
    }
    if(chk(d2)){
        cout << d2 << endl;
        return 0;
    }
    for(int i = 1; i<=N; i++){
        another[i] = dist[i];
    }
    dist[0] = INT_MAX;
    for(int i = 1; i<=N; i++){
        if(temp[i] == dist[i] && dist[d1]/2 == dist[i]){
            dfs(i, 0);
            int k = 0;
            for(int j= 1 ;j<=N; j++){
                if((graph[j].size() == 1 && dist[j] < dist[k]) && another[j] == temp[j]){
                    k = j;
                }
            }
            if(!k){
                continue;
            }
            if(chk(k)){
                cout << k << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}