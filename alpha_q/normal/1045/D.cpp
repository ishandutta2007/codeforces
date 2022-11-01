///usr/bin/g++ -O2 $0 -o ${0%.cpp} && echo "----------" && ./${0%.cpp}; exit;
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

const int N = 1e5 + 10; 
vector<int> adj[N]; 
double ans, q[N], sum[N]; 
int p[N], n, Q; 

void dfs(int u, int par = -1) {
    p[u] = par; 
    for(int v : adj[u]) if(v - par) 
        dfs(v, u), sum[u] += q[v]; 
    ans += q[u] - sum[u] * q[u]; 
}

int main() {
    scanf("%d", &n); 
    for(int i = 0; i < n; i++) {
        scanf("%lf", &q[i]); 
        q[i] = 1 - q[i]; 
    }
    for(int i = 1; i < n; i++) {
        int u, v; 
        scanf("%d %d", &u, &v); 
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    dfs(0);     
    scanf("%d", &Q); while(Q--) {
        int u; double qq; 
        scanf("%d %lf", &u, &qq); 
        qq = 1 - qq; 

        ans -= q[u];
        ans += q[u] * sum[u]; 
        if(p[u] + 1) 
            ans += q[u] * q[p[u]]; 
    
        if(p[u] + 1) {
            sum[p[u]] -= q[u]; 
            sum[p[u]] += qq; 
        }

        q[u] = qq; 

        ans += q[u]; 
        ans -= q[u] * sum[u]; 
        if(p[u] + 1) 
            ans -= q[u] * q[p[u]]; 

        printf("%.5f\n", ans); 
    }
}