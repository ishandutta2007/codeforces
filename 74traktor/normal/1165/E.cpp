#include <bits/stdc++.h>

using namespace std;

#define int long long
int a[200005];
int b[200005];
int mod = 998244353;

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        a[i] = a[i] * i * (n - i + 1);
    }
    for (int i = 1; i <= n; ++i){
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        a[i] %= mod;
        ans = (ans + b[n - i + 1] * a[i]) % mod;
    }
    cout << ans << '\n';
    return 0;
}