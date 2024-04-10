#include <bits/stdc++.h>
 
using namespace std;


const int maxn = 301;
int dp[2 * maxn][maxn][maxn];

int n;
int step(int h, int x, int t) {
    int mid = n - 1;
    if(h < mid) {
        return t == 0 ? x : x + 1;
    } else {
        return t == 0 ? x - 1 : x;
    }
}

int bound(int k) {
    return min(k, 2 * n - 2 - k);
}

int a[maxn][maxn];

int score(int h, int x) {
    int mid = n - 1;
    if(h <= mid) {
        return a[h - x][x];
    } else {
        return a[mid - x][h - mid + x];
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    memset(dp, 0xAF, sizeof(dp));
    dp[0][0][0] = a[0][0];
    int mid = n - 1;
    for(int k = 0; k < 2 * n - 2; k++) {
        for(int i = 0; i <= bound(k); i++) {
            for(int j = i; j <= bound(k); j++) {
                int dx[] = {1, 0};
                int dy[] = {0, 1};
                for(int z1 = 0; z1 <= 1; z1++) {
                    for(int z2 = 0; z2 <= 1; z2++) {
                        int d1 = step(k, i, z1);
                        int d2 = step(k, j, z2);
                        if(!(d1 > d2 || d2 < 0 || d1 > bound(k + 1))) {
                            dp[k + 1][d1][d2] = max(dp[k + 1][d1][d2], dp[k][i][j] + score(k + 1, d1) + (d1 != d2) * score(k + 1, d2));
                        }
                    }
                }
            }
        }
    }
    cout << dp[2 * n - 2][0][0] << endl;
    return 0;
}