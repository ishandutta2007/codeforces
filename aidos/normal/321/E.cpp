#include <bits/stdc++.h>
using namespace std;
int dp[888][4040];
int pref[4040][4040];
int opt[888][4040];
int a[4040][4040];
int n, k;
int sum(int x1, int y1, int x2, int y2) {
    return pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1];
}
void solve(int d, int l, int r, int optl, int optr) {
    if(l > r) return;

    int mid = (l + r)/2;
    int cur = optl;
    dp[d][mid] = dp[d-1][optl] + sum(optl+1, optl+1, mid, mid);
    for(int i = optl+1; i <= optr && i < mid; i++) {
        int x = dp[d-1][i] + sum(i+1, i+1, mid, mid);
        if(x < dp[d][mid]) {
            dp[d][mid] = x;
            cur = i;
        }
    }
    solve(d, l, mid-1, optl, cur);
    solve(d, mid+1, r, cur, optr);
}
int readInt() {
    int c = getchar();
    while(!(c != ' ' && c != EOF && c != '\n')) c = getchar();
    int x = 0;
    while(c != ' ' && c != EOF && c != '\n') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
int main(){
    n = readInt();
    k = readInt();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            //cin >> a[i][j];
            a[i][j] = readInt();
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        dp[1][i] = sum(1, 1, i, i);
    }
    for(int i = 2; i <= k; i++) {
        solve(i, i, n, 1, n);
    }
    cout << dp[k][n]/2 <<"\n";
}