#include<bits/stdc++.h>

using namespace std;

int n, ans = 0, d[10][10];

int inp(int u, int v) {
    scanf("%d", &d[u][v]);
    v > 0 ? inp(u, v - 1) : (u > 0 ? inp(u - 1, n - 1) : 0);
}

int rec(int k, int u, int v) {
    d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
    v > 0 ? rec(k, u, v - 1) : (u > 0 ? rec(k, u - 1, n - 1) : (k > 0 ? rec(k - 1, n - 1, n - 1) : 0));
}

int upd(int u, int v) {
    ans = max(d[u][v], ans);
    v > 0 ? upd(u, v - 1) : (u > 0 ? upd(u - 1, n - 1) : 0);
}

int main() {
    scanf("%d", &n);
    inp(n - 1, n - 1);
    rec(n - 1, n - 1, n - 1);
    upd(n - 1, n - 1);
    
    printf("%d\n", ans);
    
    return 0;
}