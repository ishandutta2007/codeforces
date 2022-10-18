#include <bits/stdc++.h>

using namespace std;

bitset < 10005 > a[55];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, n, s, x;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        cin >> s;
        for (int j = 1; j <= s; ++j){
            cin >> x;
            a[i][x] = 1;
        }
    }
    for (int i = 1; i <= m; ++i){
        for (int j = i + 1; j <= m; ++j){
            if ((a[i]&a[j]).count() == 0){
                cout << "impossible" << '\n';
                return 0;
            }
        }
    }
    cout << "possible" << '\n';
    return 0;
}