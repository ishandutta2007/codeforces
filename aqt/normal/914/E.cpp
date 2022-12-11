#include <bits/stdc++.h>

using namespace std;

int N;
int typ[200005];
vector<int> graph[200005];
long long ans[200005];
bool vis[200005];
int par[200005];
long long dp[200005];
int sz[200005];
int dist[200005];
int fre[1<<20], totfre[1<<20];
vector<int> sub, tot;

void dfs1(int n){
    dp[n] = 0;
    sz[n] = 1;
    for(int e : graph[n]){
        if(!vis[e] && e != par[n]){
            par[e] = n;
            dfs1(e);
            sz[n] += sz[e];
        }
    }
}

void dfs2(int n){
    dp[n] = 0;
    sub.push_back(n);
    tot.push_back(n);
    fre[dist[n]]++;
    totfre[dist[n]]++;
    for(int e : graph[n]){
        if(!vis[e] && e != par[n]){
            par[e] = n;
            dist[e] = dist[n] ^ typ[e];
            dfs2(e);
        }
    }
}

void dfs3(int n){
    for(int e : graph[n]){
        if(!vis[e] && e != par[n]){
            dfs3(e);
            dp[n] += dp[e];
        }
    }
    //cout << n << " " << dp[n] << endl;
    ans[n] += dp[n];
}

int getcent(int n){
    par[n] = 0;
    dfs1(n);
    int siz = sz[n];
    while(true){
        int hvy = 0;
        for(int e : graph[n]){
            if(e != par[n] && !vis[e]){
                hvy = (sz[hvy] > sz[e] ? hvy : e);
            }
        }
        if(2*sz[hvy] <= siz){
            break;
        }
        else{
            n = hvy;
        }
    }
    return n;
}

void solve(int n){
    n = getcent(n);
    //cout << n << endl;
    tot.push_back(n);
    dist[n] = typ[n];
    totfre[dist[n]]++;
    par[n] = 0;
    vis[n] = 1;
    for(int e : graph[n]){
        if(!vis[e]){
            dist[e] = typ[e] ^ dist[n];
            par[e] = 0;
            dfs2(e);
            for(int k : sub){
                dp[k] -= fre[dist[k] ^ dist[n]];
                for(int p = 0; p<20; p++){
                    dp[k] -= fre[dist[k]^dist[n]^(1<<p)];
                }
                //cout << "sub: " << k << " " << dp[k] << endl;
            }
            for(int k : sub){
                fre[dist[k]] = 0;
            }
            sub.clear();
        }
    }
    for(int k : tot){
        dp[k] += totfre[dist[k]^dist[n]];
        for(int p = 0; p<20; p++){
            dp[k] += totfre[dist[k]^dist[n]^(1<<p)];
        }
        //cout << "tot: " << k << " " << dp[k] << endl;
    }
    dfs3(n);
    ans[n] -= dp[n];
    dp[n]--;
    dp[n] /= 2;
    dp[n]++;
    ans[n] += dp[n];
    for(int k : tot){
        totfre[dist[k]] = 0;
        //cout << k << " " << ans[k] << " " << dist[k] << endl;
    }
    tot.clear();
    for(int e : graph[n]){
        if(!vis[e]){
            solve(e);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i<=N; i++){
        char c;
        cin >> c;
        typ[i] = c-'a';
        typ[i] = 1<<typ[i];
        //cout << "typ: " << typ[i] << endl;
    }
    solve(1);
    for(int i = 1; i<=N; i++){
        cout << ans[i] << " ";
    }
}