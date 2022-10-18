#include <bits/stdc++.h>

using namespace std;
#define int long long

int a[100005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int i = 1, j = 1, ans = 0;
    while (j <= n){
        while (j <= n && a[j] - a[i] <= d) ++j;
        int x = j - i - 2;
        ans += max((long long)0, x * (x + 1) / 2);
        ++i;
    }
    while (i <= n) ans += max((long long)0, (n - i - 1) * (n - i) / 2), ++i;
    cout << ans << endl;
    return 0;
}