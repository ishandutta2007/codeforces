#include <bits/stdc++.h>

using namespace std;

#define f first 
#define s second
#define pb push_back

typedef long long ll;      
typedef pair<int, int> pii;
typedef pair<long, long> pll;

const int N = 200100;
const ll INF = 1e18;

vector< int > g[N];
int n, k, c[N];
ll dp[N][2], ans;
bool good[N], a[N][2];
void dfs1(int v, int p){
    bool ok = 0;
    ll s = 0;
    for(auto to : g[v]){
        if(to == p)
            continue;
        ok = 1;
        dfs1(to, v);
        s += dp[to][0];
    }
    if(!ok){
        dp[v][0] = c[v];
        dp[v][1] = 0;
        return;
    }
    dp[v][0] = s;
    dp[v][1] = INF;
    for(auto to : g[v]){
        if(to == p)
            continue;
        dp[v][1] = min(dp[v][1], s - dp[to][0] + dp[to][1]);
    }
    dp[v][0] = min(dp[v][0], dp[v][1] + c[v]); 
}
void dfs2(int v, int p){
    bool ok = 0;
    ll s = 0;
    for(auto to : g[v]){
        if(to == p)
            continue;
        ok = 1;
        s += dp[to][0];
    }
    if(!ok){
        good[v] |= a[v][0];
        return;
    }
    if(s == dp[v][0]){
        for(auto to : g[v]){
            if(to == p)
                continue;
            a[to][0] |= a[v][0];
        }
    }
    
    if(dp[v][0] == dp[v][1] + c[v]){
        a[v][1] |= a[v][0];
        good[v] |= a[v][0];
    }

    int cnt = 0, last = 0;

    for(auto to : g[v]){
        if(to == p)
            continue;
        if(dp[v][1] == s - dp[to][0] + dp[to][1]){
            a[to][1] |= a[v][1];
            cnt++;
            last = to;   
        }
    }
    if(cnt == 1){
        for(auto to : g[v]){
            if(to == p)
                continue;
            if(to != last)
                a[to][0] |= a[v][1];
        }
    }else{
        for(auto to : g[v]){
            if(to == p)
                continue;
            a[to][0] |= a[v][1];
        }
    }
    for(auto to : g[v]){
        if(to == p)
            continue;
        dfs2(to, v);
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for(int i = 1; i < n; i++){
        int v, u;
        scanf("%d%d", &v, &u);
        g[v].pb(u);
        g[u].pb(v);
    }
    dfs1(1, 1);
    ans = dp[1][0];
    a[1][0] = 1;
    dfs2(1, 1);
    k = 0;
    for(int i = 1; i <= n; i++)
        k += good[i];
    printf("%lld %d\n", ans, k);
    for(int i = 1; i <= n; i++)
        if(good[i])
            printf("%d ", i);
    return 0;
}