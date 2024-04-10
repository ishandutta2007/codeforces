#include <bits/stdc++.h>

using namespace std;

int a[105];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (x > y){
        cout << n << '\n';
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        if (a[i] <= x) ans++;
    }
    cout << (ans + 1) / 2 << '\n';
    return 0;
}