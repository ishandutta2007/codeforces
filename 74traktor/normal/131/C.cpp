#include <bits/stdc++.h>

using namespace std;

#define int long long

int C[32][32];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, t, ans = 0;
    cin >> n >> m >> t;
    for (int j = 0; j <= 30; ++j) C[0][j] = 1;
    for (int n1 = 1; n1 <= 30; ++n1){
        for (int k = 1; k <= 30; ++k) C[n1][k] = C[n1][k - 1] + C[n1 - 1][k - 1];
    }
    /*for (int i = 1; i <= 5; ++i){
        for (int j = 1; j <= 5; ++j) cout << C[i][j] << " ";
        cout << endl;
    }*/
    for (int i = 4; i <= n; ++i){
        if (t - i < 1 || t - i > m) continue;
        ans += C[i][n] * C[t - i][m];
    }
    cout << ans << endl;
    return 0;
}