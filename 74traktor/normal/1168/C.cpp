#include <bits/stdc++.h>

using namespace std;

int const maxn = 20;
int a[300005][maxn];
int dp[300005][maxn];
int last[maxn];
int inf = 1e9;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        for (int j = 0; j < maxn; ++j){
            y = (x&(1<<j));
            if (y > 0) a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    for (int i = 0; i < maxn; ++i) last[i] = n + 1;
    for (int i = 0; i <= n + 1; ++i) for (int j = 0; j < maxn; ++j) dp[i][j] = inf;
    for (int i = n; i >= 1; --i){
        for (int j = 0; j < maxn; ++j){
            if (a[i][j] == 0) continue;
            for (int k = 0; k < maxn; ++k){
                if (k == j) dp[i][k] = i;
                dp[i][k] = min(dp[i][k], dp[last[j]][k]);
            }
            last[j] = i;
        }
    }
    for (int i = 1; i <= m; ++i){
        cin >> x >> y;
        bool f = false;
        for (int j = 0; j < maxn; ++j){
            if (a[y][j] == 1 && dp[x][j] <= y) f = true;
        }
        if (f) cout << "Shi" << '\n';
        else cout << "Fou" << '\n';
    }
    return 0;
}