#include <bits/stdc++.h>

using namespace std;

int a[100005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (a[i] >= 0) a[i] = (-1 * a[i] - 1);
    }
    if (n % 2 == 1){
        int mx = 0;
        for (int i = 1; i <= n; ++i){
            mx = min(mx, a[i]);
        }
        for (int i = 1; i <= n; ++i){
            if (a[i] == mx){
                a[i] = (-1 * a[i] - 1);
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    return 0;
}