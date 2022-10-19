#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mat[300][300];
ll pre[300][300];
bool done[300][300];
ll memo[300][300];
ll query(int a, int b, int c, int d) {
    ll am = pre[b][d];
    am -= pre[a-1][d] + pre[b][c-1];
    am += pre[a-1][c-1];
    return am;
}
int n;
int par[300];
ll dp(int a, int b, int p = -1) {
    if (a > b) return 0;
    if (done[a][b] && p == -1) return memo[a][b];
    done[a][b] = true;
    ll val = 0;
    if (a > 1) val += query(1, a-1, a, b);
    if (b != n) val += query(a, b, b+1, n);
    if (a == b) {
        if (p != -1) par[a] = p;
        return memo[a][b] = val;
    }
    int best = 0;
    ll ans = 1e18;
    for (int i = a; i <= b; i++) {
        ll am = val + dp(a, i-1) + dp(i+1, b);
        if (am < ans) {
            ans = am;
            best = i;
        }
    }
    if (p != -1) {
        par[best] = p;
        dp(a, best-1, best);
        dp(best+1, b, best);
    }
    return memo[a][b] = ans;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &mat[i][j]);
            pre[i][j] = mat[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }
    dp(1, n, 0);
    //printf("%lld\n", dp(1, n, 0));
    for (int i = 1; i <= n; i++) printf("%d ", par[i]);
    printf("\n");
}