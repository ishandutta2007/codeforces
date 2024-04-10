#include <bits/stdc++.h>

using namespace std;

int dp[505][1025];
int a[505][505];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j];
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i){
        for (int z = 0; z <= 1023; ++z){
            if (dp[i - 1][z] == 0) continue;
            for (int j = 1; j <= m; ++j){
                dp[i][(z^a[i][j])] = 1;
            }
        }
    }
    int i = n, cc = 0;
    vector < int > out;
    for (int xx = 1; xx <= 1023; ++xx){
        if (dp[n][xx] == 1){
            cc = xx;
        }
    }
    if (cc == 0) cout << "NIE" << '\n';
    else{
        cout << "TAK" << '\n';
        while (i >= 1){
            for (int j = 1; j <= m; ++j){
                if (dp[i - 1][cc^a[i][j]] == 1){
                    out.push_back(j);
                    cc = (cc^a[i][j]);
                    i--;
                    break;
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) cout << out[i] << " ";
    }
    return 0;
}