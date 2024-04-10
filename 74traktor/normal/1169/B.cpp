#include <bits/stdc++.h>

using namespace std;

int a[300005][2];
int b[300005][2];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 0; i < 2; ++i){
        int uk = 1;
        for (int j = 1; j <= m; ++j) if (a[j][0] != a[1][i] && a[j][1] != a[1][i]) b[uk][0] = a[j][0], b[uk][1] = a[j][1], uk++;
        if (uk == 1){
            if (a[1][i] > 1){
                cout << "YES" << '\n';
                return 0;
            }
            if (a[1][i] < n){
                cout << "YES" << '\n';
                return 0;
            }
            continue;
        }
        for (int p = 0; p < 2; ++p){
            bool f = true;
            for (int j = 1; j < uk; ++j){
                if (b[j][0] != b[1][p] && b[j][1] != b[1][p]){
                    f = false;
                    break;
                }
            }
            if (f){
                cout << "YES" << '\n';
                return 0;
            }
        }
    }
    cout << "NO" << '\n';
    return 0;
}