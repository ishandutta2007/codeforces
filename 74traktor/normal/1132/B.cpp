#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[300005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    int m, x;
    cin >> m;
    for (int i = 1; i <= m; ++ i){
        cin >> x;
        cout << sum - a[n - x + 1] << '\n';
    }
}