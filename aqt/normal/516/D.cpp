#include <bits/stdc++.h>

using namespace std;

int N, Q;
vector<pair<int, int>> graph[100005];
int par[20][100005];
long long dist[2][100005];
long long val[100005];
int cnt[100005];

void dfs1(int n, int t, int p){
    for(auto e : graph[n]){
        if(e.first != p){
            dist[t][e.first] = dist[t][n] + e.second;
            dfs1(e.first, t, n);
        }
    }
}

void dfs2(int n){
    for(auto e : graph[n]){
        if(e.first != par[0][n]){
            par[0][e.first] = n;
            dfs2(e.first);
        }
    }
}

void dfs3(int n){
    for(auto e : graph[n]){
        if(e.first != par[0][n]){
            dfs3(e.first);
            cnt[n] += cnt[e.first];
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i<N; i++){
        int a, b, v;
        cin >> a >> b >> v;
        graph[a].push_back({b, v});
        graph[b].push_back({a, v});
    }
    dfs1(1, 0, 0);
    int d1 = max_element(dist[0]+1, dist[0]+1+N) - dist[0];
    fill(dist[0]+1, dist[0]+1+N, 0);
    dist[0][d1] = 0;
    dfs1(d1, 0, 0);
    int d2 = max_element(dist[0]+1, dist[0]+1+N) - dist[0];
    dfs1(d2, 1, 0);
    for(int i = 1; i<=N; i++){
        val[i] = max(dist[0][i], dist[1][i]);
    }
    int rt = min_element(val+1, val+1+N) - val;
    //cout << rt << endl;
    dfs2(rt);
    for(int d = 1; d<20; d++){
        for(int n = 1; n<=N; n++){
            par[d][n] = par[d-1][par[d-1][n]];
        }
    }
    cin >> Q;
    while(Q--){
        long long q;
        cin >> q;
        fill(cnt+1, cnt+1+N, 1);
        for(int n = 1; n<=N; n++){
            int t = n;
            for(int d = 19; d>=0; d--){
                if(val[par[d][t]] + q >= val[n]){
                    t = par[d][t];
                }
            }
            //cout << n << " " << par[0][t] << "\n";
            cnt[par[0][t]]--;
        }
        dfs3(rt);
        cout << *max_element(cnt+1, cnt+1+N) << "\n";
    }
}