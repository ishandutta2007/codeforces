#include <bits/stdc++.h>

using namespace std;

#define int long long
char a[1005][1005];
int dp[1005][1005];
int nxt[1005][1005];
int tree[1005][4005];

void build(int j, int i, int l, int r){
    if (r - l == 1){
        tree[j][i] = dp[l][j];
    }
    else{
        int m = (r + l) / 2;
        build(j, 2 * i + 1, l, m);
        build(j, 2 * i + 2, m, r);
        tree[j][i] = min(tree[j][2 * i + 1], tree[j][2 * i + 2]);
    }
}

int get_ans(int j, int i, int l, int r, int lq, int rq){
    if (lq >= r || l >= rq) return 10000;
    if (lq <= l && r <= rq) return tree[j][i];
    int m = (r + l) / 2;
    return min(get_ans(j, 2 * i + 1, l, m, lq, rq), get_ans(j, 2 * i + 2, m, r, lq, rq));
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j];
    for (int i = 1; i <= n; ++i){
        a[i][m + 1] = '.';
        for (int j = m; j >= 1; --j){
            a[n + 1][j] = '.';
            if (a[i][j] == a[i][j + 1]) dp[i][j] = dp[i][j + 1] + 1;
            else dp[i][j] = 1;
        }
    }
    for (int j = 1; j <= m; ++j) build(j, 0, 1, n + 1);
    for (int j = 1; j <= m; ++j) nxt[n + 1][j] = n + 1;
    for (int i = n; i >= 1; --i){
        for (int j = 1; j <= m; ++j){
            if (a[i][j] == a[i + 1][j]) nxt[i][j] = nxt[i + 1][j];
            else nxt[i][j] = i + 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            int to1 = nxt[i][j];
            if (to1 == n + 1) continue;
            int len = to1 - i;
            int to2 = nxt[to1][j];
            if (to2 - to1 != len) continue;
            if (to2 + len - 1 >= n + 1) continue;
            if (nxt[to2][j] <= to2 + len - 1) continue;
            ans += get_ans(j, 0, 1, n + 1, i, to2 + len);
            //cout << i << " " << j << " " << ans << '\n';
        }
    }
    cout << ans << '\n';
    return 0;
}