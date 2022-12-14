#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 77;
int n , sz[N] , d[N] , f[N];
long long ans;
vector < int > adj[N];
bitset < N > b;
void dfs(int v, int prev = -1) {
    sz[v] = 1;
    for(int u : adj[v]) {
        if(u == prev) continue ;
        d[u] = d[v] + 1;
        dfs(u , v);
        sz[v] += sz[u];
    }
}
int find_c(int v , int prev = -1) {
    for(int u : adj[v]) {
        if(u == prev) continue ;
        if(sz[u] * 2 >= n) return find_c(u , v);
    }
    return v;
}
void test() {
    scanf("%d" , & n);
    for(int p , i = 2;i <= n;++ i) {
        scanf("%d" , & p);
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    dfs(1);
    int c = find_c(1);
    d[c] = 1;
    dfs(c);
    for(int i = 1;i <= n;++ i)
        ans += d[i];
    b[0] = 1;
    for(int v : adj[c]) ++ f[sz[v]];
    for(int i = 1;i <= n;++ i) {
        while(f[i] > 2) {
            f[i] -= 2;
            ++ f[i << 1];
        }
        while(f[i] --) {
            b |= b << i;
        }
    }
    long long mx = 0;
    for(int i = 1;i < n;++ i) {
        if(b[i])
            mx = max(mx , i * 1ll * (n - i - 1));
    }
    ans += mx;
    printf("%lld\n" , ans);

}

int main() {
    int tst = 1;
    //cin >> tst;
    while(tst --)
        test();
    return 0;
}