#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> graph[200005];
int dist[200005], sz[200005];
bool tkn[200005];

void dfs1(int n, int p){
    if(tkn[n]){
        sz[n] = 1;
    }
    for(int e : graph[n]){
        if(e != p){
            dfs1(e, n);
            sz[n] += sz[e];
        }
    }
}

void dfs2(int n, int p){
    for(int e : graph[n]){
        if(e != p){
            dist[e] = dist[n] + 1;
            dfs2(e, n);
        }
    }
}

int main(){
    cin >> N >> K;
    for(int i =1 ; i<=2*K; i++){
        int n;
        cin >> n;
        tkn[n] = 1;
    }
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs1(1, 0);
    int rt =1, p = 0;
    while(true){
        int hvy = 0;
        for(int e : graph[rt]){
            if(e != p){
                hvy = sz[hvy] < sz[e] ? e : hvy;
            }
        }
        if(K < sz[hvy]){
            p = rt;
            rt = hvy;
        }
        else{
            break;
        }
    }
    dfs2(rt, 0);
    long long ans = 0;
    for(int i =1 ; i<=N; i++){
        if(tkn[i]){
            ans += dist[i];
        }
    }
    cout << ans << endl;
}