#include <bits/stdc++.h>

using namespace std;

int a[200005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        if (a[i] > ans){
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}