#include <bits/stdc++.h>

using namespace std;

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n / 2; ++i){
        for (int j = 1; j <= m; ++j){
            cout << i << " " << j << '\n';
            cout << n - i + 1 << " " << m - j + 1 << '\n';
        }
    }
    if (n % 2 == 1){
        for (int j = 1; j <= m / 2; ++j){
            cout << (n + 1) / 2 << " " << j << '\n';
            cout << (n + 1) / 2 << " " << m - j + 1 << '\n';
        }
        if (m % 2 == 1) cout << (n + 1) / 2 << " " << (m + 1) / 2 << '\n';
    }
    return 0;
}