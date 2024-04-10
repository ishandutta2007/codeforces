#include <bits/stdc++.h>

using namespace std;

int N;
int val[200005];
vector<int> graph[200005];
int sz[200005];
bool vis[200005];
int dist[200005];
long long cnt[200005][2];
long long ans[200005];
int par[200005];
vector<int> fact;
vector<int> sub;

void dfs1(int n){
    sz[n] = 1;
    for(int e : graph[n]){
        if(e != par[n] && !vis[e]){
            par[e] = n;
            dfs1(e);
            sz[n] += sz[e];
        }
    }
}

void dfs2(int n, int p){
    dist[n] = __gcd(dist[p], val[n]);
    sub.push_back(dist[n]);
    cnt[dist[n]][1]++;
    for(int e : graph[n]){
        if(e != p && !vis[e]){
            dfs2(e, n);
        }
    }
}

int getcent(int n){
    par[n] = 0;
    dfs1(n);
    int s = sz[n];
    while(true){
        int hvy = 0;
        for(int e : graph[n]){
            if(e != par[n] && !vis[e]){
                hvy = (sz[hvy] < sz[e] ? e : hvy);
            }
        }
        if(sz[hvy]*2 <= s){
            break;
        }
        else{
            n = hvy;
        }
    }
    return n;
}

void f(){
    sort(sub.begin(), sub.end());
    sub.erase(unique(sub.begin(), sub.end()), sub.end());
    sort(fact.begin(), fact.end());
    fact.erase(unique(fact.begin(), fact.end()), fact.end());
    for(int f1 : sub){
        for(int f2 : fact){
            ans[__gcd(f1, f2)] += cnt[f1][1] * cnt[f2][0];
        }
    }
}

void solve(int n){
    n = getcent(n);
    dist[n] = val[n];
    ans[val[n]]++;
    cnt[dist[n]][0]++;
    fact.push_back(dist[n]);
    for(int e : graph[n]){
        if(vis[e]){
            continue;
        }
        dfs2(e, n);
        f();
        for(int k : sub){
            fact.push_back(k);
            cnt[k][0] += cnt[k][1];
            cnt[k][1] = 0;
        }
        sub.clear();
    }
    for(int f : fact){
        cnt[f][0] = 0;
    }
    fact.clear();
//    cout << n << " " << ans[1] << endl;
    vis[n] = 1;
    for(int e : graph[n]){
        if(!vis[e]){
            solve(e);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i =1; i<=N; i++){
        cin >> val[i];
    }
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    solve(1);
    for(int n = 1; n<=200000; n++){
        if(ans[n]){
            cout << n << " " << ans[n] << "\n";
        }
    }
}