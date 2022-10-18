#include <bits/stdc++.h>

using namespace std;

#define int long long
int a[100005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i){
        if (a[i] >= a[i - 1]) ans += (a[i] - a[i - 1]) * (n - a[i] + 1);
        else ans += (a[i - 1] - a[i]) * a[i];
    }
    cout << ans << '\n';
    return 0;
}