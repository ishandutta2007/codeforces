#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif 
    int n;
    scanf("%d", &n); 
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        dp[1][i] = b[i];
    }

    for (int len = 2; len <= n; len++) {
        ll d = 1;
        for (; d * 2 < len; d *= 2);
        for (int i = 0; i + len <= n; i++) {
            dp[len][i] = dp[len - d][i] ^ dp[len - d][i + d];
        }
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            dp[len][i] = max(dp[len][i], max(dp[len - 1][i], dp[len - 1][i + 1]));
        }
    }
    



    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d%d", &l, &r); l--;
        int len = r - l;
        printf("%d\n", dp[len][l]);
    }



}