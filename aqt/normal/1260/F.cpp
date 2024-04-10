#include <bits/stdc++.h>

using namespace std;

int N, M = 100000;
long long T = 1;
int lft[100005], rht[100005];
long long inv[100005];
vector<int> graph[100005];
int sz[100005], par[100005];
bool vis[100005];
int dist[100005];
long long ans = 0;
long long BIT[2][2][100005];
long long MOD = 1e9+7;
int qu[100005];
int vec[20000000];
int ptr;
int bigqu[100005];

inline long long mult(long long a, long long b){
    return a*b%MOD;
}

inline long long add(long long a, long long b){
    a += b;
    if(a >= MOD){
        a -= MOD;
    }
    return a;
}

inline long long qikpow(long long b, long long e){
    long long ret = 1;
    while(e){
        if(e&1){
            ret = mult(ret, b);
        }
        e >>= 1;
        b = mult(b, b);
    }
    return ret;
}

inline long long sub(long long a, long long b){
    a = add(a, -b);
    if(a < 0){
        a += MOD;
    }
    return a;
}

void dfs(int n){
    sz[n] = 1;
    for(int e : graph[n]){
        if(e != par[n] && !vis[e]){
            par[e] = n;
            dfs(e);
            sz[n] += sz[e];
        }
    }
}

inline long long upd(int p, long long v1, long long v2, int t){
    for(int i = p; i<=M; i+=i&-i){
        if(!t){
            vec[++ptr] = i;
        }
        BIT[t][0][i] = add(BIT[t][0][i], v1);
        if(BIT[t][0][i] < 0){
            BIT[t][0][i] += MOD;
        }
        BIT[t][1][i] = add(BIT[t][1][i], v2);
        if(BIT[t][1][i] < 0){
            BIT[t][1][i] += MOD;
        }
    }
}

inline long long rngupd(int l, int r, long long v, int t){
    upd(l, v, mult(l-1, v), t);
    upd(r+1, -v, -mult(r, v), t);
}

inline long long query(int p, int t){
    long long ret1 = 0, ret2 = 0;
    for(int i = p; i; i-=i&-i){
        ret1 += BIT[t][0][i];
        ret2 += BIT[t][1][i];
    }
    return sub(mult(ret1, p), ret2%MOD);
}

inline long long rngsum(int l, int r, int t){
    return sub(query(r, t), query(l-1, t));
}

inline void solve(int n){
    par[n] = 0;
    dfs(n);
    int s = sz[n];
    while(true){
        int hvy = 0;
        for(int e : graph[n]){
            if(e != par[n] && !vis[e]){
                hvy = sz[e] > sz[hvy] ? e : hvy;
            }
        }
        if(sz[hvy]<<1 <= s){
            break;
        }
        n = hvy;
    }
    vis[n] = 1;
    par[n] = 0;
    rngupd(lft[n], rht[n], mult(T, inv[n]), 0);
    for(int e : graph[n]){
        if(!vis[e]){
            dist[e] = 0;
            par[e] = n;
            int l = 1, r = 0;
            qu[++r] = e;
            while(l <= r){
                int k = qu[l++];
                for(int edge : graph[k]){
                    if(par[k] != edge && !vis[edge]){
                        qu[++r] = edge;
                        dist[edge] = dist[k] + 1;
                        par[edge] = k;
                    }
                }
            }
            for(int i = 1; i<=r; i++){
                int k = qu[i];
                ans = add(ans, mult(mult(rngsum(lft[k], rht[k], 0), inv[k]), dist[k] + 1));
                ans = add(ans, mult(inv[k], rngsum(lft[k], rht[k], 1)));
            }
            for(int i = 1; i<=r; i++){
                int k = qu[i];
                rngupd(lft[k], rht[k], mult(T, inv[k]), 0);
                rngupd(lft[k], rht[k], mult(dist[k]+1, mult(T, inv[k])), 1);
            }
        }
    }
    for(int i = 1; i<=ptr; i++){
        int k = vec[i];
        BIT[0][0][k] = BIT[0][1][k] = BIT[1][0][k] = BIT[1][1][k] = 0;
    }
    ptr = 0;
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
    for(int i = 1; i<=N; i++){
        cin >> lft[i] >> rht[i];
        inv[i] = qikpow(rht[i]-lft[i]+1, MOD-2);
        T = mult(T, rht[i]-lft[i]+1);
    }
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    solve(1);
    cout << ans;
}