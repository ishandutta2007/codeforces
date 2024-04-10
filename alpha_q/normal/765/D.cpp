#include <bits/stdc++.h> 

using namespace std;

const int N = 1e5 + 10;

int n, m, f[N], g[N], h[N], invh[N];

int main (int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", f + i);
        if (f[i] == i) {
            h[++m] = i;
            invh[i] = m;
        }
    }
    for (int i = 1; i <= m; ++i) {
        g[h[i]] = i; 
    }
    for (int i = 1; i <= n; ++i) {
        if (g[i] == 0) {
            if (invh[f[i]] == 0) {
                puts("-1");
                return 0;
            } else {
                g[i] = invh[f[i]];
            }
        }
    }
    printf("%d\n", m);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", g[i]);
    } puts("");
    for (int i = 1; i <= m; ++i) {
        printf("%d ", h[i]);
    } puts("");
    return 0;
}