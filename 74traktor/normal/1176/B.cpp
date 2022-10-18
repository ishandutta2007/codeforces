#include <bits/stdc++.h>

using namespace std;

int a[3];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> n;
        for (int j = 0; j <= 2; ++j) a[j] = 0;
        for (int j = 1; j <= n; ++j){
            cin >> x;
            a[x % 3]++;
        }
        int imin = min(a[1], a[2]);
        cout << a[0] + imin + (a[1] - imin) / 3 + (a[2] - imin) / 3 << '\n';
    }
    return 0;
}