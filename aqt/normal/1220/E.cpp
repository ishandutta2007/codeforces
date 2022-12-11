#include <bits/stdc++.h>

using namespace std;

int N, M, S;
vector<int> graph[200005];
bool good[200005];
long long val[200005];
long long tot, ans, mx;
bool vis[200005];

void dfs1(int n, int p){
    vis[n] = 1;
    for(int e : graph[n]){
        if(!vis[e]){
            dfs1(e, n);
            if(good[e]){
                good[n] = 1;
            }
        }
        else if(e != p){
            good[n] = 1;
        }
    }
}

void dfs2(int n, int p){
    vis[n] = 1;
    for(int e : graph[n]){
        if(e != p && !vis[e]){
            val[e] += val[n];
            dfs2(e, n);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        cin >> val[i];
    }
    for(int i = 1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin >> S;
    dfs1(S, 0);
    for(int i = 1; i<=N; i++){
        if(good[i]){
            tot += val[i];
            val[i] = 0;
        }
    }
    fill(vis+1, vis+1+N, 0);
    dfs2(S, 0);
    for(int i = 1; i<=N; i++){
        ans = max(ans, tot+val[i]);
    }
    cout << ans << endl;
}